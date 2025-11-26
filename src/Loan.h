#ifndef LOAN_H
#define LOAN_H

class Loan{
private:

long double amount;
long double interestRate;
int years;
public:
Loan(long double amount,long double interest,int year);
long double calculateTotalamount();
long double calculateTotalinterest();
long  double calculateMonthlyamount();


};
#endif