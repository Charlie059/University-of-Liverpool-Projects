import keras
import shutil
import tensorflow as tf
import sys
import os
import argparse
import datetime
import time
import cv2
import numpy as np
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *

def sort():
    Cans = 0
    Paper = 0
    Plastic_Bottle = 0
    # lists all files to be tested in test_input folder
    list_images = os.listdir(image_path)

    with tf.compat.v1.Session() as sess:
        for igs in list_images:
            # load the image data

            image_data = tf.compat.v1.gfile.FastGFile(image_path + igs, 'rb').read()

            # Feed the image_data as input to the graph and get first prediction
            softmax_tensor = sess.graph.get_tensor_by_name('final_result:0')

            predictions = sess.run(softmax_tensor, {'DecodeJpeg/contents:0': image_data})

            # Sort to show labels of first prediction in order of confidence
            top_k = predictions[0].argsort()[-len(predictions[0]):][::-1]
            # print('\n' + igs + ' :')
            human_string = label_lines[0]
            score = predictions[0][0]

            # print('%s (score = %.5f)' % (human_string, score))

            if human_string == "cans" and score >= 0.65:
                Cans += 1
            elif human_string == "paper" and score >= 0.97:
                Paper += 1
            elif human_string == "plastic bottle" and score >= 0.65:
                Plastic_Bottle += 1
    print(Cans)
    print(Paper)
    print(Plastic_Bottle)

    print("Eneter number")
    a = input("input")
    aa = str(a)
    if aa == '1':
        show(1)
    elif aa =='2':
        show(2)
    elif aa =='3':
        show(3)
    else:
        show(4)

    # if Cans > Paper and Cans > Plastic_Bottle:
    #     print("can")
    #     show(1)
    # elif Paper > Cans and Paper > Plastic_Bottle:
    #     print("paper")
    #     show(2)
    # elif Plastic_Bottle > Cans and Plastic_Bottle > Paper:
    #     print("plastic_bottle")
    #     show(3)
    # else:
    #     print("qwer")
    #     show(4)


def detect():
    # construct the argument parser and parse the arguments
    ap = argparse.ArgumentParser()
    ap.add_argument("-v", "--video", help="path to the video file")
    ap.add_argument("-a", "--min-area", type=int, default=1000, help="minimum area size")
    args = vars(ap.parse_args())

    # if the video argument is None, then we are reading from webcam
    if args.get("video", None) is None:
        camera = cv2.VideoCapture(0)
        time.sleep(0.25)

    # otherwise, we are reading from a video file
    else:
        camera = cv2.VideoCapture(args["video"])

    # initialize the first frame in the video stream
    firstFrame = None

    # Define the codec
    fourcc = cv2.VideoWriter_fourcc('X', 'V', 'I', 'D')
    framecount = 0
    frame = np.zeros((640, 480))
    out = cv2.VideoWriter(
        './videos/' + 'calm_down_video_' + datetime.datetime.now().strftime("%A_%d_%B_%Y_%I_%M_%S%p") + '.avi', fourcc,
        5.0, np.shape(frame))

    # to begin with, the light is not stable, calm it down
    tc = 40
    while tc:
        ret, frame = camera.read()
        out.write(frame)
        # cv2.imshow("vw",frame)
        cv2.waitKey(10)
        tc -= 1
    totalc = 2000
    tc = totalc
    out.release()

    # loop over the frames of the video
    while True:

        # grab the current frame and initialize the occupied/unoccupied
        # text
        (grabbed, frame) = camera.read()
        text = "Unoccupied"

        # if the frame could not be grabbed, then we have reached the end
        # of the video
        if not grabbed:
            time.sleep(0.25)
            continue

        # resize the frame, convert it to grayscale, and blur it
        # frame = imutils.resize(frame, width=500)

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        gray = cv2.GaussianBlur(gray, (21, 21), 0)

        # update firstFrame for every while
        if tc % totalc == 0:
            firstFrame = gray
            tc = (tc + 1) % totalc
            continue
        else:
            tc = (tc + 1) % totalc

        # print tc

        # compute the absolute difference between the current frame and
        # first frame
        frameDelta = cv2.absdiff(firstFrame, gray)
        thresh = cv2.threshold(frameDelta, 25, 255, cv2.THRESH_BINARY)[1]

        # dilate the thresholded image to fill in holes, then find contours
        # on thresholded image
        thresh = cv2.dilate(thresh, None, iterations=2)

        # _, cnts, _ = cv2.findContours(thresh.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_NONE)

        contours, hierarchy = cv2.findContours(thresh.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[-2:]
        # _, contours, _ = cv2.findContours(skin_ycrcb, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        # loop over the contours
        for c in contours:
            print(framecount)
            # if the contour is too small, ignore it
            if cv2.contourArea(c) < args["min_area"]:
                continue
            # compute the bounding box for the contour, draw it on the frame,
            # and update the text
            (x, y, w, h) = cv2.boundingRect(c)
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
            text = "Occupied"

        # draw the text and timestamp on the frame
        cv2.putText(frame, "Monitoring Area Status: {}".format(text), (10, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5,
                    (0, 0, 255), 2)
        cv2.putText(frame, datetime.datetime.now().strftime("%A %d %B %Y %I:%M:%S%p"), (10, frame.shape[0] - 10),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.35, (0, 0, 255), 1)

        # show the frame and record if the user presses a key
        cv2.imshow("Security Feed", frame)
        cv2.imshow("Thresh", thresh)
        cv2.imshow("Frame Delta", frameDelta)

        # save the detection result
        if text == "Occupied":
            if framecount == 0:
                # # create VideoWriter object
                # out = cv2.VideoWriter('./videos/' + datetime.datetime.now().strftime("%A_%d_%B_%Y_%I_%M_%S%p") + '.avi',
                #                       fourcc, 10.0, np.shape(gray)[::-1])
                # cv2.imwrite('./images/' + datetime.datetime.now().strftime("%A_%d_%B_%Y_%I_%M_%S%p") + '.jpg', frame)
                # # write the flipped frame
                # out.write(frame)
                framecount += 1
            elif framecount > 200:
                break
            else:
                # write the flipped frame
                out.write(frame)
                if framecount % 10 == 0:
                    cv2.imwrite('./images/' + datetime.datetime.now().strftime("%A_%d_%B_%Y_%I_%M_%S%p") + '.jpg',
                                frame)
                framecount += 1
        elif framecount < 200 and framecount > 1:
            # write the flipped frame
            out.write(frame)
            # if framecount%10 == 0:
            cv2.imwrite('./images/'+datetime.datetime.now().strftime("%A_%d_%B_%Y_%I_%M_%S%p")+'.jpg',frame)
            framecount += 1

        key = cv2.waitKey(1) & 0xFF

        # if the `ESC` key is pressed, break from the lop
        if key == 27:
            break

    # cleanup the camera and close any open windows
    camera.release()
    cv2.destroyAllWindows()


def clear():
    shutil.rmtree("/Users/xg/Desktop/DL-wastesort-master-2/images")
    os.mkdir("/Users/xg/Desktop/DL-wastesort-master-2/images")


def loop():
    while True:
        detect()
        sort()
        clear()

def show(num):
    app = QApplication(sys.argv)
    example1 = CellImageSize(num)
    example1.show()
    app.exec()

class CellImageSize(QWidget):

    def __init__(self,num):
        super(CellImageSize,self).__init__()
        self.initUI(num)

    def initUI(self,num):
        self.setWindowTitle("trash sort")
        self.resize(1700, 500);
        layout = QVBoxLayout()
        hlayout =QHBoxLayout()

        tablewidget = QTableWidget()
        tablewidget.setIconSize(QSize(400,200))
        tablewidget.setColumnCount(4)
        tablewidget.setRowCount(1)

        #tablewidget.setSpan(1,0,1,4)
        tablewidget.setHorizontalHeaderLabels(['paper','metal','bottle','glass'])

        self.button1 = QPushButton('continue')
        self.button1.setText('continue')
        self.button1.setFixedHeight(100)
        self.button1.setFixedWidth(300)

        self.button1.setCheckable(True)
        self.button1.toggle()
        self.button1.clicked.connect(lambda: self.close())

        hSpacer=QSpacerItem(1,1)






        # 让列的宽度和图片的宽度相同
        for i in range(4):
            tablewidget.setColumnWidth(i,400)

        # 让行的高度和图片的高度相同
        for i in range(4):
            tablewidget.setRowHeight(i,400)

        for k in range(4):
            i = 0   # 行
            j = k   # 列
            z = k+1
            item = QTableWidgetItem()
            item.setIcon(QIcon('./images/%d.jfif'%z ))
            tablewidget.setItem(i,j,item)

        ct1 = QCheckBox('', self)
        ct2 = QCheckBox('', self)
        ct3 = QCheckBox('', self)
        ct4 = QCheckBox('', self)

        if(num==0):
            print('0')
            ct1.setChecked(0)
            ct2.setChecked(0)
            ct3.setChecked(0)
            ct4.setChecked(0)
        if (num == 1):
            print('1')
            ct1.setChecked(1)
            ct2.setChecked(0)
            ct3.setChecked(0)
            ct4.setChecked(0)
        if (num == 2):
            print('2')
            ct1.setChecked(0)
            ct2.setChecked(1)
            ct3.setChecked(0)
            ct4.setChecked(0)
        if (num == 3):
            print('3')
            ct1.setChecked(0)
            ct2.setChecked(0)
            ct3.setChecked(1)
            ct4.setChecked(0)
        if (num == 4):
            print('4')
            ct1.setChecked(0)
            ct2.setChecked(0)
            ct3.setChecked(0)
            ct4.setChecked(1)

        tablewidget.setCellWidget(0, 0, ct1)
        tablewidget.setCellWidget(0, 1, ct2)
        tablewidget.setCellWidget(0, 2, ct3)
        tablewidget.setCellWidget(0, 3, ct4)

        layout.addWidget(tablewidget)
        hlayout.addSpacerItem(hSpacer)
        hlayout.addWidget(self.button1)
        layout.addLayout(hlayout)
        self.setLayout(layout)



if __name__ == '__main__':
    # Disable tensorflow compilation warnings

    os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

    image_path = '/Users/xg/Desktop/DL-wastesort-master-2/images/'

    # Loads label file, strips off carriage return
    label_lines = [line.rstrip() for line
                   in tf.compat.v1.io.gfile.GFile("tf_files/retrained_labels.txt")]

    # Unpersists graph from file
    with tf.compat.v1.gfile.FastGFile("tf_files/retrained_graph.pb", 'rb') as f:
        graph_def = tf.compat.v1.GraphDef()
        graph_def.ParseFromString(f.read())
        _ = tf.import_graph_def(graph_def, name='')


    try:
        show(0)
        print("a")
        loop()
    except KeyboardInterrupt:
        sys.exit()
