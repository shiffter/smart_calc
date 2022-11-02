#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>


/* QString expr; */


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), x_valid(-MAXFLOAT, MAXFLOAT, 16, this)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_diff,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_calc,SIGNAL(clicked()),this,SLOT(calc()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_acos,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_dot,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_asin,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_x,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_tan,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_atan,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_pow,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_log,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_mod,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_close_brace,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_open_brace,SIGNAL(clicked()),this,SLOT(add_char()));

    x_valid.setNotation(QDoubleValidator::StandardNotation);
            ui->x_val_edit->setValidator(&x_valid);
    ui->graph->yAxis->setRange(-20, 20);
    ui->graph->xAxis->setRange(-20, 20);
  
        /* X.push_back(1.3); */
        /* Y.push_back(2.2); */
        /* X.push_back(2.4); */
        /* Y.push_back(3.3); */

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::about(this, "Header", "How can i help u ?");
}

void MainWindow::add_char()
{
    QPushButton *but = (QPushButton*)sender();
    expr.append(but->text());
    ui->result->setText(expr);
}


void MainWindow::on_pushButton_clear_clicked()
{
  expr.clear();
  ui->result->setText("0");
}


void MainWindow::on_pushButton_calc_clicked()
{   
    double res = 0.0;
    int flag = 0;
    QPushButton *but = (QPushButton*)sender();
    x_x x_info[1];
    if (expr.isEmpty())
      ui->result->setText("0");
    else {
      if (expr.contains("x"))
      expr.replace("x", x_value);
      QByteArray ba_input = expr.toLocal8Bit();
      char* c_input = ba_input.data();
      double res = 0;
      flag = common_calc(c_input, x_info, &res);
      if (!flag) {
        QString result = QString::number(res);
        ui->result->setText(result);
        expr.clear();
        expr.append(result);
      } else {
        ui->result->setText("err");
      }
    }
}


void MainWindow::on_x_val_edit_editingFinished()
{
    x_value = ui->x_val_edit->text();
//    expr.replace("x", ui->x_val_edit->text());
    ui->result->setText(expr);
}



void MainWindow::on_pushButton_del_clicked()
{
    expr.chop(1);
    ui->result->setText(expr);
}


void MainWindow::on_lineEdit_start_editingFinished()
{
    x_info->start = ui->lineEdit_start->text().toDouble();
}


void MainWindow::on_lineEdit_stop_editingFinished()
{
    x_info->stop = ui->lineEdit_stop->text().toDouble();
}


void MainWindow::on_lineEdit_step_editingFinished()
{
    x_info->step = ui->lineEdit_step->text().toDouble();
}


void MainWindow::on_pushButton_graph_clicked()
{
    /* int flag = 0; */
    QByteArray ba_rpn = expr.toLocal8Bit();
    char out_rpn[200] = {0};

    char out_rpn1[200] = {0};
    char* c_rpn = ba_rpn.data();
    double tmp = x_info->start;
    get_short_func(c_rpn, out_rpn);
    find_unary(out_rpn);
    rpn(out_rpn, out_rpn1);
    printf("start %lf, stop %lf, step %lf\n", x_info->start, x_info->stop, x_info->step);
    int j = 0,  flag = 0;

    for (double i = x_info->start; !flag && i <= x_info->stop; i+=x_info->step, j++){
        x_info->start = i;
        double res = 0; 
        flag = calc(out_rpn1, &res, x_info);
        X.push_back(i);
        Y.push_back(res);
        /* printf("cords %lf %lf\n", i, res); */
        }
    if (!flag){
      x_info->start = tmp;
      ui->graph->clearGraphs();
      ui->graph->addGraph();
      ui->graph->graph(0)->addData(X, Y);
      ui->graph->replot();
      X.clear(); Y.clear();
    } else {
      ui->result->setText("err");
    }
}



void MainWindow::on_pushButton_plot_clear_clicked()
{
    ui->graph->clearGraphs();
    ui->graph->replot();
    X.clear();
    Y.clear();
}
