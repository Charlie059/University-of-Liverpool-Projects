/*
 * COMP201 Assignment 1
 * Person.java
 * NAME:Xuhui Gong
 * STUDENT ID:201447569
 * COMPUTER USERNAME:sgxgong4
 * 
 */
 
 public class Person{
	 public String name;

     public Person()
     {
         name = new String("UNKNOWN");
     }

     public Person(String theName)
     {
         name = new String(theName);
         System.out.println("A person named " + name + " has been created.");
     }
};
