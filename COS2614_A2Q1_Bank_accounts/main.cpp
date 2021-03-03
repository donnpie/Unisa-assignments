#include <QCoreApplication>
#include "accountlist.h"
#include "chequeaccount.h"
#include "savingsaccount.h"
#include <QtDebug>

double SavingsAccount::minIntEarnedForPoints = 5; //Where to define the static member?

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AccountList *lst = new AccountList();
    QStringList names = {"John Wick", "Babayaga", "Winston", "Iosef Tarasov", "Vigo Tarasov", "Ms Perkins"};
    QStringList numbers = {"00001", "11111", "22222", "33333", "44444", "55555"};
    ChequeAccount *c;
    SavingsAccount *s;

    //Test cheque account - create 3 new accounts
    for (int i = 0; i < 3; i++)
    {
        c = new ChequeAccount(names[i], numbers[i], 0.05, 1000);
        //qDebug().noquote() << c.Account::toString(); //This calls the function in the base class
        //qDebug().noquote() << c->toString(); //This calls the function in the derived class
        c->transaction(-100);
        //qDebug().noquote() << c->toString();
        c->calcInterest();
        //qDebug().noquote() << c->toString();
        c->transaction(-1000);
        //qDebug().noquote() << c->toString();
        c->transaction(500);
        //qDebug().noquote() << c->toString();
        //c->printTransactions();
        lst->addAccount(c); //Add account to account list
        lst->addAccount(c); //Try to add c again: does not allow c to be added again
    }

    //Test savings account - create 3 new accounts
    for (int i = 3; i < 6; i++)
    {
        s = new SavingsAccount(names[i], numbers[i], 0.1);
        //qDebug().noquote() << s->toString(); //This calls the function in the derived class
        s->transaction(-2000);
        //qDebug().noquote() << s->toString();
        s->transaction(1000);
        //qDebug().noquote() << s->toString();
        s->calcInterest();
        //qDebug().noquote() << s->toString();
        s->transaction(-50);
        //qDebug().noquote() << s->toString();
        qDebug() << "Create clone of savings account:";

        //test the assignment operator
        //SavingsAccount * s2 = s;
        //qDebug().noquote() << s2->toString();
        //delete s2;

        lst->addAccount(s); //Add account to account list
    }

    lst->totalBalance();
    lst->doInterestCalculations();
    lst->toString();
    lst->printTransactionsForAllAccounts();
    QStringList l = lst->CustomersWithHighestPoints();
    QString str;
    foreach (str, l)
    {
        qDebug() << str;
    }


    //delete c;
    //delete s;

    delete  lst;//Delete the account list.
        //The account list destructor will delete all the accounts



    return a.exec();
}
