#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExp>
#include <QValidator>
#include "reference.h"
#include "referencemodel.h"
#include "QMessageBox"
#include "QDebug"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
//Contructors and destructors**************************************************************
public:
    explicit MainWindow(QWidget *parent = nullptr);
    MainWindow(QWidget *parent, ReferenceModel *m);
    ~MainWindow();

//Getters**********************************************************************************
    //QPushButton *getbutton(QString btype);

//Setters**********************************************************************************
    void setLineEditAuthor(QString author);
    void setModel(ReferenceModel* m);


public slots:
    void addHandler();
    void findHandler();
    //void nextHandler();
    void clearHandler();
    void removeHandler();
    void tableColumnClicked(int index);
    //void tableRowClicked(int);
    void tableCellClicked(const QModelIndex &index);
    void validatorChanged();




//Member functions*************************************************************************
public:
    void loadReftoUi(Reference * r);
    Reference *loadUitoRef();
    void highlight();
    //QList<QStandardItem *> QStandardItemModel::findItems(const QString &text, Qt::MatchFlags flags = Qt::MatchExactly, int column = 0) const


    //bool removeRows(int position, int rows, const QModelIndex &parent);


//Data members*****************************************************************************
private:
    Ui::MainWindow *ui;
    ReferenceModel *_m;
};

#endif // MAINWINDOW_H
