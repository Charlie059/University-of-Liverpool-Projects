import java.util.ArrayList;

public class Main {
    public static boolean leaderFlag = false;   // set the leaderFlag to false initially

    public static void runningTestandOutput(int increaseStep,int repeatStepTimes, int repeatOneNodeTimes,int randomType, int numOfNode, int numOfAlpha){     //define each increase step of num of node, define the node increase until, define repeat One Node Times,define the type of random id, num of node, num of alpha
        for (int n = 0; n <= repeatStepTimes; n++) {
            for (int j = 0; j < repeatOneNodeTimes; j++) {

                ArrayList<Node> nodeList = new ArrayList<Node>();
                NodeGenerator NG = new NodeGenerator();
                nodeList = NG.randomNodeGenerator(numOfNode + increaseStep * n,numOfAlpha,randomType);    //set node list  1. ascendingRandomNumbers 2.//invertedRandomNumbers 3.randomNumbers
                Validation vd = new Validation();
                /*initially bind each node in the node list */

                //  bind each node together
                for (int i = 0; i < nodeList.size() - 1; i++) {    //bind the outNode
                    nodeList.get(i).setOutNode(nodeList.get(i + 1));
                }
                for (int i = nodeList.size() - 1; i > 0; i--) {    //bind the inNode
                    nodeList.get(i).setInNode(nodeList.get(i - 1));
                }
                nodeList.get(0).setInNode(nodeList.get(nodeList.size() - 1));  //bind the first(0) node to the last node
                nodeList.get(nodeList.size() - 1).setOutNode(nodeList.get(0)); //bind the last node to the first node


                /************/
                System.out.print("\tNumber of Nodes: \t"+ nodeList.size()+"\t");

                LCR lcr = new LCR();
                lcr.process(nodeList);
                boolean validationresult = vd.run(nodeList);
             //   System.out.println(validationresult);     //valid the maxid


                for (int i = 0; i < nodeList.size(); i++) {
                    nodeList.get(i).rmNode();   //Clear the node info to let HS use the same nodeList again
                }

                HS hs = new HS();
                hs.run(nodeList);
             //   System.out.println(validationresult);     //valid the maxid
                /*clear the memory*/
                nodeList = null;
                NG = null;
                leaderFlag = false;
                System.out.println();
            }

        }







    }

    public static void main(String[] args) {
        TerminalOut to = new TerminalOut();     //write file -> testResult
        runningTestandOutput(10,10,1,1,1000,3);

    }


}

