#include "transaction.h"

Transaction::Transaction() : type(""), amount(0) {}

Transaction::Transaction(QString ty, double amt) :
    type(ty), amount(amt) {}

QString Transaction::toString()
{
    QString str =
    "Transaction details:\n"
    "\tType type: " + type + "\n"
    "\tAmount: " +  QString::number(amount) + "\n";
    return str;
}

double Transaction::getAmount()
{
    return  amount;
}
