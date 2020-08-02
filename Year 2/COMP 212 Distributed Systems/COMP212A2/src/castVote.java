import java.security.NoSuchAlgorithmException;

public interface castVote extends java.rmi.Remote {
    void vote (int choice, String localTicket) throws java.rmi.RemoteException;
    String getVotingResults(String localTicket) throws java.rmi.RemoteException;
    String randomGenerationCode() throws java.rmi.RemoteException;
}
