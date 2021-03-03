#include "referencemodel.h"


ReferenceModel::ReferenceModel(QObject *parent)
{
    this->setParent(parent);

    QStringList headerLabels;
    headerLabels << "Author" << "Year" << "Title" << "Journal" << "Volume" << "Issue" << "Pages";

    _m = new QStandardItemModel;
    _m->setHorizontalHeaderLabels(headerLabels);
    //_m->setVerticalHeaderLabels(headerLabels);

    //Add a few rows of data
    QList<QStandardItem*> l1;
    l1 << new QStandardItem("Flash");
    l1 << new QStandardItem(QString::number(2019));
    l1 << new QStandardItem("A quicky");
    l1 << new QStandardItem("Journal1");
    l1 << new QStandardItem(QString::number(1));
    l1 << new QStandardItem(QString::number(1));
    l1 << new QStandardItem("12-24");
    _m->appendRow(l1);

    QList<QStandardItem*> l2;
    l2 << new QStandardItem("Wonder Woman");
    l2 << new QStandardItem(QString::number(2015));
    l2 << new QStandardItem("Bullet proof");
    l2 << new QStandardItem("Journal2");
    l2 << new QStandardItem(QString::number(2));
    l2 << new QStandardItem(QString::number(2));
    l2 << new QStandardItem("12-24");
    _m->appendRow(l2);

    QList<QStandardItem*> l3;
    l3 << new QStandardItem("Aquaman");
    l3 << new QStandardItem(QString::number(2009));
    l3 << new QStandardItem("Wet Willy");
    l3 << new QStandardItem("Journal3");
    l3 << new QStandardItem(QString::number(3));
    l3 << new QStandardItem(QString::number(3));
    l3 << new QStandardItem("12-24");
    _m->appendRow(l3);

    //Reference * defaultRef = new Reference(nullptr, "Author", 2019, "Title", "Journal", 2, 2, "12-24");
    //_w.loadReftoUi(defaultRef);
    //_w.show();
    //delete defaultRef;
    //_w.ui->lineEditAuthor->setText("Test");
    //_w.setLineEditAuthor("Test");


}

ReferenceModel::~ReferenceModel()
{
    delete _m; _m = nullptr;
}

QStandardItemModel *ReferenceModel::getModel()
{
    return _m;
}

/*
bool ReferenceModel::removeRows(int position, int rows, const QModelIndex &parent)
//https://doc.qt.io/qt-5/model-view-programming.html#inserting-and-removing-rows
{
    //_m->getModel()->beginRemoveRows(QModelIndex(), position, position+rows-1);
    beginRemoveRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row) {
        stringList.removeAt(position);
    }

    endRemoveRows();
    return true;
}
*/




