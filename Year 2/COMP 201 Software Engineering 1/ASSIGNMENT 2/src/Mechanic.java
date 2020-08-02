//Xuhui Gong
//sgxgong4
//201447569
public class Mechanic extends Staff{

    public Mechanic(String setName, String setType) {
        super(setName, setType);
    }

    public void viewWaitingTicket(Ticket ticket){

    }
    //The Mechanic checks the ticket which the status is waiting


    public  Ticket changeTicketStatus(Ticket ticket){
        return ticket;
    }
    //The Mechanic can change the status of the ticket


    public void performWork(){

    }
    //The Mechanic do the task

    public Ticket addNoteInTicket(Ticket ticket){
        return ticket;
    }
    //If any unexpected cost, the note will add into the ticket

}
