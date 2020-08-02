import java.util.ArrayList;

public class HS {
    public static boolean leaderFlag = false;   // set the leaderFlag to false initially
    public static int numOfMess = 0;    //set the num of mess send in the process
    public static int round = 0;
    public static Integer leaderListID = null;
    public static int phase = 0;

    public HS() {}

    public void run(ArrayList<Node> nodeList){
        int round = 0;
        for (int i = 0; i < nodeList.size(); i++) {
            nodeList.get(i).HSSendMessBegin();
        }
        while (leaderFlag == false){
            for (int i = 0; i < nodeList.size(); i++) {
                nodeList.get(i).HSNodeBehaviour();
                if (leaderFlag == true){
                    break;
                }
            }
            if (leaderFlag == false) {
                for (int i = 0; i < nodeList.size(); i++) {
                    nodeList.get(i).HSMessSend();
                }
            }

            round++;
        }


    System.out.print("\t HS      Num of Message: "+"\t"+(numOfMess+nodeList.size())+"\t"+ "    Num of Round:" +"\t"+ (round+(nodeList.size())/2));
        /*clear the memory*/
        leaderFlag = false;   // set the leaderFlag to false initially
        numOfMess = 0;    //set the num of mess send in the process
        round = 0;
        leaderListID = null;
    }





}
