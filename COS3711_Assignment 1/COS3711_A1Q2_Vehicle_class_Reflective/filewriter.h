#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QObject>
#include <QObjectList>
#include <QFile>
#include <QTextStream>
#include <QMetaObject>
#include <stdlib.h>
#include "vehicle.h"
#include "passengervehicle.h"
#include "transportvehicle.h"

class FileWriter : public QObject
{
    Q_OBJECT
//Contructors and destructors**************************************************************
public:
    explicit FileWriter(QObject *parent = nullptr);
    FileWriter(QObject *parent = nullptr, QObjectList list = QObjectList(), QString filename = "");


//Getters and setters**********************************************************************
//Overloaded operators*********************************************************************
//Signals and Slots************************************************************************
signals:

public slots:


//Member functions*************************************************************************
public:
    int write();

//Data members*****************************************************************************
private:
    QObjectList _list;
    QString _filename;
};

#endif // FILEWRITER_H



