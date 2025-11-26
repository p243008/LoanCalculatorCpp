#include<gtest/gtest.h>
#include"../hardcode/Loan.h"
//EIM CALCULATION FOR NORMAL
TEST(Loantest,normalemi){
Loan l1(100000,12,10);
EXPECT_NEAR(l1.calculateTotalamount(),100000*10+100000*10(12/100.0),0.01);

EXPECT_NEAR(l1.calculateTotalinterest(),100000*10*(12/100.0),0.01);

EXPECT_NEAR(l1.calculateMonthlyamount(),100000*10+100000*10(12/100.0)/(10*12),0.01);
}

//INVALID INPUT HANDLING

TEST(Loantest,invalidinput){
 Loan l2(-5000,12,2);
EXPECT_LT(l2.calculateTotalamount(),0);
Loan l3(5000,-10,2);
EXPECT_LT(l3.calculateTotalamount(),5000*2);
Loan l4(5000,12,-2);
EXPECT_LT(l4.calculateTotalamount(),5000*2);

}
//WITHOUT OVERFLOW

TEST(Loantest,overflow);
Loan l5(1000,5,1000);
EXPECT_NEAR(l5.calculateTotalamount(),1000*1000+1000*1000(5/100.0),0.01);

EXPECT_NEAR(l5.calculateTotalinterest(),1000*1000*(5/100.0),0.01);

EXPECT_NEAR(l5.calculateMonthlyamount(),1000*1000+1000*1000(5/100.0)/(1000*5),0.01);

//MAIN FUNCTION

int main(int argc,char **argv){
::testing :: InitGoogleTest(&argc,argv);
return RUN_ALL_TESTS();
}
