# import imgaug as ia
# from imgaug import augmenters as iaa
# import numpy as np
# import imageio
# import cv2
# from skimage.io import imread_collection
# ia.seed(1)
#
# # path= '/Volumes/MDisk/dataset/test_data/*.jpg'
# # img=imread_collection(path)
# img = imageio.imread("/Volumes/MDisk/dataset/test_data/test.jpg") #read you image
#
# print(img)
# images = np.array(
#     [img for _ in range(32)], dtype=np.uint8)  # 32 means creat 32 enhanced images using following methods.
#
# seq = iaa.Sequential(
#     [
#         iaa.Fliplr(0.5),
#         iaa.Crop(percent=(0, 0.1)),
#         iaa.Sometimes(0.5, iaa.GaussianBlur(sigma=(0, 0.5))),
#         iaa.ContrastNormalization((0.75, 1.5)),
#         iaa.AdditiveGaussianNoise(
#             loc=0, scale=(0.0, 0.05 * 255), per_channel=0.5),
#         iaa.Multiply((0.8, 1.2), per_channel=0.2),
#         iaa.Affine(
#             scale={
#                 "x": (0.8, 1.2),
#                 "y": (0.8, 1.2)
#             },
#             translate_percent={
#                 "x": (-0.2, 0.2),
#                 "y": (-0.2, 0.2)
#             },
#             rotate=(-25, 25),
#             shear=(-8, 8))
#     ],
#     random_order=True)  # apply augmenters in random order
#
# images_aug = seq.augment_images(images)
#
# for i in range(32):
#     imageio.imwrite(str(i)+'new.jpg', images_aug[i])  #write all changed images
#
import matplotlib
from imgaug import augmenters as iaa
import numpy as np
import imageio
import cv2
from pasta.augment import inline

from skimage.io import imread_collection
import imgaug as ia
from imgaug import augmenters as iaa
import numpy as np
import imageio
from glob import glob
import matplotlib.pyplot as plt
import cv2
import scipy.misc

def get_img(img_paths, img_size):
    X = np.zeros((len(img_paths), img_size, img_size, 3), dtype=np.uint8)
    i = 0
    for img_path in img_paths:
        img = cv2.imread(img_path)
        img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        img = cv2.resize(img, (img_size, img_size), interpolation=cv2.INTER_AREA)
        X[i, :, :, :] = img
        i += 1
    return X


def get_X_batch(X_path, batch_size, img_size):
    while 1:
        for i in range(0, len(X_path), batch_size):
            X = get_img(X_path[i:i + batch_size], img_size)
            yield X


if __name__ == '__main__':
    img_paths = glob('/Volumes/MDisk/dataset/test_data/*.jpg')  # 得到所有图片的路径列表
    print(img_paths)
    images = get_X_batch(img_paths, 16, 300)  # 得到一个batch的图片，形式为generator
    images = next(images)  # next(generator)，得到一个batch的ndarray

    ia.seed(1)

    seq = iaa.Sequential([

        iaa.Fliplr(0.5),  # 0.5的概率水平翻转
        iaa.Crop(percent=(0, 0.1)),  # random crops
        # sigma在0~0.5间随机高斯模糊，且每张图纸生效的概率是0.5
        iaa.Sometimes(0.5,
                      iaa.GaussianBlur(sigma=(0, 0.5))
                      ),
        # 增大或减小每张图像的对比度
        iaa.ContrastNormalization((0.75, 1.5)),
        # 高斯噪点
        iaa.AdditiveGaussianNoise(loc=0, scale=(0.0, 0.05 * 255), per_channel=0.5),
        # 给每个像素乘上0.8-1.2之间的数来使图片变暗或变亮
        # 20%的图片在每个channel上乘以不同的因子
        iaa.Multiply((0.8, 1.2), per_channel=0.2),
        # 对每张图片进行仿射变换，包括缩放、平移、旋转、修剪等
        iaa.Affine(
            scale={"x": (0.8, 1.2), "y": (0.8, 1.2)},
            translate_percent={"x": (-0.2, 0.2), "y": (-0.2, 0.2)},
            rotate=(-90, 90),
            shear=(-8, 8)
        )
    ], random_order=True)  # 随机应用以上的图片增强方法

    images_aug = seq.augment_images(images)  # 得到增强后的图片ndarray
    print((len(images_aug)))
    for i in range(len(images_aug)):
        imageio.imwrite(str(i)+'new.jpg', images_aug[i])  #write all changed images
