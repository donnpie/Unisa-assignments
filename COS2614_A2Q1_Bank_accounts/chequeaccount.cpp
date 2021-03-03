#include "chequeaccount.h"

ChequeAccount::ChequeAccount() :
    Account("", "", 0.0, "Cheque"), overdraft(0.0) {}

ChequeAccount::ChequeAccount(QString cn, QString an, double ir, double od) :
    Account(cn, an, ir, "Cheque"), overdraft(od) {}

void ChequeAccount::transaction(double amt)
{
    qDebug() << "Processing transaction for " << this->getAccNum() << "...";
    if (amt > 0)
    {
        Transaction  * t = new Transaction("Deposit", amt);
        transactions.append(*t);
        balance += amt;
    }
    else {
        if (-amt > balance + overdraft)
        {
            qDebug() << "Insufficient funds. Available balance: " << balance + overdraft;
            return;
        }
        Transaction  * t = new Transaction("Withdrawal", amt);
        transactions.append(*t);
        balance += amt;
    }
    //How to destroy pointer t???
    qDebug() << "...Done";
}

void ChequeAccount::calcInterest()
{
    qDebug() << "Processing interest transaction for "<< this->getAccNum() << "...";
    double interest = balance * getInterestRate()/12; //calculate the interest
    balance += interest;
    Transaction  * t = new Transaction("Interest", interest);
    transactions.append(*t);
    qDebug() << "...Done";
}

QString ChequeAccount::toString()
{
    QString str =
    "Account details:\n"
    "\tCustomer name: " + getCustName() + "\n"
    "\tAccount number: " + getAccNum() + "\n"
    "\tInterest rate: " + QString::number(getInterestRate()*100) + "%\n"
    "\tAccount type: " + getType() + "\n"
    "\tBalance: " + QString::number(balance) + "\n"
    "\tOverdraft: " +  QString::number(overdraft) + "\n";
    return str;
}
