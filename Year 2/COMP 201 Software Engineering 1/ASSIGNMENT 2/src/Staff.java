//Xuhui Gong
//sgxgong4
//201447569
public class Staff extends Person {
    private String staffType;

    public Staff(String setName, String setType) {
        super(setName);
        this.staffType = setType;
    }

    ////Getter and Setter
    public String getStaffType() {
        return staffType;
    }

    public void setStaffType(String staffType) {
        this.staffType = staffType;
    }
    //End of getter and setter
}
