#include <QCoreApplication>
#include <iostream>
#include "stock.h"
#include "confectionery.h"
#include "readingmaterial.h"
#include "stockfactory.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Test the stock class
    //Stock *stockItemPtr = new Stock; //This will not work since the class is pure virtual

    //use the factory to create new stock objects
    StockFactory f;
    Stock *conf1 = f.createStock("Confectionery");
    std::cout << conf1->toString().toStdString();
    Stock *conf2 = f.createConfectionery("Cake", 12, 105);
    std::cout << conf2->toString().toStdString();
    Stock *conf3 = f.createStock("Confectionery", "pastry", 13, 106);
    std::cout << conf3->toString().toStdString();

    Stock *read = f.createStock("ReadingMaterial");
    std::cout << read->toString().toStdString();
    Stock *read2 = f.createReadingMaterial("People Magazine", 13, "Weekly");
    std::cout << read2->toString().toStdString();
    Stock *read3 = f.createStock("ReadingMaterial", "Car Magazine", 14, "Monthly");
    std::cout << read3->toString().toStdString();


    return a.exec();
}
