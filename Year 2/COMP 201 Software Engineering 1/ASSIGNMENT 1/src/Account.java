/*
 * COMP201 Assignment 1
 * Account.java
 * NAME:Xuhui Gong
 * STUDENT ID:201447569
 * COMPUTER USERNAME:sgxgong4
 * 
 */
 
 abstract class Account{
	 private double balance; //The account balance
	 public Customer holder; //Account Holder
	 
	 public void setHolder(Customer theCustomer)
	 {
			holder = theCustomer;
	 }
	 
	 public Customer getHolder()
	 {
			return holder;
	 }
	 
	 //Returns the balance of the account
	 public double getBalance()
	 {
			return balance;
	 }
	 
	 //Sets the balance of the account to amount
	 public void setBalance(double amount)
	 {
			balance = amount;
	 }
	 
	 //Increases the account balance by the amount
	 public double payment(double amount)
	 {
		  setBalance(getBalance() + amount);
		  System.out.println("______________________________________");
		  System.out.println(this.holder.name+" Payment Success with "+ amount);
		  System.out.println("______________________________________");
		  return getBalance();
	 }
	 
	 //TODO: Abstract methods - to be implemented in each class that extends Account as per reqs
	  abstract void close() throws AccountException; //Closes the account
	  abstract void withdraw(double amount) throws AccountException; //Withdraws money
};
