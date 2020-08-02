public class Message {
    private int messID;     //def the message passing id
    public enum DirectionSet {out,in};    //enum the set of the directions
    private DirectionSet direction;  //def the direction when using the HS
    private int hopCount;   //def the hopCount when using the HS






    public Message(){}

    public Message(int setMessID){
        this.messID = setMessID;
    }

    public Message(int setMessID, DirectionSet setDirection, int setHopCount){
        this.messID = setMessID;
        this.hopCount = setHopCount;
        this.direction = setDirection;
    }

    /*getter and setter*/
    public int getMessID() {
        return messID;
    }

    public void setMessID(int setMessID) {
        this.messID = setMessID;
    }
    public int getHopCount() {
        return hopCount;
    }

    public void setHopCount(int hopCount) {
        this.hopCount = hopCount;
    }

    public void setDirection(DirectionSet direction) {
        this.direction = direction;
    }

    public DirectionSet getDirection() {
        return direction;
    }



}
