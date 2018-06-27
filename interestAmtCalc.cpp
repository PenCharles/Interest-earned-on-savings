#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

	//Author: James Saylor
	//Description : This program will ask the user for monthly savings, interest
	//				rate and savings goal to calculate the length of time needed
	//				to save measured in months.

//constants
const double LOW_SAVE = 5;
const double HIGH_SAVE = 5000;
const double LOW_INTEREST = 1;
const double HIGH_INTEREST = 25;
const double TOTAL_SAVE = 1000000;

//function prototypes
double SavedAmount ();
double InterestAmount ();
double TotalAmount ();
double FactorFormula (double interest, int month);
double TotalPerMonth (double factor, double interest, double monthlySavings);

int main ()
{
	//local variables
	double monthlySavings;
	double interestRate;
	double goal;
	double factor;
	double amtPerMonth;
	int month = 1;
	
	cout << setprecision(2) << showpoint << fixed;
	cout << " Program will calculate the amount accumulated every month you" 
		 << " save, until you reach your goal." << endl << endl;
		 
	monthlySavings = SavedAmount ();
	interestRate = InterestAmount ();
	goal = TotalAmount ();
	goal = floor((goal * 100) + 0.5) / 100.0;
	
	cout << "Month      Total" << endl;
	cout << "Number     Accumulated" << endl;
	cout << "------     -----------" << endl;
	
	cout << setprecision(2) << showpoint << fixed;
	do
	{
		factor = FactorFormula (interestRate, month);
		amtPerMonth = TotalPerMonth (factor, interestRate, monthlySavings);
		//amtPerMonth = floor((amtPerMonth * 100) + 0.5) / 100.0;
		cout << setw(4) << month << setw(16) << amtPerMonth << endl;
		month++;
	}
	while (amtPerMonth <= goal);
	
	cout << endl << setprecision(3);
	cout << "At an annual interest rate of" << setw(12) << interestRate << " %";
	cout << endl << setprecision(2);
	cout << "With a montly savings of" << setw(17) << monthlySavings << endl;
	cout << "It will take" << setw(29) << month << " months" << endl;
	cout << "To reach your goal of" << setw(20) << goal << endl;
	cout << "With a final accumulation of" << setw(13) << amtPerMonth << endl;	
 	cout << endl << endl;
 	return 0;
}

double SavedAmount ()
{
	double amount;
	
	cout << noshowpoint << setprecision(0);
	do
	{
		cout << " Enter the dollar amount to be saved each month"
			 << " (between " << LOW_SAVE << " and " << HIGH_SAVE << "): ";
		cin >> amount;
		cout << endl;
		
		if (amount < LOW_SAVE || amount > HIGH_SAVE)
		{
			cout << "Invalid amount --- must save between " << LOW_SAVE << " and "
				 << HIGH_SAVE << " dollars a month. Try again." << endl << endl;
		}	
	}
	while (amount < LOW_SAVE || amount > HIGH_SAVE);

	return amount;
}

double TotalAmount ()
{
	double amount;
	
	do
	{
		cout << " Enter a positive amount that is less than 1 million: ";
		cin >> amount;
		cout << endl;
		
		if (amount < LOW_INTEREST || amount >= TOTAL_SAVE)
		{
			cout << "Invalid amount --- must be between " << LOW_INTEREST << " and "
				 << TOTAL_SAVE << ". Try again." << endl << endl;
		}
		
	}
	while (amount < LOW_INTEREST || amount >= TOTAL_SAVE);
	
	return amount;
}

double InterestAmount ()
{
	double amount;
	
	do
	{
		cout << " Enter the annual interest (between " << LOW_INTEREST << " and " 
	     	 << HIGH_INTEREST << "): ";
		cin >> amount;
		cout << endl;
		
		if (amount < LOW_INTEREST || amount > HIGH_INTEREST)
		{
			cout << "Invalid amount --- must be between " << LOW_INTEREST
			     << " and " << HIGH_INTEREST << ". Try again." << endl << endl;
		}
	}
	while (amount < LOW_INTEREST || amount > HIGH_INTEREST);
	
	amount = ((amount / 100) / 12);
	
	return amount;

}

double FactorFormula (double interest, int month)
{
	double factor;
	
	factor = exp(month * (log(1 + interest)));
	
	return factor;
}

double TotalPerMonth (double factor, double interest, double monthlySavings)
{
	double total;
	
	total = ((factor - 1) * monthlySavings) / interest;
	
	return total;
}


