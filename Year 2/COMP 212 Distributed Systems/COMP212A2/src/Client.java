/*
 * The security manager is not being used in this example, hence, no security
 * control. Note that RMI will not download classes (other than from the local
 * class path) for objects received as parameters, return values, or exceptions
 * in remote method calls. This restriction ensures that the operations
 * performed by downloaded code go through a set of security checks.
*/

import java.rmi.*;
import java.util.Scanner;


public class Client {

  public static void main(String[] args) {
    String localTicket = "";
    try {
      castVote sgen = (castVote) Naming.lookup("rmi://localhost/Dater1");

      
      //Main Menu
      boolean flag = false;
      int input_ = 0;
      Scanner menuInput = new Scanner(System.in);
      do {
        System.out.println("\n\n****************************************************************");
        System.out.println("Welcome to the voting system");
        System.out.println("Please select the option by entering 1, 2.etc.");
        System.out.println("1. Connect to the Server and ask a ticket");
        System.out.println("2. Enter the Voting System without ticket");
        System.out.println("****************************************************************\n");
        String menuInputStr ="";
        if (menuInput.hasNextLine()) {  //receive the str input
          menuInputStr = menuInput.next();
          System.out.println("You entered" + menuInputStr);
          System.out.println("****************************************************************\n");
        }
        if (menuInputStr.length()==1 && !menuInputStr.matches("\\p{Alpha}")){   //check only valid input
          input_ = Integer.parseInt(menuInputStr);
          if (input_ == 1 || input_ == 2){
            flag = true;
          }
          else {
            System.out.println("Wrong number, please reenter");
          }
        }
        else {
         System.out.println("Please enter the valid number");
        }

      }
      while (!flag);

      if (input_ == 1) {
        ///////////////////////////////////
        //ask and store a ticket
        localTicket = sgen.randomGenerationCode();
        System.out.println("You have asked a ticket, ticketNo is: " + localTicket);
        ///////////////////////////////////


        voteUI();
        boolean inner_flag = false;
        String inputStr = "";
        do {

          String menuInputStr ="";
          if (menuInput.hasNextLine()) {  //receive the str input
            menuInputStr = menuInput.next();
            System.out.println("You entered" + menuInputStr);
          }
          if (menuInputStr.length()==1 && !menuInputStr.matches("\\p{Alpha}")){   //check only valid input
            input_ = Integer.parseInt(menuInputStr);
            if (input_ == 1 || input_ == 2 || input_ == 3){
              inner_flag = true;
            }
            else {
              System.out.println("Wrong number, please reenter");
            }
          }
          else {
            System.out.println("Please enter the valid number");
          }

        }
        while (!inner_flag);

        sgen.vote(input_,localTicket);
        System.out.println("You have voted successful, now you can see the result");
        System.out.println("From the server: \n"+sgen.getVotingResults(localTicket));

      }
      else {
        voteUI();
        String inputStr = "";
        if (menuInput.hasNextLine()) {
          inputStr = menuInput.next();
          System.out.println("You entered" + inputStr);
        }
        int input = Integer.parseInt(inputStr);
        menuInput.close();

        sgen.vote(input,localTicket);
        System.out.println("\n****************************************************************\n");
        System.out.println("From the server: \n"+sgen.getVotingResults(localTicket));
        System.out.println("****************************************************************\n");
      }


    }
    catch(Exception e) {
      System.out.println("Problem encountered accessing remote object "+e);
    }
  }
  public static void voteUI(){
    System.out.println("****************************************************************\n");
    System.out.println("* Please elect student union representatives");
    System.out.println("* 1. Charlie");
    System.out.println("* 2. Trump");
    System.out.println("* 3. Maple");
    System.out.println("* Please vote 1 or 2 or 3");
    System.out.println("****************************************************************\n");
  }

}
