import java.util.Vector;

/*
 * COMP201 Assignment 1
 * CreditUnion.java *V2*
 * NAME: Xuhui Gong
 * STUDENT ID:201447569
 * COMPUTER USERNAME:sgxgong4
 * 
 */
 
 public class CreditUnion{
	 
	 public Vector<Account> accounts;
	 public Vector<Person> people;
	 private double initialCapital = 0.0;

	public CreditUnion()
	{
			accounts = new Vector<Account>();
			people = new Vector<Person>();
	}

	public CreditUnion(double initial) throws AccountException
	{
			accounts = new Vector<Account>();
			people = new Vector<Person>();
			
			//TODO: Make sure you can't have a negative amount of initial capital
		if (initial < 0){
			System.out.println("No negative amount of initial capital");
			throw new AccountException("Negative amount of initial capital");
		}
		initialCapital = initial;
	}
	
	public CreditUnion(double initial, Clerk theClerk) throws AccountException
	{
		accounts = new Vector<Account>();
		people = new Vector<Person>();
		
		//TODO: Make sure you can't have a negative amount of initial capital
		if (initial < 0){
			System.out.println("No negative amount of initial capital");
			throw new AccountException("Negative amount of initial capital");
		}
		initialCapital = initial;
		
		people.add(theClerk);
		theClerk.setUnion(this);	
	}


	 /**
	  * Makes a descision on a loan application. 
	  *	Loan should be approved if the following are true (as per brief):
	  * 	1) the amount is no more than £5000,
	  *		2) Amount is no more than 5% of total capital held by the credit union.
	  *		3) Loaning the money does not make the credit union go into negative capital
	  *
	  * @param theClerk - The clerk who is processing the application
	  * @param amount - Amount that the loan is for
	  * @return true: Loan application approved
	  *			false: Loan applcation denied
	  */
	public Boolean processLoanApplication(Person theClerk, double amount)
	{
		//Check theClerk is authorised to process loan applciation
		if(!(theClerk instanceof Clerk)) return false;

		//Check that this Clerk is a true clerk at the credit union
		boolean exists = false;
		for(int i = 0; i < people.size(); i++)
		{
			
			if(people.elementAt(i).equals(theClerk)) 
			{
				exists = true;
			}
			if(!exists) return false;
		}

		double unionBalance = this.getTotalCapital(theClerk); //Total capital held by bank
		double threshold = unionBalance * 0.05; //Threshold to satisfy criterion 2
		if(amount <= threshold && unionBalance - threshold >= 0.0) //Check points 2 and 3 are satisfied
		{
			//Loan approved
			return true;
		}
		//Otherwise, loan is declined
		return false;
	}

	/**
	 * Gets the sum of all account balances in the credit union
	 * @return Sum of all account balances in {@link}accounts
	 */
	public double getTotalCapital(Person p)
	{
		//TODO: This method should only be available to Clerks
		if (p.getClass().getName() == "Clerk"){
			double totalCapital = 0.0;

			totalCapital += initialCapital;

			//Loop through all accounts held by credit union
			for(int i = 0; i < accounts.size(); i ++)
			{
				//Get each account balance and then add it to total capital
				double balance = accounts.elementAt(i).getBalance();
				totalCapital+=balance;
			}
			//Return answer
			return totalCapital;
		}
		else {
			//If not clerk return -1
			System.out.println("ERROR, Only Clerk can get total capital");
			return -1;
		}


	}
	
};
