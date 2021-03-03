#include "savingsaccount.h"

SavingsAccount::SavingsAccount() :
    Account ("", "", 0.0, "Savings"), points(0) {}

SavingsAccount::SavingsAccount(QString cn, QString an, double ir) :
    Account (cn, an, ir, "Savings"), points(0) {}

SavingsAccount &SavingsAccount::operator=(const SavingsAccount &other)
{
    Account::operator=(other);  //Use the assignment operator of the base class
        //to populate the private members of the base class
    this->points = other.points;
    return *this;
}

SavingsAccount &SavingsAccount::operator=(const Account &other)
{
    Account::operator=(other);
    this->points = 0;
    return *this;
}

void SavingsAccount::transaction(double amt)
{
    qDebug() << "Processing transaction for " << this->getAccNum() << "...";
    if (amt > 0)
    {
        Transaction  * t = new Transaction("Deposit", amt);
        transactions.append(*t);
        balance += amt;
    }
    else {
        if (-amt > balance)
        {
            qDebug() << "Insufficient funds. Available balance: " << balance;
            return;
        }
        Transaction  * t = new Transaction("Withdrawal", amt);
        transactions.append(*t);
        balance += amt;
    }
    //How to destroy pointer t???
    qDebug() << "...Done";
}

void SavingsAccount::calcInterest()
{
    qDebug() << "Processing interest transaction for " << this->getAccNum() << "...";
    double interest = balance * getInterestRate()/12; //calculate the interest
    double p = interest / 1;
    if (p > SavingsAccount::minIntEarnedForPoints)
    {
        points += p;
    }
    balance += interest;
    Transaction  * t = new Transaction("Interest", interest);
    transactions.append(*t);
    qDebug() << "...Done";
}

int SavingsAccount::getPoints()
{
    return points;
}

QString SavingsAccount::toString()
{
    QString str =
    "Account details:\n"
    "\tCustomer name: " + getCustName() + "\n"
    "\tAccount number: " + getAccNum() + "\n"
    "\tInterest rate: " + QString::number(getInterestRate()*100) + "%\n"
    "\tAccount type: " + getType() + "\n"
    "\tBalance: " + QString::number(balance) + "\n"
    "\tPoints: " +  QString::number(points) + "\n";
    return str;

}
