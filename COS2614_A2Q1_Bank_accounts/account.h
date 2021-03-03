#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>
#include <QList>
#include <QDebug>
#include "Transaction.h"

//This is an abstract class.
//The derived (concrete) classes are SavingsAccount and ChequeAccount

/*
The Account class contains the common aspects
of different bank accounts such as the customer name,
account number, account balance, type of account ("Savings"
or "Cheque"), interest rate and a list of transactions. The
account type is set by the constructors of the concrete
subclasses of Account. A transaction is of type "Deposit"
or "Withdrawal" or "Interest" and it is automatically
recorded when a deposit or a withdrawal is made, or when
interest is added to or subtracted from an account. A deposit
or a withdrawal is achieved using the function transaction(),
where a positive amount (amt) indicates a deposit and a
negative amount indicates a withdrawal. The function calcInterest()
calculates the interest on the account and updates the balance
accordingly. You need not be concerned about when calcInterest()
will be invoked as it is meant to be automatically invoked once
a month. Note that both transaction() and calcInterest() do not
have implementations in Account as these functions are meant to
be implemented in the subclasses.
*/


class Account
{
public:
    Account();
    Account(QString cn, QString an, double ir, QString ty);
        //Overloaded constructor
    //Account(const Account& other); //Copy constructor
    Account & operator=(const Account & other); //Assignment operator
    virtual ~Account();
        //When a class is pure virtual, the destructor must be defined. See
        //https://stackoverflow.com/questions/3065154/undefined-reference-to-vtable
    QString getCustName();
    QString getAccNum();
    double getBalance();
    QList<Transaction> getTransaction();
    void printTransactions();
    QString toString();
    QString getType();
    double getInterestRate();
    virtual void transaction(double amt) = 0;
    virtual void calcInterest() = 0;
private:
    QString custName;
    QString accNum;
    double interestRate;
    QString type;
protected:
    double balance;
    QList<Transaction> transactions;

};

#endif // ACCOUNT_H
