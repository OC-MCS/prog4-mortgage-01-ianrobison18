// implementation file for Mortgage class
#include <iostream>
using namespace std;
#include "Mortgage.h"

// Constructors
/*
Name: Mortgage
Purpose: set default values for class
Parameters: none
*/
Mortgage::Mortgage()
{
	payment = 0;
	rate = 0.0f;
	term = 0;
	loan = 0;
	years = 0;
}

/*
Name: Mortgage
Purpose: set values for class
Parameters: initial loan, rate, and years 
*/
Mortgage::Mortgage(int l, float r, int yr)
{
	payment = 0;
	rate = r;
	term = pow((1 + r/12), 12 * yr);
	loan = l;
	years = yr;
}

// Setters
/*
Name: set loan amount
Purpose: sets the value for the variable loan
Parameters: loan
Returns: none
*/
void Mortgage::setLoanAmount(int l)
{
	loan = l;
}

/*
Name: set rate
Purpose: sets the value for the variable rate
Parameters: rate
Returns: none
*/
void Mortgage::setRate(float r)
{
	rate = r;
}

/*
Name: set years
Purpose: sets the value for the variable years
Parameters: years
Returns: none
*/
void Mortgage::setYears(int yr)
{
	years = yr;
}

// Other Functions
/*
Name: find payment
Purpose: finds payment value
Parameters: none
Returns: payment value
*/
float Mortgage::findPayment()
{
	payment = (loan * rate / 12 * term) / (term - 1);
	return payment;
}