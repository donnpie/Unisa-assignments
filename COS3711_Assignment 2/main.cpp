#include <QCoreApplication>
#include <iostream>
#include "stock.h"
#include "confectionery.h"
#include "readingmaterial.h"
#include "stockfactory.h"
#include "stocklist.h"
#include <iostream>
#include <cstring>
#include "xmlwriter.h"
#include "xmlhandler.h"
#include "xmlreader.h"


void printStockList(QVector<Stock*> &list)
{
    for (int i = 0; i < list.count(); i++)
    {
        std::cout << list[i]->toString().toStdString();
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Test the stock class
    //Stock *stockItemPtr = new Stock; //This will not work since the class is pure virtual

    std::cout << "*****************************************************************\n";
    std::cout << "Use the factory to create new stock objects:\n";

    //use the factory to create new stock objects
    StockFactory f;

    Stock *conf1 = f.createStock("Confectionery");
    std::cout << conf1->toString().toStdString();
    Stock *conf2 = f.createConfectionery("Cake", 12, 105);
    std::cout << conf2->toString().toStdString();
    Stock *conf3 = f.createStock("Confectionery", "pastry", 13, 106);
    std::cout << conf3->toString().toStdString();

    Stock *read1 = f.createStock("ReadingMaterial");
    std::cout << read1->toString().toStdString();
    Stock *read2 = f.createReadingMaterial("People Magazine", 13, "Weekly");
    std::cout << read2->toString().toStdString();
    Stock *read3 = f.createStock("ReadingMaterial", "Car Magazine", 14, "Monthly");
    std::cout << read3->toString().toStdString();

    std::cout << "*****************************************************************\n";
    std::cout << "Instantiate the singleton:\n";

    //Instantiate the singleton
    StockList *stockList = StockList::getInstance();
    std::cout << "stockList address in memory: " << stockList << "\n";
    //try to declare another instance of StockList
    StockList *stockList2 = StockList::getInstance();
    std::cout << "stockList address in memory: " << stockList2 << "\n";

    std::cout << "*****************************************************************\n";
    std::cout << "Add items to the stock list:\n";

    //Add items to the stock list
    stockList->addStock(conf1);
    stockList->addStock(conf2);
    stockList->addStock(conf3);
    stockList->addStock(read1);
    stockList->addStock(read2);
    stockList->addStock(read3);

    std::cout << "*****************************************************************\n";
    std::cout << "Get the Confectionery and ReadinMaterial lists and write to xml:\n";

    //Get the Confectionery and ReadinMaterial lists
    QVector<Stock*> confList = stockList->getList("Confectionery");
    printStockList(confList);
    QVector<Stock*> readList = stockList->getList("ReadingMaterial");
    printStockList(readList);

    //Write to xml
    QString fileName = "StockItems.xml";
    XmlWriter writer(&a, stockList, fileName);
    writer.writeToFile();

    std::cout << "*****************************************************************\n";
    std::cout << "Read from xml:\n";

    //Read from xml
    XmlHandler handler;                     //Create xml handler object
    XmlReader reader(fileName, handler);    //Create reader object that takes the file name and handler as as arguments
                                            //and also parses the file

    //Print out the content of the file
    QVector<Stock*> list = handler.getStockList();
    printStockList(list);

    std::cout << "*****************************************************************\n";
    std::cout << "Add data in xml file to the stock list:\n";

    //Add to the stock list
    stockList->appendStockList(list);

    std::cout << "*****************************************************************\n";
    std::cout << "Print the full list:\n";

    //Print the full list
    confList = stockList->getList("Confectionery");
    printStockList(confList);
    readList = stockList->getList("ReadingMaterial");
    printStockList(readList);




    return a.exec();
}
