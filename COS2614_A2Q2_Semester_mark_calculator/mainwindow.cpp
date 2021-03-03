#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(50, 50, WINDOW_WIDTH, WINDOW_HEIGHT);
    this->setWindowTitle("Launchpad");
    b = new QPushButton("Launch QDialog", this);
    b->setGeometry(WINDOW_WIDTH/2 -BUTTON_WIDTH/2 ,
                   WINDOW_HEIGHT/2 -BUTTON_HEIGHT/2 ,
                   BUTTON_WIDTH, BUTTON_HEIGHT);
    font = QFont(FONT_FAMILY, FONT_SIZE, FONT_WEIGHT, false);
    b->setFont(font);
    connect(b, SIGNAL(clicked()), this, SLOT(on_b_clicked()));
    //b->show();

}

MainWindow::~MainWindow()
{
    qDebug() << "Mainwindow destructor started";
    delete ui;
    delete b;
    delete m;
    qDebug() << "Mainwindow destructor finished";
}

void MainWindow::on_b_clicked()
{
    m = new MarkView;
    m->show();

}
