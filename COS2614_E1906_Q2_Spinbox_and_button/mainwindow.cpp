#include "mainwindow.h"
#include "ui_mainwindow.h"

//MainWindow::MainWindow(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::MainWindow)



MainWindow::MainWindow()
{
    //ui->setupUi(this);
    QLabel* amountLabel = new QLabel("Amount: ", this);

    amountInput = new QSpinBox(this);
    amountInput->setMinimum(1);
    amountInput->setMaximum(1000);

    QLabel* percentLabel = new QLabel("Percentage: ", this);

    percentInput= new QSpinBox(this);
    percentInput->setMinimum(1);
    percentInput->setMaximum(100);

    QPushButton* calculate = new QPushButton("Calculate", this);

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(amountLabel, 0, 0);
    layout->addWidget(percentLabel, 1, 0);
    layout->addWidget(amountInput, 0, 1);
    layout->addWidget(percentInput, 1, 1);
    layout->addWidget(calculate, 2, 1);

    this->setLayout(layout);
    this->setWindowTitle("Demo dialog");

    connect(calculate, SIGNAL(clicked()), this, SLOT(getResult()));


}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::getResult()
{
    double answer = percentInput->value()*amountInput->value()/100;
    QMessageBox::information(this, "Result", QString::number(answer));
}
