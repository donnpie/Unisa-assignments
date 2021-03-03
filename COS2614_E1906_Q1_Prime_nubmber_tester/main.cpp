#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>

bool isPrime(int n)
{
    qDebug() << "Testing " << n << '\n';
    if (n == 1 || n == 2 || n == 3)
    {
        qDebug() << n << " is prime" << '\n';
        return true;
    }
    int mid = n/2;
    qDebug() << "mid value is: " << mid << '\n';
    for (int i = 2; i <= mid; ++i)
    {
        qDebug() << "i = " << i << '\n';
        if (n%i == 0)
        {
            qDebug() << n << " is not prime" << '\n';
            return false;
        }
    }
    qDebug() << n << " is prime" << '\n';
    return true;
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int answer = 0;
    int result;
    QString boolResult;

    do {
        result = QInputDialog::getInt(nullptr, "Input", "Enter a number");
        if (isPrime(result))
            boolResult = result + " is a prime number";
        else
            boolResult = result + " is not a prime number";
        answer = QMessageBox::question(nullptr, "Prime numbers", boolResult + "\nCheck another integer?");
        //This works, but the message box is too small to display the entire message

        //msg.setStyleSheet("QLabel{min-width: 700px;}");

    } while (answer == QMessageBox::Yes);

    return 0;
//    for (int i = 1; i < 10; i++)
//        isPrime(i);
//
}
