import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;
import java.util.Random;
import java.util.Vector;

public class castVoteImp extends UnicastRemoteObject implements castVote {
    private int[] votingResult = {0, 0, 0};
    private  Vector<StringBuffer> EncryptionToken= new Vector<>();

    // Implementing the interface method
    public castVoteImp() throws RemoteException {
    }

    ;

    public void vote(int choice, String localTicket) {
        //validation

        try {
            if (MD5Validation(localTicket) == true){

                System.out.println(choice);
                if (choice == 1) {
                    votingResult[0]++;
                } else if (choice == 2) {
                    votingResult[1]++;
                } else {
                    votingResult[2]++;
                }

            }
            else {System.out.println("ERROR, NO PERMISSIONS");
            System.out.println();
            }
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }

    //return the voting result
    public String getVotingResults(String localTicket) throws RemoteException {
        //validation
        try {
            if (MD5Validation(localTicket) == true){
                String votingResult = "The number 1: Vote Times = " + this.votingResult[0] + "\nThe number 2: Vote Times = " + this.votingResult[1] + "\nThe number 3: Vote Times = " + this.votingResult[2];
                System.out.println(votingResult);
                return votingResult;
            }
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        String warning = "ERROR, NO PERMISSIONS";
        return warning;
    }

    //The client ask server to generate a random code and return back to the client
    public String randomGenerationCode() throws RemoteException {
        int counter = 0;
        // ticket dictionary
        char[] str = {'1', '2', '3', '4', '5', '6', '7', '8', '9','@','#','$','%','&','*','a','b','c'};
        StringBuffer sb = new StringBuffer("");
        Random r = new Random();
        while (counter < 16) {
            int i = r.nextInt(str.length);
            sb.append(str[i]);
            counter++;
        }
        try {
            MD5Encryption(sb.toString());   //Encryption to store in the server
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        System.out.println(sb.toString());
        return sb.toString();
    }

    //MD5Encryption
    public void MD5Encryption(String unEncryptionTicket) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("MD5");
        md.update(unEncryptionTicket.getBytes());
        byte[] bs = md.digest();//Encryption
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < bs.length; i++) {//translate to the hex
            int v = bs[i] & 0xff;
            if (v < 16) {
                sb.append(0);
            }
            sb.append(Integer.toHexString(v));
        }
        EncryptionToken.add(sb);
    }

    //MD5Validation
    public boolean MD5Validation(String ValidatingTicket) throws NoSuchAlgorithmException {

        MessageDigest md = MessageDigest.getInstance("MD5");
        md.update(ValidatingTicket.getBytes());
        byte[] bs = md.digest();//Encryption
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < bs.length; i++) {//translate to the hex
            int v = bs[i] & 0xff;
            if (v < 16) {
                sb.append(0);
            }
            sb.append(Integer.toHexString(v));
        }

        //looking for table
        for (int i = 0; i < EncryptionToken.size(); i++) {
            if ( EncryptionToken.get(i).toString().equals(sb.toString())){
                return true;
            }
        }
        return false;
    }


}
