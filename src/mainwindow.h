#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

extern "C" {
#include "c_source/smart_calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

private slots:
    void add_char();
    void on_pushButton_clear_clicked();
    void on_pushButton_calc_clicked();
    void on_lineEdit_returnPressed();
};
#endif // MAINWINDOW_H
