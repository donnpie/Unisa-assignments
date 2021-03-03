#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "account.h"



class SavingsAccount : public Account
{
public:
    SavingsAccount();
     SavingsAccount(QString cn, QString an, double ir);
     SavingsAccount &operator=(const SavingsAccount & other);
     SavingsAccount &operator=(const Account & other);
     void transaction(double amt);
        //be sure to define these virtual function in the cpp file, else the compiler gives and error
     void calcInterest();
     int getPoints();
     QString toString();
     static double minIntEarnedForPoints;
private:
    int points;

};

#endif // SAVINGSACCOUNT_H
