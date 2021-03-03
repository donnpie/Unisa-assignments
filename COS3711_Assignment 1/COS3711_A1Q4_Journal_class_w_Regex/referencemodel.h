#ifndef REFERENCEMODEL_H
#define REFERENCEMODEL_H

#include <QStandardItem>
#include <QStandardItemModel>
#include "reference.h"
#include <QObject>
#include <QMessageBox>
#include <QDebug>
#include <QStringList>

//class ReferenceModel : public QObject
class ReferenceModel : public QStandardItemModel
{
    Q_OBJECT

public:
    ReferenceModel(QObject * parent = nullptr);
    ~ReferenceModel();

//Getters and setters**********************************************************************
    QStandardItemModel *getModel();

//Signals and Slots************************************************************************

//public slots:


//Moved here from mainwindow.h
public:
    //bool removeRows(int position, int rows, const QModelIndex &parent);



//Data members*****************************************************************************
private:
    QStandardItemModel *_m;


};

#endif // REFERENCEMODEL_H
