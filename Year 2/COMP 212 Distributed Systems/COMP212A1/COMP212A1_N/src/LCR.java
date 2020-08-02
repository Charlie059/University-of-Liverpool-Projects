import java.util.ArrayList;

public class LCR {
    public static boolean leaderFlag = false;   // set the leaderFlag to false initially
    public static int numOfMess = 0;    //set the num of mess send in the process
    public static int round = 0;
    public static Integer leaderListID = null;

    public LCR() {

    }

    public void process(ArrayList<Node> nodeList){
        //  round 1 send mess
        for (int i = 0; i < nodeList.size(); i++) {
            nodeList.get(i).processLCRMess(1);
        }

        //  >= round 2 send mess

        while (Main.leaderFlag == false) {

            for (Node node : nodeList) {
                node.receiveLCRMess();
            }   //let all nodes receive the messages and clear the node.outMess

            for (int i = 0; i < nodeList.size(); i++) {
                nodeList.get(i).processLCRMess(2);
                if (nodeList.get(i).getLeaderID() != null){
                    leaderListID = i;
                }


            }
            round++;
        }


        /*leader announcement*/

        //There are three types of situation: 1. leaderListID is 0; 2. leaderListID is nodeList.size()-1 (the last); 3. leaderListID between the 0 and the last

        if (leaderListID == 0){     //leaderListID is 0
            for (Node node : nodeList) {
                node.getOutNode().leaderAnnounce();
                round++;
            }
        }
        else if (leaderListID == nodeList.size() - 1){      //leaderListID is nodeList.size()-1 (the last)
            for (Node node : nodeList) {
                node.leaderAnnounce();
                round++;
            }
        }
        else {  //leaderListID between the 0 and the last

            //let the program run the leaderListID to the end of the array
            for (int i = leaderListID; i < nodeList.size(); i++) {
                nodeList.get(i).getOutNode().leaderAnnounce();
                round++;
            }

            //let the rest node to know until leader
            for (int i = 1; i < leaderListID; i++) {
                nodeList.get(i).leaderAnnounce();
                round++;

            }
            round++;    //Compensate for the less calculated round in the head and tail splicing

        }


        System.out.print("LCR     Num of Message: "+"\t"+numOfMess+"\t"+ "    Num of Round:" +"\t"+ round);

        /*clear the memory*/
        leaderFlag = false;   // set the leaderFlag to false initially
        numOfMess = 0;    //set the num of mess send in the process
        round = 0;
        leaderListID = null;

    }
}
