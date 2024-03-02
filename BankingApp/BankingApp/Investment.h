#pragma once

class Investment
{

public:

	// Default and parameterized constructor for the "investment" class
	Investment();
	Investment(double t_initial, double t_deposit, double t_interest, int t_years);

	// Functions that will be used for calculation and printing the results for the user
	double calculateTotal();
	double calculateInterest();
	void run();
	
	// Getter/setter methods for variables
	void setInitialInvestment(double t_initial);
	void setMonthlyDeposit(double t_deposit);
	void setAnnualInterest(double t_interest);
	void setNumberYears(int t_years);
	void setBalanceTotal(double t_total);
	void setClosingBalance(double t_balance);
	void setInterestTotal(double t_interest);
	double getInitialDeposit() const { return m_initialInvestment; }
	double getMonthlyDeposit() const { return m_monthlyDeposit;  }
	double getAnnualInterest() const { return m_annualInterest;  }
	int getNumberYears() const { return m_numberYears; }
	double getBalanceTotal() const { return m_balanceTotal; }
	double getClosingBalance() const { return m_closingBalance; }
	double getInterestTotal() const { return m_interestTotal;  }
	
private: 

	// Variables to store the user's data and calculate results
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_annualInterest;
	int m_numberYears;	
	double m_interestTotal;
	double m_balanceTotal;
	double m_closingBalance;

};

