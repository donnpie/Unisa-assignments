#include "mainwindow.h"
#include "ui_mainwindow.h"

const int OLD_REFS = 10;
const int RECENT_REFS = 5;

MainWindow::MainWindow(QWidget *parent, ReferenceModel *m) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _m = m;

    //Setup QListView
    ui->tableView->setModel(_m->getModel());

    //Setup filter dropdown list
    QStringList labels;
    labels << "Author" << "Year" << "Title" << "Journal" << "Volume" << "Issue";
    ui->comboBoxSearchField->addItems(labels);

    //Connections
    connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(addHandler()));
    connect(ui->pushButtonFind, SIGNAL(clicked()), this, SLOT(findHandler()));
    //connect(ui->pushButtonNext, SIGNAL(clicked()), this, SLOT(nextHandler()));
    connect(ui->pushButtonClear, SIGNAL(clicked()), this, SLOT(clearHandler()));
    connect(ui->pushButtonRemove, SIGNAL(clicked()), this, SLOT(removeHandler()));
    //connect(ui->tableView->horizontalHeader(), SIGNAL(sectionClicked(int) ), this, SLOT(tableColumnClicked(int index))); //Wrong!!
    connect(ui->tableView->horizontalHeader(), SIGNAL(sectionClicked(int) ), this, SLOT(tableColumnClicked(int))); //Do not pass parameters when declaring connection!!!
    connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(tableCellClicked(const QModelIndex &)));
    //connect(ui->tableView->verticalHeader(), SIGNAL(sectionClicked(int) ), this, SLOT(tableRowClicked(int)));

    highlight();
}


MainWindow::~MainWindow()
{
    delete ui;
    delete _m;
    _m = nullptr;

}

/*
QPushButton *MainWindow::getbutton(QString btype)
{
    if (btype == "add")
        return ui->pushButtonAdd;
    if (btype == "find")
        return ui->pushButtonFind;
    //if (btype == "next")
    //    return ui->pushButtonNext;
    if (btype == "clear")
        return ui->pushButtonClear;
    if (btype == "remove")
        return ui->pushButtonRemove;
    else {
        return nullptr;
    }
}*/


void MainWindow::setLineEditAuthor(QString author)
{
    ui->lineEditAuthor->setText(author);
}

void MainWindow::setModel(ReferenceModel *m)
{
    _m = m;
}

void MainWindow::addHandler()
{
    //qDebug() << "The add button was pushed";
    //QMessageBox::warning(nullptr, "Error", "The add button was pushed");
    _m->getModel()->appendRow(loadUitoRef()->getStdList());

    highlight();
}

void MainWindow::findHandler()
{
    //QMessageBox::warning(nullptr, "Error", "The find button was pushed");
    //QList<QStandardItem *> QStandardItemModel::findItems(const QString &text, Qt::MatchFlags flags = Qt::MatchExactly, int column = 0) const
    QString searchTerm = ui->lineEditSearch->text();
    QString searchCategory = ui->comboBoxSearchField->currentText();
    int column = 0;
    //Column lookup:
    if (searchCategory == "Author")
    {
        column = 0;
    }
    if (searchCategory == "Year")
    {
        column = 1;
    }
    if (searchCategory == "Title")
    {
        column = 2;
    }
    if (searchCategory == "Journal")
    {
        column = 3;
    }
    if (searchCategory == "Volume")
    {
        column = 4;
    }
    if (searchCategory == "Issue")
    {
        column = 5;
    }

    //Filter
    Qt::MatchFlags flags = Qt::MatchWildcard;
    //Qt::MatchFlags flags = Qt::MatchExactly;
    QList<QStandardItem *> searchResults = _m->getModel()->findItems(searchTerm, flags, column);


    if (searchResults.isEmpty())
    {
        QMessageBox::warning(nullptr, "Warning", "No matches found");
    }
    else {

        //Make model
        QStandardItemModel *searchResultsModel = new QStandardItemModel;
        QStringList headerLabels;
        headerLabels << "Author" << "Year" << "Title" << "Journal" << "Volume" << "Issue" << "Pages";
        searchResultsModel->setHorizontalHeaderLabels(headerLabels);
        int row = 0;

        //QString resultsString = "Results include: ";
        for (int i = 0; i < searchResults.count(); i++)  //test to see if I can get some results
        {
            qDebug() << "Result " << QString::number(i+1);
            //resultsString = resultsString + " " + searchResults[i]->text();       //This works since I am able to print out the results
            qDebug() << searchResults[i]->text();
            qDebug() << "Row: " << searchResults[i]->row();
            row = searchResults[i]->row();
            QList<QStandardItem*> items;
            items << _m->getModel()->item(row, 0)->clone();
            items << _m->getModel()->item(row, 1)->clone();
            items << _m->getModel()->item(row, 2)->clone();
            items << _m->getModel()->item(row, 3)->clone();
            items << _m->getModel()->item(row, 4)->clone();
            items << _m->getModel()->item(row, 5)->clone();
            items << _m->getModel()->item(row, 6)->clone();


            qDebug() << "";
            searchResultsModel->appendRow(items);

        }


        //QMessageBox::information(nullptr, "Message", resultsString);


        //Display results
        ui->tableView->setModel(searchResultsModel);

    }







}

/*void MainWindow::nextHandler()
{
    QMessageBox::warning(nullptr, "Error", "The next button was pushed");
}*/

void MainWindow::clearHandler()
{
    //QMessageBox::warning(nullptr, "Error", "The clear button was pushed");
    ui->tableView->setModel(_m->getModel());
}

void MainWindow::removeHandler()
{
    //QMessageBox::warning(nullptr, "Error", "The remove button was pushed");


    //
    //determine if a row is selected
    QItemSelectionModel *select = ui->tableView->selectionModel();
    //QModelIndexList selectedIndexes () const
    if (!select->selectedIndexes().isEmpty())
    {
        //if row selected, ask user if he is sure he wants to remove the row
        QMessageBox::StandardButton b = QMessageBox::question(this, "Confirm", "Are you sure you want to delete this row?");
        if (b == QMessageBox::StandardButton::Yes)
        {

        //if yes, romove row
            _m->getModel()->removeRow(select->selection().indexes().first().row());
            QMessageBox::information(this, "Message", "The record was removed");

        }
        else {
            QMessageBox::information(this, "Message", "No rows were removed");
        }

    }
    else {
        //if no row selected, show popup saying so.
        QMessageBox::information(this, "Message", "No rows were selected for removal");
    }

}

void MainWindow::tableColumnClicked(int index)
{
    //void QStandardItemModel::sort(int column, Qt::SortOrder order = Qt::AscendingOrder)
    Qt::SortOrder sortOrder = ui->tableView->horizontalHeader()->sortIndicatorOrder(); //Return current sort order

    qDebug() << "sortOrder" << sortOrder;

    if (sortOrder != Qt::DescendingOrder)
        _m->getModel()->sort(index, Qt::DescendingOrder);
    else {
        _m->getModel()->sort(index, Qt::AscendingOrder);
    }



    //QMessageBox::warning(nullptr, "Error", "The table column header was clicked" + QString::number(index));
}

//void MainWindow::tableRowClicked(int row)
//{
//    //QMessageBox::warning(nullptr, "Error", "The table row header was clicked" + QString::number(row));
//}

void MainWindow::tableCellClicked(const QModelIndex &index)
{
    //QMessageBox::warning(nullptr, "Error", "The table cell was clicked" + QString::number(index.row()) + " " + QString::number(index.column()));
    //QStandardItem *QStandardItemModel::item(int row, int column = 0) const


    //copy the row to a Reference object
    Reference *r = new Reference;
    r->setAuthor(_m->getModel()->item(index.row(), 0)->text());
    r->setYear(_m->getModel()->item(index.row(), 1)->text().toInt());
    r->setTitle(_m->getModel()->item(index.row(), 2)->text());
    r->setJournal(_m->getModel()->item(index.row(), 3)->text());
    r->setVolume(_m->getModel()->item(index.row(), 4)->text().toInt());
    r->setIssue(_m->getModel()->item(index.row(), 5)->text().toInt());
    r->setPages(_m->getModel()->item(index.row(), 6)->text());

    //write the reference to the Ui
    this->loadReftoUi(r);
    delete r;


}

void MainWindow::loadReftoUi(Reference *r)
{
    ui->lineEditAuthor->setText(r->getAuthor());
    ui->spinBoxYear->setValue(r->getYear());
    ui->lineEditTitle->setText(r->getTitle());
    ui->lineEditJournal->setText(r->getJournal());
    ui->spinBoxVolume->setValue(r->getVolume());
    ui->spinBoxIssue->setValue(r->getIssue());
    ui->lineEditPages->setText(r->getPages());
}

Reference *MainWindow::loadUitoRef()
{
    Reference *r = new Reference;
    r->setAuthor(ui->lineEditAuthor->text());
    r->setYear(ui->spinBoxYear->value());
    r->setTitle(ui->lineEditTitle->text());
    r->setJournal(ui->lineEditJournal->text());
    r->setVolume(ui->spinBoxVolume->value());
    r->setIssue(ui->spinBoxIssue->value());
    r->setPages(ui->lineEditPages->text());
    return r; //NB: When will r get deleted? Dangling pointer!
}

void MainWindow::highlight()
{
    //check for highlighting

    int oldYear = QDate::currentDate().year() - OLD_REFS;
    int recentYear = QDate::currentDate().year() - RECENT_REFS;


    for (int i = 0; i < _m->getModel()->rowCount(); i++)
    {
        if (_m->getModel()->item(i, 1)->text().toInt() < oldYear)
        {

            //paint row

            for (int j = 0; j < 7; j++)
                _m->getModel()->setData(_m->getModel()->index(i, j), QBrush(QColor("red")), Qt::BackgroundRole);
                    //_m->getModel()->item(i, 1)->setData(QVariant(), Qt::BackgroundRole);
                    //model->setData(model->index(row,i,parent),brush,Qt::BackgroundRole));
        }
        if (_m->getModel()->item(i, 1)->text().toInt() > recentYear)
        {

            //paint row

            for (int j = 0; j < 7; j++)
                _m->getModel()->setData(_m->getModel()->index(i, j), QBrush(QColor("green")), Qt::BackgroundRole);
                //_m->getModel()->item(i, 1)->setData(QVariant(), Qt::BackgroundRole);
                //model->setData(model->index(row,i,parent),brush,Qt::BackgroundRole));
        }
    }

}
