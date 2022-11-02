#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleValidator>
#include <QVector>
#include <qcustomplot.h>
#include <limits.h>
#include <math.h>

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
    

private:
    Ui::MainWindow *ui;
    QString expr, x_value = "0";
    /* double start = 0, stop = 0, step = 1; */
    QDoubleValidator x_valid;
    QVector<double> X, Y;
    x_x x_info[1];


private slots:
    void add_char();
    void on_pushButton_clear_clicked();
    void on_pushButton_calc_clicked();
    void on_pushButton_clicked();
    void on_x_val_edit_editingFinished();
    void on_pushButton_del_clicked();
    void on_lineEdit_start_editingFinished();
    void on_lineEdit_stop_editingFinished();
    void on_lineEdit_step_editingFinished();
    void on_pushButton_graph_clicked();
    void on_pushButton_plot_clear_clicked();
};
#endif // MAINWINDOW_H
