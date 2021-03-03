#ifndef REFERENCE_H
#define REFERENCE_H
//This class holds the data for a journal reference

#include <QString>
#include <QObject>
#include <QMessageBox>
#include <QDate>
#include <QStandardItem>
#include <QList>
#include <stdlib.h> //exit
//#include <assert.h> //cassert



class Reference : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString author READ getAuthor WRITE setAuthor)
    Q_PROPERTY(int year READ getYear WRITE setYear)
    Q_PROPERTY(QString title READ getTitle WRITE setTitle)
    Q_PROPERTY(QString journal READ getJournal WRITE setJournal)
    Q_PROPERTY(int volume READ getVolume WRITE setVolume)
    Q_PROPERTY(int issue READ getIssue WRITE setIssue)
    Q_PROPERTY(QString pages READ getPages WRITE setPages)

    //Contructors and destructors**************************************************************
public:
    Reference(QObject * parent = nullptr);
    Reference(QObject * parent, QString author, int year, QString title, QString journal, int volume, int issue, QString pages);



    //Getters and setters**********************************************************************
    QString getAuthor();
    int getYear();
    QString getTitle();
    QString getJournal();
    int getVolume();
    int getIssue();
    QString getPages();

    void setAuthor(QString author);
    void setYear(int year);
    void setTitle(QString title);
    void setJournal(QString journal);
    void setVolume(int volume);
    void setIssue(int issue);
    void setPages(QString pages);

    //Overloaded operators*********************************************************************

    //Signals and Slots************************************************************************

    //Member functions*************************************************************************

public:
    int getCurrentYear();
    //void QStandardItemModel::appendRow(const QList<QStandardItem *> &items)
    QList<QStandardItem *> getStdList();

    //Data members*****************************************************************************
private:
    QString _author;
    int _year;
    QString _title;
    QString _journal;
    int _volume;
    int _issue;
    QString _pages;


};

#endif // REFERENCE_H
