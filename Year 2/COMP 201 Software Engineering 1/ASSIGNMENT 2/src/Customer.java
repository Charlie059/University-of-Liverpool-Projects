//Xuhui Gong
//sgxgong4
//201447569

import java.util.Vector;

public class Customer extends Person {
    private int phoneNumber;
    private Vector<Vehicle> vehicles;

    public Customer(String setName, int setPhoneNumber) {
        super(setName);//Extends the inheritance
        this.phoneNumber = setPhoneNumber;

    }


    public void addVehicle(){

    }
    //Customer can have more than one vehicles


    public void rmVehicle(){

    }
    //Remove the vehicle

    public Vector<Vehicle> talkToStaff(){
        return vehicles;
    }
    //The customer talks to the receptionist to give the vehicle info

    public Customer infoToStaff(){
        return this;
    }
    //The customer talks to the receptionist to give the customer info

    public void payTheBill(){

    }
    //The customer pays the money to the receptionist


    public void collectTheVehicle(){

    }
    //After paying the bill, the customer collect the vehicle


    ////Getter and Setter
    public int getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(int phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public Vector<Vehicle> getVehicles() {
        return vehicles;
    }

    public void setVehicles(Vector<Vehicle> vehicles) {
        this.vehicles = vehicles;
    }

    ////End of Getter and Setter
}
