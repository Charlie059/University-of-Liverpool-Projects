//Xuhui Gong
//sgxgong4
//201447569
public class Manager extends Mechanic{

    public Manager(String setName, String setType) {
        super(setName, setType);
    }

    public void chargeOfStaffs(Staff staff){

    }
    //The manager should charge all staffs

    public Ticket viewTicketInCheck(Ticket ticket){
        return ticket;
    }
    //The manager view the ticket in status of check

    public Ticket updatePrice(Ticket ticket){
        return ticket;
    }
    //The manager updates the price if there are unexpected cost

}
