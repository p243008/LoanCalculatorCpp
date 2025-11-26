#include<iostream>
#include<fistream>
#include<string>
#include "Loan.h"
using namespace std;
int main(){

long double loan_amount=0;
long double interest_rate=0;
int year=0;

ifstream config("config.txt");
if(config.is_open()){
string k;
char eq;
while(config>>k>>eq){
if(k=="default_amount")config>>loan_amount;
else if(k=="default_interest")config>>interest_rate;
else if (k=="default_year")config>>year;
}
config.close();
}
cout<<"enter loan amount("<<loan_amount<<"):"<<endl;
long double input;
cin>>input;
if(input>0) loan_amount=input;
cout<<"enter interest rate("<<interest_rate<<"):"<<endl;
cin>>input;
if(input>0) interest_rate=input;
cout<<"enter the year("<<year<<"):"endl;
cin>>input;
if(input>0) year=input;
//input validation
if(loan_amount<=0 || interest_rate<=0  || year<=0){
cout<<"All must be greater then zero(0)"<<endl;
return 1;

}
Loan myloan(loan_amount,interest_rate,year);

cout<<"Total Loan to be paid"<<myloan.calculateTotalamount()<<endl;
cout<<"Total Interest: "<<myloan.calculateTotalinterest()<<endl;

cout<<"Monthly Payment: "<<myloan.calculateMonthlyamount()<<endl;

return 0;


}