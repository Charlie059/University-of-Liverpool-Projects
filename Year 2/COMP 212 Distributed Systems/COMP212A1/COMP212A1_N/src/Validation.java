import java.util.ArrayList;

public class Validation {
    public Validation(){};

    //get the max id from the nodeArrList
    public boolean run(ArrayList<Node> nodeArrayList){
        int nodeIdList[] = new int[nodeArrayList.size()];
        int maxIDFromAlgorithm = 0;
        int leaderTimesCounter = 0;
        for (int i = 0; i <nodeArrayList.size() ; i++) {
            nodeIdList[i] = nodeArrayList.get(i).getMyID(); //fill the nodeIDlist and use bubble sort to check the max
            if (nodeArrayList.get(i).getStatus()== Node.statusSet.leader){
                maxIDFromAlgorithm = nodeArrayList.get(i).getMyID();
                leaderTimesCounter++;
            }
        }
        int maxID = bubbleSort(nodeIdList);
        //check same id
        if (maxIDFromAlgorithm == maxID && leaderTimesCounter == 1){
            return true;
        }
        else
        return false;
    }

    public int bubbleSort(int[] nodeIdList) {     //the bubble sort and return the max id

        for (int i = 0; i < nodeIdList.length - 1; i++) {
            for (int j = 0; j < nodeIdList.length - i - 1; j++) {

                if (nodeIdList[j] > nodeIdList[j + 1]) {
                    int tmp = nodeIdList[j];
                    nodeIdList[j] = nodeIdList[j + 1];
                    nodeIdList[j + 1] = tmp;
                }
            }
        }
        int maxId = nodeIdList[nodeIdList.length - 1];
        return maxId;

    }

}
