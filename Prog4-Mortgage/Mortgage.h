#pragma once
// header file for Mortgage class

class Mortgage
{
private:
	float payment,
		rate,
		term;
	int loan,
		years;
public:
	Mortgage();
	Mortgage(int loan, float rate, int years);
	void setLoanAmount(int l);
	void setRate(float r);
	void setYears(int yr);
	float findPayment();
};
