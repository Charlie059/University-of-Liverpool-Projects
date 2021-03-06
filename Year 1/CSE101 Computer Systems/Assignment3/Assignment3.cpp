// Assingment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	int loop;                     //Store the number of cycles entered by the user named loop
	int realLoop = 0;             //Store the number of entries(The user can also count correctly when canceling the calculation)
	char userEnter;               //Detect user-entered characters
	int i = 1;                    //Intracycle counter which show the correct number like "Enter alphanumeric character %d:"
	int counterUpper = 0;         //Uppercase letter counter
	int counterLower = 0;         //Lowercase letter counter
	int counterEven = 0;          //Even counter
	int counterOdd = 0;           //Odd counter


	char message1[] = "Give me a number for a loop: \n";     //Show the message1
	char message2[] = "Please enter a positive interger.\n";   //Show the message2
	char message3[] = "Enter alphanumeric character %d:";      //Show the message3
	char message4[] = "Stop";                                  //Show the message4
	char message5[] = "Lowercase\n";                           //Show the message5
	char message6[] = "Uppercase\n";                           //Show the message6
	char message8[] = "Even\n";                                //Show the message7
	char message7[] = "Odd\n";                                 //Show the message8
	char message9[] = "Number of entries character is %d\n";   //Show the entries character which user entered
	char message10[] = "Number of uppercase character is %d\n";//Show the uppercase character which user entered
	char message11[] = "Number of lowercase character is %d\n";//Show the lowercase character which user entered
	char message12[] = "Number of even character is %d\n";     //Show the even character which user entered
	char message14[] = "Number of odd character is %d\n";      //Show the odd character which user entered
	char formot[] = "%d";									   //Int data placeholder in text in c language
	char scanner[] = "%c";									   //Char data placeholder in text in c language

	_asm {
	begin:													   //jump tp the begin when ueser input the neigative number
		    lea eax, message1;                                 //Put the address of message1 into eax
		    push eax									       //Push eax onto the stack
			call printf										   //Use the printf method to print the message1
			add esp, 4										   //Because we made changes to the stack, we have to restore the stack
	/*The above four sentences are intended to print message1*/
			lea eax, loop									   //Put the address of loop(int) into eax
			push eax										   //Push eax onto the stack
			lea eax, formot									   //Put the address of formot(char which has %d)into eax
			push eax										   //Push eax onto the stack
			call scanf_s									   //Use the printf method to print the int loop into the char[]
			add esp, 8										   //Because we made changes to the stack, we have to restore the stack
	/*The above six sentences are intended to scan the loop which uerser input*/
			mov eax,loop									   //Copy the value of loop to eax
			cmp eax, 0										   //Compare the size of eax and 0
			jle neigative									   //Skip to negative operation when eax is less than or equal to 0
			jg positive						                   //Jump into positive operation when eax is greater than 0
    /*The above four sentences are intended to compare the user input whether it is greater than 0*/
			neigative :										   //jump neigative if the user input is neigative
		    lea eax, message2								   //Put the address of message2 into eax
			push eax										   //Put the address of message2 into eax
			call printf										   //Use the printf method to print the message2("Please enter a positive interger.\n")
			add esp, 4										   //Because we made changes to the stack, we have to restore the stack
			jmp begin										   //jump to the begin let user reenter the loop number
    /*The above six sentences are intended to show if the user input the neigative number, the command will let user reenter the loop numebr*/
			positive :										   //if the loop number that user input is correct then jump into the positive


		while :												   //The cycle which the system looped


			mov eax, loop									   //Copy the value of loop number to eax
			cmp eax, 0									       //Compare the size of eax and 0
			je end_while									   //If loop equals to 0, then jump to the end_while

			sub loop, 1										   //Subtract the value of each loop by 1
	/*The above four sentences are intended to begin the loop and consider whether the loop is over*/
			push i											   //Push i into the stack and let i become a loop counter that shows print 
															   //which show the "Number of entries character is %d\n"
			lea eax, message3							       //Print Message 3
			push eax										   //Put the address of message3 into eax
			call printf										   //Use the printf method to print the message3
			add esp, 8										   //Because we made changes to the stack, we have to restore the stack
			mov eax, 1											
			add i, eax									       //Let the i++
	/*The above seven sentences are intended to print the message3 and let i++ in each loop*/



			lea eax, userEnter								   //Put the address of userEnter into eax
			push eax										   //Push eax onto the stack
			lea eax, scanner								   //Scan user-entered characters
			push eax										   //Push eax onto the stack
			call scanf_s									   //Use the scanf method to allow user input
			call scanf_s									   //???
			add esp, 8										   //Because we made changes to the stack, we have to restore the stack

			movzx eax, byte ptr[userEnter]					   //Convert user-entered data to ASCII
			cmp eax, 42										   //Check the number of users or input *
			je stop											   //If the user enters *, jump to stop

			jne consider									   //If the user does not enter, jump to the consider

	/*The above 11 sentences are intended to consider whether input "*" */


			consider:										   //consider part
		movzx eax, byte ptr[userEnter]					       //Convert user-entered data to ASCII and move to the eax
			cmp eax, 97										   //Determine if the user enters lower letters
			jge lowercase								       //If it is a lower letter, it is judged to be lowercase

			cmp eax, 65										   //Determine if the user enters upper letters
			jge uppercase									   //If it is a upper letter, it is judged to be uppercase

			cmp eax, 57										   //Determine if the user enters 0-9
			jle number										   //If it is a lowercase letter, it is judged to be number

	/*The above 7 sentences are intended to consider the uppercase and lowercase and number */


			uppercase :
		add counterUpper, 1									   //Add one to the uppercase counter
			add realLoop, 1									   //Add one to the actual number of cycles
			lea eax, message6								   //Put the address of message5 into eax
			push eax										   //Push eax onto the stack
			call printf									       //Use the printf method to print the message6
			add esp, 4										   //Because we made changes to the stack, we have to restore the stack
			jmp while										   //Enter the loop again after the judgment is over
	/*The above 7 sentences are intended to show the imformation which is uppercase*/

			lowercase:
		add counterLower, 1									   //Add one to the lowercase counter
			add realLoop, 1									   //Add one to the actual number of cycles
			lea eax, message5							       //Put the address of message6 into eax
			push eax										   //Push eax onto the stack
			call printf									       //Use the printf method to print the message5
			add esp, 4									       //Because we made changes to the stack, we have to restore the stack
			jmp while									       //Enter the loop again after the judgment is over
	/*The above 7 sentences are intended to show the imformation which is lowercase*/
			number:
		movzx eax, byte ptr[userEnter]						   //Convert user-entered data to ASCII and move to the eax
			cmp eax, 48										   //Check if the user enters 0
			je ev											   //Determine the user input even number
			cmp eax, 49										   //Check if the user enters 1
			je odd										       //Determine the user input odd number
			cmp eax, 50										   //Check if the user enters 2
			je ev											   //Determine the user input even number
			cmp eax, 51										   //Check if the user enters 3
			je odd											   //Determine the user input odd number
			cmp eax, 52									       //Check if the user enters 4
			je ev											   //Determine the user input even number
			cmp eax, 53										   //Check if the user enters 5
			je odd											   //Determine the user input odd number
			cmp eax, 54										   //Check if the user enters 6
			je ev											   //Determine the user input even number
			cmp eax, 55										   //Check if the user enters 7
			je odd											   //Determine the user input odd number
			cmp eax, 56										   //Check if the user enters 8
			je ev										       //Determine the user input even number
			cmp eax, 57										   //Check if the user enters 9
			je odd											   //Determine the user input odd number

	/*The above 21 sentences are intended to show the imformation which is ood or even*/
	
			ev :
		    add counterEven, 1								   //Add one to the even counter
		    add realLoop, 1									   //Add one to the actual number of cycles
			lea eax, message8;								   //Put the address of message8 into eax
		    lea eax, message8;								   //Put the address of message8 into eax
		    push eax										   //Push eax onto the stack
			call printf										   //Use the printf method to print the message8
			add esp, 4										   //Because we made changes to the stack, we have to restore the stack
			jmp while										   //Enter the loop again after the judgment is over
	/*The above 8 sentences are intended to show the imformation which is even to the user*/
			odd:
		    add counterOdd, 1								   //Add one to the odd counter
			add realLoop, 1									   //Add one to the actual number of cycles
			lea eax, message7;								   //Put the address of message7 into eax
		    push eax										   //Push eax onto the stack
			call printf										   //Use the printf method to print the message7
			add esp, 4										   //Because we made changes to the stack, we have to restore the stack
			jmp while										   //Enter the loop again after the judgment is over
    /*The above 7 sentences are intended to show the imformation which is odd to the user*/
			end_while:										   //Jump when ending the loop


	stop:

		push realLoop										   //Push the int realLoop in to the stack
			lea eax, message9								   //Put the address of message9 into eax
			push eax										   //Push eax onto the stack
			call printf										   //Use the printf method to print the message9

			push counterUpper								   //Push the int counterUpper in to the stack
			lea eax, message10								   //Put the address of message10 into eax
			push eax										   //Push eax onto the stack
			call printf										   //Use the printf method to print the message10

			push counterLower								   //Push the int counterLower in to the stack
			lea eax, message11								   //Put the address of message11 into eax
			push eax									       //Push eax onto the stack
			call printf										   //Use the printf method to print the message11

			push counterEven								   //Push the int counterEven in to the stack
			lea eax, message12								   //Put the address of message12 into eax
			push eax										   //Push eax onto the stack
			call printf										   //Use the printf method to print the message12

			push counterOdd									   //Push the int counterOdd in to the stack
			lea eax, message14								   //Put the address of message14 into eax
			push eax										   //Push eax onto the stack
			call printf										   //Use the printf method to print the message14
			add esp, 40							               //Because we made changes to the stack, we have to restore the stack

	/*The above sentences are intended to show the realloop, counterUpper, counterLower, counterEven, counterOdd to the user*/
	}
	return 0;
}

