//Xuhui Gong
//sgxgong4
//201447569
public class Receptionist extends Staff{

    public Receptionist(String setName, String setType) {
        super(setName, setType);
    }

    public Ticket discussAndOpenTicket(Customer customer, Task task){
        Ticket ticket = new Ticket();
        return ticket;
    }
    //The Receptionist can talk to the customer and open a ticket

    public void checkTicketAndCallCustomer(Ticket ticket){

    }
    //The Receptionist check the ticket in the signed off, and call the customer to pick up the vehicle
    public void showTheVehicle(Customer customer, Ticket ticket){

    }
    //The Receptionist shows the vehicle to the customer
}
