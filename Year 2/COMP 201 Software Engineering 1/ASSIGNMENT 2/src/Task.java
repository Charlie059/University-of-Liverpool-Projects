import java.util.Date;

public class Task {
    private String taskName;

// For generalType, perform inspection tasks, repair tasks, and maintenance tasks
// For specificType, each generalType has their specificType, for example: perform inspection tasks has MOT test which means taskNameToArray[0][0] = "MOT test";
    public Task(int generalType,int specificType)
    {

        String[][] taskNameToArray = new String[3][];
        taskNameToArray[0] = new String[2];
        taskNameToArray[1] = new String[4];
        taskNameToArray[2] = new String[3];
        taskNameToArray[0][0] = "MOT test";
        taskNameToArray[0][1] = "General diagnostic test";
        taskNameToArray[1][0] = "body repair";
        taskNameToArray[1][1] = "engine repair";
        taskNameToArray[1][2] = "window replacement";
        taskNameToArray[1][3] = "insurance mandated repair";
        taskNameToArray[2][0] = "air conditioning top-up";
        taskNameToArray[2][1] = "body respray";
        taskNameToArray[2][2] = "tyre change";
        //Initialize the 2D array
        try {
            taskName = taskNameToArray[generalType][specificType];
        } catch (Exception e) {
            e.printStackTrace();
        }
        //Try to init the task and give the name
    }



    ////Getter and Setter
    public String getTaskName() {
        return taskName;
    }

    public void setTaskName(String taskName) {
        this.taskName = taskName;
    }
////End of getter and setter


}


