//Xuhui Gong
//sgxgong4
//201447569

public class Vehicle {
    private String vehicleType;
    private int vehicleId;

    public Vehicle(String setVehicleType,int setVehicleId){
        this.vehicleType = setVehicleType;
        this.vehicleId = setVehicleId;
    }


    ////Getter and setter
    public String getVehicleType() {
        return vehicleType;
    }
    //
    public void setVehicleType(String vehicleType) {
        this.vehicleType = vehicleType;
    }

    public int getVehicleId() {
        return vehicleId;
    }

    public void setVehicleId(int vehicleId) {
        this.vehicleId = vehicleId;
    }

    ///End of getter and setter
}
