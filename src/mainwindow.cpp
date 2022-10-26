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
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_diff->setCheckable(true);
    ui->pushButton_div->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);

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

    expr += but->text();
}

void MainWindow::on_pushButton_dot_clicked()
{

        expr += ".";
}

void MainWindow::operations()
{
    QPushButton *but = (QPushButton*)sender();
    double all_numbers;
    QString new_label;

    if(but->text() == "+/-")
    all_numbers = (ui->result->text()).toDouble();
    all_numbers *= -1;
    new_label = QString::number(all_numbers, 'g', 15);
    ui->result->setText(new_label);
}
void MainWindow::on_pushButton_clear_clicked()
{
//    double res = 0;
//    char inp[] = "22+25";
//    char out[50] = {0};
//    char out1[50] = {0};
//    printf("start =%s|\n", out);

//    get_short_func(inp, out);
//    find_unary(out);
//    printf("start =%s|\n", out);
//    rpn(out, out1);
//    printf("out =%s|\n", out1);
//    calc(out1, &res);
//    pair_paren(inp);
//    printf("res %lf", res);

//    QString new_label = QString::number(res);
//    ui->result->setText(new_label);
}


void MainWindow::on_pushButton_calc_clicked()
{
    QPushButton *but = (QPushButton*)sender();
    /* printf("%s", expr); */
    ui->result->setText(expr);
}

void MainWindow::math_operations()
{
    QPushButton *but = (QPushButton*)sender();





}
