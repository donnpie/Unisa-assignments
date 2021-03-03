#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog //QMainWindow
{
    Q_OBJECT

public:
    //explicit MainWindow(QWidget *parent = nullptr);
    explicit MainWindow();
    QSpinBox* amountInput;
    QSpinBox* percentInput;
    ~MainWindow();
public slots:
    void getResult();

private:
    //Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
