public class Node {
    private int myID;
    public enum statusSet {unknown,leader};    //enum the set of the status
    private statusSet status;
    private Message inMess = new Message();     //define the incoming and outgoing message
    private Message outMess = new Message();
    private Node inNode;    //define the in_neighborhood of the node (counter-clockwise)
    private Node outNode;    //define the in_neighborhood of the node  (clockwise)
    private Integer leaderID;     //define the leaderID when the node know the leader id finally
    private int phase = 0;      //define the phase to control the message send range
    private boolean sendMessFlag = true;    //define the sendMessFlag when using HS
    private Message sendClock = new Message();      //define the sendClock in HS
    private Message sendCounterclock= new Message();    //define the sendCounterclock in HS

    private Message ClockBuffer = new Message();      //define the messagebuffer to store the incoming in HS
    private Message CounterclockBuffer = new Message();      //define the messagebuffer to store the incoming in HS

    public Node (int setMyID){
        this.myID = setMyID;
        status = statusSet.unknown;     //initially  set the status to the unknown
    }

    public Node (int setMyID, Node setInNode, Node setOutNode){
        this.myID = setMyID;
        this.status = statusSet.unknown;     //initially  set the status to the unknown
        this.inNode = setInNode;
        this.outNode = setOutNode;
    }

    /*define the method of receiving message when LCR*/
    public void receiveLCRMess(){
        this.inMess.setMessID(this.inNode.outMess.getMessID()) ;   //the message has been sent from the pip, and let the node to receive the message(inMess)
        this.inNode.outMess.setMessID(0);//clear the mess(this.inNode.outMess)
    }

    /*define the method of sending and process message when LCR*/
    public void processLCRMess(int round){
        if (round == 1){
            this.outMess.setMessID(this.myID);    //in the first round, send itself ID to the out-neighbour(clockwise)
            LCR.numOfMess += 1;    //update the mess times
        }
        else {
            //  round >= 2 @Process take inMess and output(outMess)
            if (this.inMess.getMessID() > this.myID){
                this.outMess.setMessID(this.inMess.getMessID());    //pass the larger id
                LCR.numOfMess += 1;    //update the mess times
                this.inMess.setMessID(0);//clear the inMess

            }
            else if (this.inMess.getMessID() == this.myID){
                Main.leaderFlag = true;//set leader flag
                this.setStatus(statusSet.leader);
                this.setLeaderID(this.getMyID());
                this.inMess.setMessID(0);//clear the inID
                this.outMess.setMessID(this.myID);//send itself id and prepare the terminate loop
                LCR.numOfMess += 1;    //update the mess times
            }
            else if (this.inMess.getMessID() < this.myID){
                this.inMess.setMessID(0);   //clear messID
                //do nothing
            }
        }


    }
    public void leaderAnnounce(){
        if (this.getStatus() != statusSet.leader){
            receiveLCRMess();
            this.outMess.setMessID(this.inMess.getMessID());    //pass the leader id
            LCR.numOfMess += 1;    //update the mess times
            this.setLeaderID(this.inMess.getMessID());//setup leader id
            this.inMess.setMessID(0);//clear the inMess
        }
        else {
            receiveLCRMess();
            this.inMess.setMessID(0);//clear the inMess
        }


    }

    /*define the method of sending and process message when HS*/

    public void HSMessSend(){
        //double message space
        if (this.sendClock.getMessID() != 0){
            //sendclock Message to the clockwise node
            this.outNode.ClockBuffer.setMessID(this.sendClock.getMessID());
            this.outNode.ClockBuffer.setDirection(this.sendClock.getDirection());
            this.outNode.ClockBuffer.setHopCount(this.sendClock.getHopCount());
            HS.numOfMess ++;
            //clear the sendclock Message
            this.sendClock.setMessID(0);
            this.sendClock.setDirection(null);
            this.sendClock.setHopCount(0);

        }


        if (this.sendCounterclock.getMessID() != 0){
            //sendcounterclock Message to the counterclockwise node
            this.inNode.CounterclockBuffer.setMessID(this.sendCounterclock.getMessID());
            this.inNode.CounterclockBuffer.setDirection(this.sendCounterclock.getDirection());
            this.inNode.CounterclockBuffer.setHopCount(this.sendCounterclock.getHopCount());
            HS.numOfMess ++;
            //clear the sendclock Message
            this.sendCounterclock.setMessID(0);
            this.sendCounterclock.setDirection(null);
            this.sendCounterclock.setHopCount(0);
        }




    }

    public void HSSendMessBegin(){
        this.sendCounterclock.setMessID(this.getMyID());
        this.sendCounterclock.setDirection(Message.DirectionSet.out);
        this.sendCounterclock.setHopCount(1);
        this.sendClock.setMessID(this.getMyID());
        this.sendClock.setDirection(Message.DirectionSet.out);
        this.sendClock.setHopCount(1);
    }
    public void HSNodeBehaviour(){


//        upon receiving ⟨inID, out, hopCount⟩ from counterclockwise neighbour if inID > myIDi and hopCount > 1 then
//        sendClocki :=⟨inID,out,hopCount−1⟩ else if inID > myIDi and hopCount = 1 then
//        sendCounterclocki :=⟨inID,in,1⟩ else if inID = myIDi then
//        statusi := “leader” end if

        if ((this.ClockBuffer.getMessID() != 0)&&(this.ClockBuffer.getDirection() == Message.DirectionSet.out)){     //CB has sth != 0 and outDir
            if ((ClockBuffer.getMessID() > this.getMyID())&&(ClockBuffer.getHopCount() > 1)){
                this.sendClock.setMessID(ClockBuffer.getMessID());
                this.sendClock.setDirection(Message.DirectionSet.out);
                this.sendClock.setHopCount(ClockBuffer.getHopCount() - 1);

                //clear
                ClockBuffer.setMessID(0);
                ClockBuffer.setDirection(null);
                ClockBuffer.setHopCount(0);
            }
            else if ((ClockBuffer.getMessID() > this.getMyID())&&(ClockBuffer.getHopCount() == 1)){
                this.sendCounterclock.setMessID(ClockBuffer.getMessID());
                this.sendCounterclock.setDirection(Message.DirectionSet.in);
                this.sendCounterclock.setHopCount(1);

                //clear
                ClockBuffer.setMessID(0);
                ClockBuffer.setDirection(null);
                ClockBuffer.setHopCount(0);
            }
            else if (ClockBuffer.getMessID() == this.getMyID()){
                this.setStatus(statusSet.leader);
                HS.leaderFlag = true;
            }
        }

//        upon receiving ⟨inID, out, hopCount⟩ from clockwise neighbour if inID > myIDi and hopCount > 1 then
//        sendCounterclocki :=⟨inID,out,hopCount−1⟩ else if inID > myIDi and hopCount = 1 then
//        sendClocki :=⟨inID,in,1⟩ else if inID = myIDi then
//        statusi := “leader” end if

        if ((this.CounterclockBuffer.getMessID() != 0)&&(this.CounterclockBuffer.getDirection() == Message.DirectionSet.out)){     //CCB has sth != 0 and outDir
            if ((CounterclockBuffer.getMessID() > this.getMyID())&&(CounterclockBuffer.getHopCount() > 1)){
                this.sendCounterclock.setMessID(CounterclockBuffer.getMessID());
                this.sendCounterclock.setDirection(Message.DirectionSet.out);
                this.sendCounterclock.setHopCount(CounterclockBuffer.getHopCount() - 1);

                //clear
                CounterclockBuffer.setMessID(0);
                CounterclockBuffer.setDirection(null);
                CounterclockBuffer.setHopCount(0);
            }
            else if ((CounterclockBuffer.getMessID() > this.getMyID())&&(CounterclockBuffer.getHopCount() == 1)){
                this.sendClock.setMessID(CounterclockBuffer.getMessID());
                this.sendClock.setDirection(Message.DirectionSet.in);
                this.sendClock.setHopCount(1);

                //clear
                CounterclockBuffer.setMessID(0);
                CounterclockBuffer.setDirection(null);
                CounterclockBuffer.setHopCount(0);
            }
            else if (CounterclockBuffer.getMessID() == this.getMyID()){
                this.setStatus(statusSet.leader);
                HS.leaderFlag = true;
            }
        }

        //upon receiving ⟨inID, in, 1⟩ from counterclockwise neighbour, in which inID ̸= myIDi sendClocki :=⟨inID,in,1⟩

        if ((this.ClockBuffer.getMessID() != 0)&&(this.ClockBuffer.getDirection() == Message.DirectionSet.in)&&(this.ClockBuffer.getHopCount() == 1)){     //CB has sth != 0 and outDir
            if (this.ClockBuffer.getMessID() != this.getMyID()){
                this.sendClock.setMessID(this.ClockBuffer.getMessID());
                this.sendClock.setDirection(this.ClockBuffer.getDirection());
                this.sendClock.setHopCount(this.ClockBuffer.getHopCount());

                //clear
                ClockBuffer.setMessID(0);
                ClockBuffer.setDirection(null);
                ClockBuffer.setHopCount(0);
            }
        }

//        upon receiving ⟨inID, in, 1⟩ from clockwise neighbour, in which inID ̸= myIDi
//        sendCounterclocki :=⟨inID,in,1⟩

        if ((this.CounterclockBuffer.getMessID() != 0)&&(this.CounterclockBuffer.getDirection() == Message.DirectionSet.in)&&(this.CounterclockBuffer.getHopCount() == 1)){     //CB has sth != 0 and outDir
            if (this.CounterclockBuffer.getMessID() != this.getMyID()){
                this.sendCounterclock.setMessID(this.CounterclockBuffer.getMessID());
                this.sendCounterclock.setDirection(this.CounterclockBuffer.getDirection());
                this.sendCounterclock.setHopCount(this.CounterclockBuffer.getHopCount());

                //clear
                CounterclockBuffer.setMessID(0);
                CounterclockBuffer.setDirection(null);
                CounterclockBuffer.setHopCount(0);
            }
        }

//        upon receiving ⟨inID,in,1⟩ from both clockwise and counterclockwise neighbours, in
//        both of which inID = myIDi holds
//        phasei := phasei + 1
//        sendClocki :=⟨myIDi,out,2phasei⟩
//        endCounterclocki :=⟨myIDi,out,2phasei⟩


        if ((this.ClockBuffer.getMessID() != 0)&&(this.ClockBuffer.getDirection() == Message.DirectionSet.in)&&(this.ClockBuffer.getHopCount() == 1))
        {
            if ((this.CounterclockBuffer.getMessID() != 0)&&(this.CounterclockBuffer.getDirection() == Message.DirectionSet.in)&&(this.CounterclockBuffer.getHopCount() == 1)){
                if ((this.ClockBuffer.getMessID() == this.getMyID())&&(this.CounterclockBuffer.getMessID() == this.getMyID())){
                    phase = phase + 1;

                    sendClock.setMessID(this.getMyID());
                    sendClock.setDirection(Message.DirectionSet.out);
                    sendClock.setHopCount((int)Math.pow(2,phase));


                    sendCounterclock.setMessID(this.getMyID());
                    sendCounterclock.setDirection(Message.DirectionSet.out);
                    sendCounterclock.setHopCount((int)Math.pow(2,phase));

                    //clear
                    CounterclockBuffer.setMessID(0);
                    CounterclockBuffer.setDirection(null);
                    CounterclockBuffer.setHopCount(0);

                    //clear
                    ClockBuffer.setMessID(0);
                    ClockBuffer.setDirection(null);
                    ClockBuffer.setHopCount(0);


                }
            }
        }
    }


    public void rmNode(){   //let the node reuse from LCR to HS
        this.status = statusSet.unknown;
        this.leaderID = null;
    }

    /* getter and setter */

    public void setOutMessID(int id){
        this.outMess.setMessID(id);
    }
    public int getMyID() {
        return myID;
    }

    public statusSet getStatus() {
        return status;
    }

    public Message getInMess() {
        return inMess;
    }

    public Message getOutMess() {
        return outMess;
    }

    public Node getInNode() {
        return inNode;
    }

    public Node getOutNode() {
        return outNode;
    }

    public void setMyID(int myID) {
        this.myID = myID;
    }

    public void setStatus(statusSet status) {
        this.status = status;
    }

    public void setInMess(Message inMess) {
        this.inMess = inMess;
    }

    public void setOutMess(Message outMess) {
        this.outMess = outMess;
    }

    public void setInNode(Node inNode) {
        this.inNode = inNode;
    }

    public void setOutNode(Node outNode) {
        this.outNode = outNode;
    }
    public Integer getLeaderID() {
        return leaderID;
    }

    public void setLeaderID(Integer leaderID) {
        this.leaderID = leaderID;
    }

    public int getPhase() {
        return phase;
    }

    public void setPhase(int phase) {
        this.phase = phase;
    }


    public boolean isSendMessFlag() {
        return sendMessFlag;
    }

    public void setSendMessFlag(boolean sendMessFlag) {
        this.sendMessFlag = sendMessFlag;
    }




}
