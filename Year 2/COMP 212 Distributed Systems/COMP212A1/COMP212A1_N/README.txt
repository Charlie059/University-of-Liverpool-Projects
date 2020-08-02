Note:	All the output is written into the testResult, there are no console output

1. The program need to run in the main class, the method called runningTestandOutput is the main controller. There are six parameters in this method, which are 

1.1 increase step --> Control the each times the node number increase; 

1.2 repeat Step times --> Control how many times the simulator repeat. ie. The increaseStep * repateStepTimes == The final node numbers in the simulator; 

1.3 repeatOneNodeTime --> In random, one node need to run many times, for example, if you want to repeat 100 times in node num == 1000, so you need to set this parameter to the 100;

1.4 Random types --> 1. ascendingRandomNumbers 2.invertedRandomNumbers 3.randomNumber

1.5 NumberOfNode --> select the num of nodes start from the simulator;

1.6 NumberOfAlpha --> if the node id need to pick from 1 to alpha*n, eg: if you set alpha to 3, then the id pick from the 1 to the 3n	

	
2. The Main method: runningTestandOutput(10,1000,1,2,100,3);


3. Due to performance reasons and the correctness of the program has been verified by a large number of data tests, the verifier is turned off by default, however, you can manually turn it on: 

It is in the method of runningTestandOutput, line 33 and 42, you can output into the file

4. The dataset has been saved into the dataset files. ie. Excel and Txt. If you want to check, please open it, however, excel file needs a lot of time to open because the data is too large.


