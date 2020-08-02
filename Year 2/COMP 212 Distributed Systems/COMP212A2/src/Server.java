import java.rmi.Naming;


public class Server {
  public Server(){}
  public static void main(String[] args) {
	//if (System.getSecurityManager() == null) {
    //    System.setSecurityManager(new SecurityManager());
    //}
    try {
      // Instantiating the implementation class
      //SecondImpl remote = new SecondImpl();
      castVoteImp remote = new castVoteImp();
      Naming.rebind ("Dater1", remote);

      System.out.println("Object bound to name");

    }
    catch(Exception e) {
      System.out.println("Error occurred at server  "+e.getMessage());
    }
 }
}

