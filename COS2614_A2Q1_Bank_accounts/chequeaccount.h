#ifndef CHEQUEACCOUNT_H
#define CHEQUEACCOUNT_H
#include "account.h"

class ChequeAccount : public Account
{
public:
    ChequeAccount();
    ChequeAccount(QString cn, QString an, double ir, double od);
    void transaction(double amt);
    void calcInterest();
    double getOverdraft();
    QString toString();
private:
    double overdraft;
};

#endif // CHEQUEACCOUNT_H
