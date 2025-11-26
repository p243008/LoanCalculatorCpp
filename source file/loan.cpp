#include"Loan.h"
#include<cmath>
Loan::Loan(long double amount,long double interest,int year)
{
this->amount=amount;
interestRate=interest;
years=year;
}
long double Loan::calculateTotalamount()
{
return (years*amount)+(years*amount*(interestRate/100.0));
}
long double Loan::calculateTotalinterest()
{
return calculateTotalamount()-(years*amount);
}
long double Loan:: calculateMonthlyamount()
{
return calculateTotalamount()/(years*12);
}

