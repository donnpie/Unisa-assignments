#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QString>


class Transaction
{
public:
    Transaction();
    Transaction(QString ty, double amt);
    QString toString();
    QString getType();
    double getAmount();
private:
    QString type;
    double amount;
};

#endif // TRANSACTION_H
