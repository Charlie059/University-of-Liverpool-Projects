/*
 * COMP201 Assignment 1
 * Loan.java
 * NAME:Xuhui Gong
 * STUDENT ID:201447569
 * COMPUTER USERNAME:sgxgong4
 */
 
 public class Loan extends Account{
	 //Default constructor for Loan account - sets initial balance to 0
	public Loan()
	{
		super();
		setBalance(0.0);
	}
	
	public Loan(double amount) throws AccountException
	{
		if(amount > 0.0)
		{
			throw new AccountException("Cannot open a Loan account with positive balance: " + amount);
		}
		else{

			setBalance(amount);

		}


		//TODO: Complete the opening of this Loan account
	}
	
	public void close() throws AccountException
	{
		if(getBalance() < 0.0)
		{
			throw new AccountException("Cannot close a Savings account with negative balance: " + getBalance());
		} else if (getBalance() > 0.0)
        {
            throw new AccountException("Cannot close a loan account with positive balance, this should not have happened, so an error has occured! Balance is: £" + getBalance());
        } else
		{
			System.out.println("Closing the account...");
			System.out.println("Please return £" + getBalance() + " to the customer.");
			System.out.println("Balance at account closure is now: £" + getBalance());
		}
	}
	
	/**
	 * Makes Payment into the loan account
	 * @return The new balance
	 * @param amount the amount to make payment of
	 */ 
	public double payment(double amount)
	{
		//TODO: Complete this method inline with reqs
		//Make sure that the customer cannot make a payment beyond the balance
		if (amount>=0 && amount <= -(this.getBalance())){
			setBalance(getBalance() + amount);
			return getBalance();}
		else
			System.out.println("Payment Must lager than 0 and smaller than the balance");
		return getBalance();
	}
	
	public void withdraw(double amount) throws AccountException
	{
			throw new AccountException("...");
	}
};
