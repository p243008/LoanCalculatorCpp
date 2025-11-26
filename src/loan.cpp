#include "Loan.h"
#include <cmath>
#include <iostream>
using namespace std;

Loan::Loan(long double amount, long double interest, int year)
{
    this->amount = amount;
    interestRate = interest;
    years = year;
}

long double Loan::calculateTotalamount()
{
    return amount + (amount * (interestRate / 100.0) * years);
}

long double Loan::calculateTotalinterest()
{
    return amount * (interestRate / 100.0) * years;
}

long double Loan::calculateMonthlyamount()
{
    return calculateTotalamount() / (years * 12);
}
