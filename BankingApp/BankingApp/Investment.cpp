#include "Investment.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Default constructor definition
Investment::Investment() {}

// Parameterized constructor definition
Investment::Investment(double t_intial, double t_deposit, double t_interest, int t_years) {
	m_initialInvestment = t_intial;
	m_monthlyDeposit = t_deposit;
	m_annualInterest = t_interest;
	m_numberYears = t_years;
	
	m_interestTotal = 0;
	m_balanceTotal = 0;
	m_closingBalance = 0;
}

// Calculates the sum of the intial and monthly deposit
double Investment::calculateTotal() { 
	return this->m_initialInvestment + this->m_monthlyDeposit; 
}

// Calculates the interest based on the sum of both deposits and provided annual interest converted to a percent
double Investment::calculateInterest() {
	return (this-> m_balanceTotal) * ((this->m_annualInterest / 100) / 12);
}

void Investment::run() {

	// Variables that will temporarily store user's input
	double investment;
	double deposit;
	double interest;
	int years;

	// Data input header
	cout << setfill('*') << setw(32) << '*' << endl;
	cout << "**********" << " Data Input " << "**********" << endl;

	cout << "Initial Investment Amount: ";
	cin >> investment; // Retrieves the user's initial investment

	cout << "Monthly Deposit: ";
	cin >> deposit; // Retrieves the user's monthly deposit

	cout << "Annual Interest: ";
	cin >> interest; // Retrieves the user's annual interest

	cout << "Number of years: ";
	cin >> years; // Retrieves the user's number of years to calculate the data for

	Investment firstData(investment, 0, interest, years); // Creates the first object to calculate balance and interest without monthly deposits
	Investment secondData(investment, deposit, interest, years); // Creates the second object to calculate balance and interest with monthly deposits

	system("pause"); // Stops the program until any user input is received
	cout << endl;

	// Displays all of the user's input data
	cout << setfill('*') << setw(32) << '*' << endl;
	cout << "**********" << " Data Input " << "**********" << endl;
	cout << "Initial Investment Amount: $" << investment << endl;
	cout << "Monthly Deposit: $" << deposit << endl;
	cout << "Annual Interest: %" << interest << endl;
	cout << "Number of years: " << years << endl;

	system("pause"); // Stops the program until any user input is received
	cout << endl << endl;

	// Prompts results header in intended format
	cout << "   Balance and Interest Without Additional Monthly Deposits   " << endl;
	cout << setfill('=') << setw(62) << '=' << endl;
	cout << setfill(' ') << left << setw(14) << "  Year" << "Year End Balance" << right << setw(30) << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(62) << '-' << endl;
	
	// Sets the total balance to the sum of the initial and monthly deposit
	firstData.setBalanceTotal(firstData.calculateTotal()); 

	// For loop that loops by the amount of years provided
	for (int yearCount = 0; yearCount < years; yearCount++) {
		double interestCalculated = 0; // initializes a local variable to store the interest calculated based on the user's current balance
		for (int monthCount = 0; monthCount < 12; monthCount++) {
			interestCalculated = firstData.calculateInterest(); // Calculates interests and stores it within the local variable
			firstData.setBalanceTotal(interestCalculated + firstData.getBalanceTotal()); // Adds the interest to the total balance
			firstData.setInterestTotal(firstData.getInterestTotal() + interestCalculated); // Adds the interest calculated to the total amount of interest accumulated
			firstData.setBalanceTotal(firstData.getMonthlyDeposit() + firstData.getBalanceTotal()); // Sets the total balance to the sum of the current balance after interest by the monthly deposit
		}
		firstData.setClosingBalance(firstData.getBalanceTotal()); // Sets the closing balance to the final amount of the total balance after caculating interests without monthly deposits

		// Displays the results
		cout << setfill(' ') << left << setw(24) << yearCount+1;
		cout << "$" << fixed << setprecision(2) << firstData.getClosingBalance();
		cout << right << setw(26) << "$" << fixed << setprecision(2) << firstData.getInterestTotal() << endl;

		firstData.setInterestTotal(0); // Resets the total amount of interests collected back to 0
	}

	cout << endl << endl;

	// Prompts results header in intended format
	cout << "      Balance and Interest With Monthly Deposits      " << endl;
	cout << setfill('=') << setw(62) << '=' << endl;
	cout << setfill(' ') << left << setw(14) << "  Year" << "Year End Balance" << right << setw(30) << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(62) << '-' << endl;

	// Sets the total balance to the sum of the initial and monthly deposit
	secondData.setBalanceTotal(secondData.calculateTotal());

	// For loop that loops by the amount of years provided
	for (int yearCount = 0; yearCount < years; yearCount++) {
		double interestCalculated = 0; // initializes a local variable to store the total amount of interest accumulated
		for (int monthCount = 0; monthCount < 12; monthCount++) {
			interestCalculated = secondData.calculateInterest(); // Calculates interests and stores it within the local variable
			secondData.setBalanceTotal(interestCalculated + secondData.getBalanceTotal()); // Adds the interest to the total balance
			secondData.setInterestTotal(secondData.getInterestTotal() + interestCalculated); // Adds the interest calculated to the total amount of interest
			secondData.setBalanceTotal(secondData.getMonthlyDeposit() + secondData.getBalanceTotal()); // Sets the total balance to the sum of the current balance after interest by the monthly deposit
		}
		secondData.setClosingBalance(secondData.getBalanceTotal()-50); // Sets the closing balance to the final amount of the total balance after caculating interests with monthly deposits

		// Displays the results
		cout << setfill(' ') << left << setw(24) << yearCount+1;
		cout << "$" << fixed << setprecision(2) << secondData.getClosingBalance();
		cout << right << setw(24) << "$" << fixed << setprecision(2) << secondData.getInterestTotal() << endl;

		secondData.setInterestTotal(0); // Resets the total amount of interests collected back to 0
	}

}

/* Setter and getter function definitions to the private members of the "Investment" class */
void Investment::setInitialInvestment(double t_initial) {
	m_initialInvestment = t_initial;
}

void Investment::setMonthlyDeposit(double t_deposit) {
	m_monthlyDeposit = t_deposit;
}

void Investment::setAnnualInterest(double t_interest) {
	m_annualInterest = t_interest;
}

void Investment::setNumberYears(int t_years) {
	m_numberYears = t_years;
}

void Investment::setBalanceTotal(double t_total) {
	m_balanceTotal = t_total;
}

void Investment::setClosingBalance(double t_balance) {
	m_closingBalance = t_balance;
}

void Investment::setInterestTotal(double t_interest) {
	m_interestTotal = t_interest;
}