#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>


QString expr;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
    if (expr.isEmpty())
      ui->result->setText("0");
    else {
     QByteArray ba_input = expr.toLocal8Bit();
    /* QString out = "", rpn_s = ""; */
    /* QByteArray ba_out = out.toLocal8Bit(); */
    /* QByteArray ba_rpn_s = rpn_s.toLocal8Bit(); */
    
    char* c_input = ba_input.data();
    /* char* c_out = ba_out.data(); */
    /* char* c_rpn_s = ba_rpn_s.data(); */

    /* printf("inp %s\n", c_input); */
    /* get_short_func(c_input, c_out); */
    /* find_unary(c_out); */

    /* printf("norm_str %s\n", c_out); */
    /* rpn(c_out, c_rpn_s); */
    
    /* printf("rpn_s %s\n", c_rpn_s); */

    double res = 0;
      res = common_calc(c_input);
      QString result = QString::number(res);
      ui->result->setText(result);
      expr.clear();
      expr.append(result);

 
    /* expr = result; */

    }
 }

void MainWindow::on_lineEdit_returnPressed()
{

}

