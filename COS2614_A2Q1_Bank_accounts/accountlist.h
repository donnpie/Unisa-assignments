#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QList>
#include "account.h"
#include "savingsaccount.h"

class AccountList : QList<Account*>
{
public:
    AccountList();
    ~AccountList();
        //Deletes all the account objects
    bool addAccount(Account * a);
        //Adds and object pointed to by Account pointer, if an
        //account with that account number does not already exist in the list
    double totalBalance();
        //Returns the sum of balances of accounts in the list
    void doInterestCalculations();
        //Initiates interest calculations for all accounts in the list
    QString toString();
        //Returns string equivalant of all accounts in the list
    QStringList CustomersWithHighestPoints();
        //Returns all customer names with the highest points
    void printTransactionsForAllAccounts();
private:
    Account *findAccount(QString an);
        //Checks if an account with the given account number exists in the list
        //If it exists, return a pointer to that account.
        //if not, return null pointer
    QList<Account*> accList;
    int accCount;//Keeps count of the number of accounts in this list

};

#endif // ACCOUNTLIST_H
