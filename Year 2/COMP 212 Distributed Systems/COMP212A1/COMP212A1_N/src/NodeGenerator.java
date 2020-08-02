import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Random;
import java.util.Set;
import java.util.Collections;

public class NodeGenerator {
    private int n;
    private int alpha;
    private int totalToken;
    private ArrayList<Node> nodeList = new ArrayList<Node>();
    public NodeGenerator(){

    }
    public NodeGenerator(int setN, int setAlpha){
        n = setN;
        alpha = setAlpha;
        totalToken = n * alpha;
    }
    public ArrayList<Node> randomNodeGenerator(int setN, int setAlpha,int randomType){
        if (randomType == 1){   //ascendingRandomNumbers
            int i, j;

            Random random = new Random();
            HashSet hashset = new HashSet();
            for(;;){
                int tmp = random.nextInt(setN * setAlpha)+1;
                hashset.add(tmp);
                if(hashset.size() == setN) break;
            }

            Integer[] asRandomNumbers = (Integer[]) hashset.toArray(new Integer[hashset.size()]);


            for(i=0; i<asRandomNumbers.length; i++){
                for(j=1; j<asRandomNumbers.length-i; j++){
                    if(asRandomNumbers[j-1] > asRandomNumbers[j]){
                        int temp;
                        temp = asRandomNumbers[j-1];
                        asRandomNumbers[j-1] = asRandomNumbers[j];
                        asRandomNumbers[j]=temp;
                    }
                }
            }
            for (int k = 0; k < asRandomNumbers.length; k++) {
                Node node = new Node(asRandomNumbers[k]);
                nodeList.add(node);
            }
            return nodeList;
        }
        else  if (randomType == 2){     //invertedRandomNumbers
            int i, j;

            Random random = new Random();
            HashSet hashset = new HashSet();
            for(;;){
                int tmp = random.nextInt(setN * setAlpha)+1;
                hashset.add(tmp);
                if(hashset.size() == setN) break;
            }

            Integer[] asRandomNumbers = (Integer[]) hashset.toArray(new Integer[hashset.size()]);


            for(i=0; i<asRandomNumbers.length; i++){
                for(j=1; j<asRandomNumbers.length-i; j++){
                    if(asRandomNumbers[j-1] > asRandomNumbers[j]){
                        int temp;
                        temp = asRandomNumbers[j-1];
                        asRandomNumbers[j-1] = asRandomNumbers[j];
                        asRandomNumbers[j]=temp;
                    }
                }
            }
            for (int k = 0; k < asRandomNumbers.length; k++) {
                Node node = new Node(asRandomNumbers[asRandomNumbers.length - k - 1]);
                nodeList.add(node);
            }
            return nodeList;
        }
        else {      //randomNumbers
            ArrayList<Integer> list = new ArrayList<Integer>();
            for (int i=1; i<(setN * setAlpha)+1; i++) {
                list.add(i);
            }
            Collections.shuffle(list);
            for (int k = 0; k < setN; k++) {
                Node node = new Node(list.get(setN - k - 1));
                nodeList.add(node);
            }
            return nodeList;
        }

    }



}
