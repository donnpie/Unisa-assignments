#include "accountlist.h"



AccountList::AccountList()
{
    accCount = 0;
}

AccountList::~AccountList()
{
    qDebug() << "Destroying account list...";
    Account * accPtr; //pointer used to loop through the container
    foreach (accPtr, accList)
    {
        if (accPtr != nullptr)
        {
            qDebug() << "\tDestroying account" << accPtr->getAccNum();
            delete accPtr;
        }
    }
}

bool AccountList::addAccount(Account *a)
{
    Account * accPtr = findAccount(a->getAccNum());
    if (accPtr == nullptr)
    {
        //qDebug() << "if clause in addAccount was triggered";
        accList.append(a);
        accCount++;
        qDebug() << "\tAccount " << a->getAccNum() << " was added successfully";
        return true; //Return true if a match is found
    }
    qDebug() << "\tAccount was not added";
    return false; //Return false if no match was found
}

double AccountList::totalBalance()
{
    double sum = 0;
    qDebug() << "Calculating total balance...";
    Account * accPtr; //pointer used to loop through the container
    foreach (accPtr, accList)
    {
        sum += accPtr->getBalance();
    }
    qDebug() << "\tThe total balance is: " << sum;
    return sum;
}

void AccountList::doInterestCalculations()
{
    qDebug() << "Doing interest calculations for all accounts...";
    Account * accPtr; //pointer used to loop through the container
    foreach (accPtr, accList)
    {
        accPtr->calcInterest();
        accPtr->toString();
    }
    qDebug() << "...Interest calculations done";
}

QString AccountList::toString()
{
    qDebug() << "Printing account data for all accounts...";
    Account * accPtr; //pointer used to loop through the container
    foreach (accPtr, accList)
    {
        qDebug().noquote() << accPtr->toString();
    }
    qDebug() << "...Done";
    return "";
}

QStringList AccountList::CustomersWithHighestPoints()
{
    qDebug() << "Finding customers with highest points...";
    int max = 0;
    QStringList l;
    SavingsAccount *s;
    for (int i = 0; i < accList.size(); i++)
    {
        if (accList[i]->getType() == "Savings")
        {
            //qDebug() << "accList[i] type is Savings";
            if ((s = dynamic_cast<SavingsAccount*>(accList[i])))
            {
                //qDebug() << "Dynamic cast worked!";
                l.append(s->getCustName());
                if (s->getPoints() > max)
                {
                    max = s->getPoints();
                }
            }
        }
    }
    l << "Max points: ";
    l << QString::number(max);
    //qDebug() << "...Done";
    return l;
}

void AccountList::printTransactionsForAllAccounts()
{
    qDebug() << "Printing transaction data for all accounts...";
    for (int i = 0; i < accList.size(); i++)
    {
        qDebug() << "i: " << i;
        accList[i]->printTransactions();
    }
    qDebug() << "...Done";
}

Account *AccountList::findAccount(QString an)
{
    Account * accPtr; //pointer used to loop through the container
    qDebug() << "Checking if account already exists...";
    foreach (accPtr, accList)
    {
        if (accPtr->getAccNum()==an)
        {
            qDebug() << "\tA matching account was found";
            return accPtr; //if found, return a pointer to the account
        }
    }
    qDebug() << "\tNo matching account was found";
    return nullptr;//if not found, return the null pointer

}
