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
    /* connect(ui->pushButton_unary,SIGNAL(clicked()),this,SLOT(add_char())); */
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_diff,SIGNAL(clicked()),this,SLOT(add_char()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(add_char()));
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
      res = common_calc(c_input, x_info);
      QString result = QString::number(res);
      ui->result->setText(result);
      expr.clear();
      expr.append(result);
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
    start = ui->lineEdit_start->text().toDouble();
}


void MainWindow::on_lineEdit_stop_editingFinished()
{
    stop = ui->lineEdit_stop->text().toDouble();
}


void MainWindow::on_lineEdit_step_editingFinished()
{
    step = ui->lineEdit_step->text().toDouble();
}


void MainWindow::on_pushButton_graph_clicked()
{
    QByteArray ba_rpn = expr.toLocal8Bit();
    char out_rpn[200] = {0};
    char* c_rpn = ba_rpn.data();
    rpn(c_rpn, out_rpn);
    x_x x_inform[1];
    printf("start %lf, stop %lf, step %lf\n", start, stop, step);
    int j = 0;
    for (double i = start; i < stop; i+=step, j++){
//        printf("start %lf\n", i);
        x_inform->start = i;
        double res = calc(out_rpn, &res, x_inform);
        x_inform->x_val[j] = i;
        x_inform->y_val[j] = res;
        printf("cords %lf %lf, res %lf \n", x_inform->x_val[j], x_inform->y_val[j], res);
        }
}

