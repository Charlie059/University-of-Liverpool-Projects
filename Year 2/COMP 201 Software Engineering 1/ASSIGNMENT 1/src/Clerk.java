/*
 * COMP201 2019-20
 * Assignment 1
 * Clerk.java *V2*
 * NAME:Xuhui Gong
 * STUDENT ID:201447569
 * COMPUTER USERNAME:sgxgong4
 */
 
 public class Clerk extends Person{
	private CreditUnion union;
	 
	 public Clerk()
	 {
		 super(); 
	  }
	 
	 public Clerk(CreditUnion theUnion)
	 {
		 super();
		 union = theUnion;
	 }
	 
	 public Clerk(String theName)
	 {
			super(theName);
	 }
	 
	 public void setUnion(CreditUnion theUnion)
	 {
			union = theUnion;
	 }
	 
	 
	 public void addAccount(Account theAccount)
	{

		union.accounts.add(theAccount);
		
	}
	
	public void rmAccount(Account theAccount)
	{
			//TODO: Complete this method as opposite of addAccount(Account, Person)

		//Close the account
		try {
			theAccount.close();
		} catch (AccountException e) {
			System.out.println("Close Failure");
		}

		//Delete the account from vector
		for (int i = 0; i < this.union.accounts.size(); i++) {
			if (this.union.accounts.get(i).holder.name == theAccount.holder.name) {
				this.union.accounts.remove(i);
			}


		}
	}
	
	public void addCustomer(Customer c)
	{
		union.people.add(c);
		System.out.println("Customer " + c.name + " is registered with the Credit Union");
	}
	
	public void rmCustomer(Customer c) {


	}
	public boolean openSavings(Customer theCustomer, double openAmount)
	 {
		 //Check the Customer is registered with the union
		 if(!(union.people.contains(theCustomer)))
		 {
			 addCustomer(theCustomer);
		 }
		 
			 //Check we are opening the account with a valid amount
			 if(openAmount >=0.0)
			 {
				 try
				 {
					//Create a Saving account for the customer with the openAmount
					Account theAccount = new Savings(openAmount, theCustomer); 
					addAccount(theAccount);
					return true;
				 }catch(AccountException e)
				 {
						System.out.println("Account Exception caught whilst opening a savings account");
				 }
				
			 }
		 
		 return false;
	 }
	 
	 public boolean openLoan(Customer theCustomer, double theAmount)
	 {
		 //TODO: Complete this method - use the Process Loan method to help
		 //If this customer is not registered in the union, add customer to union
		 if(!(union.people.contains(theCustomer)))
		 {
			 addCustomer(theCustomer);
		 }

		 if(this.union.processLoanApplication(this,-theAmount) == true && theAmount >= -5000)
		 {
			 try
			 {
				 Account theAccount = new Loan(theAmount);
				 theAccount.setHolder(theCustomer);
				 theAccount.holder.setAccount(theAccount);
				 addAccount(theAccount);
				 System.out.println("Loan account opened for " + theAccount.holder.name + " with balance of " + theAccount.getBalance());
				 return true;

			 }catch(AccountException e)
			 {
				 System.out.println("Account Exception caught whilst opening a savings account");
			 }

		 }
		 else
			 System.out.println("Account Exception caught whilst opening a savings account");

		 return false;

		 //The Clerk use union processLoanApplication method to consider opening loan account

	 }
	 
	 public boolean closeAccount(Account account)
	 {
		 //TODO: Complete this method


		return true;

	 }
	 
	 public boolean applyInterest()
	{	//TODO: Complete this method
		for (int i = 0; i < union.accounts.size(); i++) {
			if ((union.accounts.get(i).getClass().getName() == "Loan")) {
				union.accounts.get(i).setBalance(union.accounts.get(i).getBalance()*(1+0.0001));
			}
		}
		return true;
	}
};
