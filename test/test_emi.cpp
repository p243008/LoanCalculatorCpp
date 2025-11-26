#include<iostream>
#include<cmath>
#include"../src/Loan.h"
using namespace std;

void testNormalEMI()
{
    cout<<"=== Test 1: Normal EMI Calculation ==="<<endl;
    Loan l1(100000,12,10);
    
    double total=l1.calculateTotalamount();
    double interest=l1.calculateTotalinterest();
    double monthly=l1.calculateMonthlyamount();
    
    cout<<"Total Amount: "<<total<<endl;
    cout<<"Total Interest: "<<interest<<endl;
    cout<<"Monthly Payment: "<<monthly<<endl;
    
    double expected_total=100000+(100000*(12/100.0)*10);
    double expected_interest=100000*(12/100.0)*10;
    double expected_monthly=(100000+(100000*(12/100.0)*10))/(10*12);
    
    if(abs(total-expected_total)<0.01)
    {
        cout<<"PASS: Total amount calculation correct"<<endl;
    }
    else
    {
        cout<<"FAIL: Total amount calculation wrong"<<endl;
    }
    
    if(abs(interest-expected_interest)<0.01)
    {
        cout<<"PASS: Total interest calculation correct"<<endl;
    }
    else
    {
        cout<<"FAIL: Total interest calculation wrong"<<endl;
    }
    
    if(abs(monthly-expected_monthly)<0.01)
    {
        cout<<"PASS: Monthly amount calculation correct"<<endl;
    }
    else
    {
        cout<<"FAIL: Monthly amount calculation wrong"<<endl;
    }
}

void testInvalidInput()
{
    cout<<"\n=== Test 2: Invalid Input Handling ==="<<endl;
    
    Loan l2(-5000,12,2);
    double result2=l2.calculateTotalamount();
    cout<<"Negative amount result: "<<result2<<endl;
    if(result2<0)
    {
        cout<<"PASS: Negative amount handled"<<endl;
    }
    else
    {
        cout<<"FAIL: Negative amount not handled properly"<<endl;
    }
    
    Loan l3(5000,-10,2);
    double result3=l3.calculateTotalamount();
    cout<<"Negative interest result: "<<result3<<endl;
    if(result3<(5000*2))
    {
        cout<<"PASS: Negative interest handled"<<endl;
    }
    else
    {
        cout<<"FAIL: Negative interest not handled properly"<<endl;
    }
    
    Loan l4(5000,12,-2);
    double result4=l4.calculateTotalamount();
    cout<<"Negative years result: "<<result4<<endl;
    if(result4<(5000*2))
    {
        cout<<"PASS: Negative years handled"<<endl;
    }
    else
    {
        cout<<"FAIL: Negative years not handled properly"<<endl;
    }
}

void testLargeNumbers()
{
    cout<<"\n=== Test 3: Large Numbers Without Overflow ==="<<endl;
    
    Loan l5(1000,5,1000);
    
    double total=l5.calculateTotalamount();
    double interest=l5.calculateTotalinterest();
    double monthly=l5.calculateMonthlyamount();
    
    cout<<"Large Total Amount: "<<total<<endl;
    cout<<"Large Total Interest: "<<interest<<endl;
    cout<<"Large Monthly Payment: "<<monthly<<endl;
    
    double expected_total=1000+(1000*(5/100.0)*1000);
    
    if(total>0&&!isinf(total))
    {
        cout<<"PASS: Large numbers handled without overflow"<<endl;
    }
    else
    {
        cout<<"FAIL: Overflow occurred with large numbers"<<endl;
    }
    
    if(abs(total-expected_total)<0.01)
    {
        cout<<"PASS: Large total amount calculation correct"<<endl;
    }
    else
    {
        cout<<"FAIL: Large total amount calculation wrong"<<endl;
    }
}

int main()
{
    cout<<"=========================================="<<endl;
    cout<<"      LOAN CALCULATOR SIMPLE TESTS"<<endl;
    cout<<"=========================================="<<endl;
    
    testNormalEMI();
    testInvalidInput();
    testLargeNumbers();
    
    cout<<"\n=========================================="<<endl;
    cout<<"             TESTS COMPLETED"<<endl;
    cout<<"=========================================="<<endl;
    
    return 0;
}
