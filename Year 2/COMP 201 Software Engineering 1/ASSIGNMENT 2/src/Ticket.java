//Xuhui Gong
//sgxgong4
//201447569

import java.util.Date;

public class Ticket {
    private int ticketId;
    private String status;
    private Customer customerInfo;
    private int vehicleId;
    private Task workRequired;
    private Date deadline;
    private int quotedPrice;
    private String note;

    public Ticket(){

    }

    //Use a non-parameter constructor is easy to test

    public Ticket(int setTicketId, String setStatus,Customer customer,int vehicleId, Task task,Date setDeadline,int setQuotedPrice, String setNote){
        this.ticketId = setTicketId;
        this.status = setStatus;
        this.customerInfo = customer;
        this.vehicleId = vehicleId;
        this.workRequired = task;
        this.deadline = setDeadline;
        this.quotedPrice = setQuotedPrice;
        this.note = setNote;
    }
    ////Getter and Setter
    public int getTicketId() {
        return ticketId;
    }

    public void setTicketId(int ticketId) {
        this.ticketId = ticketId;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public Customer getCustomerInfo() {
        return customerInfo;
    }

    public void setCustomerInfo(Customer customerInfo) {
        this.customerInfo = customerInfo;
    }

    public Task getWorkRequired() {
        return workRequired;
    }

    public void setWorkRequired(Task workRequired) {
        this.workRequired = workRequired;
    }

    public Date getDeadline() {
        return deadline;
    }

    public void setDeadline(Date deadline) {
        this.deadline = deadline;
    }

    public int getQuotedPrice() {
        return quotedPrice;
    }

    public void setQuotedPrice(int quotedPrice) {
        this.quotedPrice = quotedPrice;
    }

    public String getNote() {
        return note;
    }

    public void setNote(String note) {
        this.note = note;
    }

    public int getVehicleId() {
        return vehicleId;
    }

    public void setVehicleId(int vehicleId) {
        this.vehicleId = vehicleId;
    }

    ////End of getter and setter
}
