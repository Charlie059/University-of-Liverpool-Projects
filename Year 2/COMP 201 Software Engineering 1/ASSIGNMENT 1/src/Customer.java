/*
 * COMP201 2019-20
 * Assignment 1
 * Customer.java
 * NAME:Xuhui Gong
 * STUDENT ID:201447569
 * COMPUTER USERNAME:sgxgong4
 */
 
 public class Customer extends Person{
	 public Account myAccount; //The customers account
	 
	 public Customer()
	 {
			super();
	 }
	 
	 public Customer(String theName)
	 {
			super(theName);
	 }
	 
	 public String getName()
	 {
			return name;
	 }
	 
	 public void setName(String newName)
	 {
			name = newName;
	 }
	 
	 public void setAccount(Account theAccount)
	 {
			myAccount = theAccount;
	 }
	 
	 public void makeWithdrawal(double amount)
	 {
		 try
		 {
			 	 //TODO: Make sure this only happens for a Savings Account
			 // Checking it only happens for a Savings Account
			if (myAccount instanceof Savings == true){
				myAccount.withdraw(amount);
			}
			else {
				System.out.println("Withdraw Fail");
			}

				//return myAccount.getBalance();
		  } catch (AccountException e)
		  {
			  //TODO:: Handle gracefully
			System.out.println("Withdraw Fail");
			}
	 }
	 
	 public double makePayment(double amount)
	 {
			myAccount.payment(amount);
			return myAccount.getBalance();
	 }
};
