#include "account.h"

Account::Account() :
    custName(""), accNum(""), interestRate(0.0), balance(0.0)
{

}

Account::Account(QString cn, QString an, double ir, QString ty) :
    custName(cn), accNum(an), interestRate(ir), type(ty), balance(0.0)
{
    qDebug() << "New account created successfully with account number " << this->getAccNum();
}

Account &Account::operator=(const Account &other)
{
    this->type = other.type;
    this->accNum = other.accNum;
    this->balance = other.balance;
    this->custName = other.custName;
    this->interestRate = other.interestRate;
    this->transactions = other.transactions;
    return *this;
}

Account::~Account()
{

}

QString Account::getCustName()
{
    return custName;
}

QString Account::getAccNum()
{
    return accNum;
}

double Account::getBalance()
{
    return balance;
}

QList<Transaction> Account::getTransaction()
{
    return transactions;
}

void Account::printTransactions()
{
    qDebug() << "Printing transactions for account " << this->getAccNum();
    for (int i = 0; i < transactions.size(); i++)
    {
        qDebug().noquote() << transactions[i].toString();
    }
}

QString Account::toString()
{
    QString str =
    "Account details:\n"
    "\tCustomer name: " + custName + "\n"
    "\tAccount number: " + accNum + "\n"
    "\tInterest rate: " + QString::number(interestRate*100) + "%\n"
    "\tAccount type: " + type + "\n"
    "\tBalance: " + QString::number(balance);
    return str;
}

QString Account::getType()
{
    return type;
}

double Account::getInterestRate()
{
    return interestRate;
}
