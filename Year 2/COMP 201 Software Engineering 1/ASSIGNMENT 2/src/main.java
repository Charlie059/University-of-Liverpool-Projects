//Xuhui Gong
//sgxgong4
//201447569

import java.util.Date;

//This is the main function to let the program compile
public class main {
    public static void main(String[] args) {
        Mechanic mechanic = new Mechanic("Tom","Mechanic");
        Customer customer = new Customer("Maple",1100012);
        Date deadline = new Date();
        Task task = new Task(2,2);
        Ticket ticket = new Ticket(12,"check",customer,12,task,deadline,2120,"NAN");
        System.out.println(ticket.getDeadline());
    }
}
