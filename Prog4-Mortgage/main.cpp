/*
Ian Robison
Mortgage Class Program
February 17, 2019
Prgramming II
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "Mortgage.h"

bool parseInt(string cS, int &val);
bool parseFloat(string cS, float &val);
int main()
{
	int loanAmount = 0, //the amount for the loan
		years = 0;		//Years of life you lose to the loan
	float rate = 0,		//percent of money you lose to interest
		payment;	//How much you lose every month
	string loanS,	//Loan amount, but as a string
		yearS,		//years of life lost . . . as a string
		rateS;		//percent lost . . . . . . as a striiiiiiinnnnnnnggggg
	bool validNum = false;

	cout << fixed << showpoint << setprecision(2);
	cout << "In order to calculate your monthly payment, I must know a few things.\n";
	while (!validNum)
	{
		cout << "What is the loan amount? ";
		cin >> loanS;
		validNum = parseInt(loanS, loanAmount);
	}

	validNum = false;
	while (!validNum)
	{
		cout << "Now, how many years to fulfill the loan? ";
		cin >> yearS;
		validNum = parseInt(yearS, years);
	}

	validNum = false;
	while (!validNum)
	{
		cout << "Finally, what is the interest rate? ";
		cin >> rateS;
		validNum = parseFloat(rateS, rate);
		
		if (rate >= 1)
		{
			rate = rate / 100;
		}
	}

	Mortgage mort(loanAmount, rate, years);
	payment = mort.findPayment();

	cout << "Your monthly payment is $" << payment << endl;


	return 0;
}

/*
Name: Parse int
Purpose: To convert a string to an int and catch any exceptions
Parameters: choice as a string and the value passed by reference
Outputs: whether the choice was valid or not
*/
bool parseInt(string cS, int &val)
{
	int num; //Number to check
	bool success = true; //whether or not the parse succeeded.

	try
	{
		num = stoi(cS);
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
		cout << "Invalid input. Try again\n\n";
	}

	return success;
}

/*
Name: Parse float
Purpose: To convert a string to an float and catch any exceptions
Parameters: choice as a string and the value passed by reference
Outputs: whether the choice was valid or not
*/
bool parseFloat(string cS, float &val)
{
	float num; //Number to check
	bool success = true; //whether or not the parse succeeded.

	try
	{
		num = stof(cS);
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
		cout << "Invalid input. Try again\n\n";
	}

	return success;
}