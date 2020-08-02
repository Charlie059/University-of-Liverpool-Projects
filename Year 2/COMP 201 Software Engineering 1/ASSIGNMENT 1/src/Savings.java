/*
 * COMP201 2019-20
 * Assignment 1
 * Savings.java
 * NAME:Xuhui Gong
 * STUDENT ID:201447569
 * COMPUTER USERNAME:sgxgong4
 */
 
 public class Savings extends Account{
	//Default constructor for Savings account - sets initial balance to 0
	public Savings()
	{
		super();
		setBalance(0.0);
	}
	
	public Savings(double theAmount, Customer theCustomer) throws AccountException
	{
		if(theAmount < 0.0)
		{
			throw new AccountException("Cannot open a Savings account with negative balance: " + theAmount);
		}
		setBalance(theAmount);
		holder = theCustomer;
		holder.setAccount(this);
		
		System.out.println("Savings account opened for " + holder.name + " with balance of " + getBalance());
	}
	
	public void close() throws AccountException
	{
		if(getBalance() < 0.0)
		{
			throw new AccountException("Cannot close a Savings account with negative balance: " + getBalance());
		} else
		{
			System.out.println("Closing the account...");
			System.out.println("Please return £" + getBalance() + " to the customer.");
			setBalance(0.0);
			System.out.println("Balance at account closure is now: £" + getBalance());
		}
	}
	
	public void withdraw(double amount) throws AccountException
	{
		if(amount <= 0.0)
		{
			throw new AccountException("Can only withdraw a non-zero positive amount of money");
		}else if( amount > getBalance() )
		{
			throw new AccountException("Insufficient funds available. Account balance is £" + getBalance() + ". You cannot withdraw £" + amount + "\n");
		} else 
		{
			System.out.println("Withdrawal of £" + amount + " by " + holder.name);
			setBalance(getBalance() - amount);
			System.out.println("New balance: £" + getBalance());
		}
		
	}
	
	
};
