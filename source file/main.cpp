#include<iostream>
#include"Loan.h"
using namespace std;
int main()
{
long double loan_amount;
long double interest_rate;
int no_years;

cout<<"Enter The Loan Amount"<<endl;
cin>>loan_amount;
cout<<"Enter The Interest Rate"<<endl;
cin>>interest_rate;
cout<<"Enter The Number Of Years"<<endl;
cin>>no_years;

if(loan_amount<=0 || interest_rate<=0 || no_years<=0)
{
  cout<<"Enter The Number Greater Then Zero"<<endl;
    
      return 1;
     }
       Loan myloan(loan_amount,interest_rate,no_years);
       cout<<"Total Amount is to be Paid: "<<myloan.calculateTotalamount()<<endl;
       cout<<"Total Interest is to be Paid: "<<myloan.calculateTotalinterest()<<endl;
       cout<<"Monthly Amounts to be Paid: "<<myloan.calculateMonthlyamount()<<endl; 
  return 0;
}
