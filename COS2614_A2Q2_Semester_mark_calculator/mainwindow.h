#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFont>
#include <QDebug>
#include "markview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_b_clicked();

private:
    Ui::MainWindow *ui;
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    const int BUTTON_WIDTH = 200;
    const int BUTTON_HEIGHT = 50;
    const int FONT_SIZE = 9;
    const int FONT_WEIGHT =1;
    const QString FONT_FAMILY = "MS Shell Dlg 2";
    QPushButton *b;
    QFont font;
    MarkView *m;
};

#endif // MAINWINDOW_H
