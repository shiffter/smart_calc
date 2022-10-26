/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *result;
    QPushButton *pushButton_unary;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_div;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_mult;
    QPushButton *pushButton_9;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_1;
    QPushButton *pushButton_diff;
    QPushButton *pushButton_3;
    QPushButton *pushButton_0;
    QPushButton *pushButton_calc;
    QPushButton *pushButton_dot;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(551, 550);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        result = new QLabel(centralwidget);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(30, 210, 201, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        font.setKerning(false);
        result->setFont(font);
        result->setStyleSheet(QString::fromUtf8("Qlabel {\n"
" qproperty-alignment: 'AlignVCenter | AalignRight';\n"
" border: 1px solid gray;\n"
"}\n"
"\n"
"bacground-color : gray;"));
        pushButton_unary = new QPushButton(centralwidget);
        pushButton_unary->setObjectName(QString::fromUtf8("pushButton_unary"));
        pushButton_unary->setGeometry(QRect(80, 250, 51, 51));
        pushButton_unary->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(93, 93, 93);\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(130, 250, 51, 51));
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(93, 93, 93);\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(30, 250, 51, 51));
        pushButton_clear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(93, 93, 93);\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_div = new QPushButton(centralwidget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setGeometry(QRect(180, 250, 51, 51));
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 151, 57);\n"
"	color: white;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(80, 300, 51, 51));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2:0, y2:1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(30, 300, 51, 51));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2:0, y2:1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_mult = new QPushButton(centralwidget);
        pushButton_mult->setObjectName(QString::fromUtf8("pushButton_mult"));
        pushButton_mult->setGeometry(QRect(180, 300, 51, 51));
        pushButton_mult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 151, 57);\n"
"	color: white;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(130, 300, 51, 51));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2:0, y2:1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(80, 350, 51, 51));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2:0, y2:1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 350, 51, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2:0, y2:1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setGeometry(QRect(180, 350, 51, 51));
        pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 151, 57);\n"
"	color: white;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(130, 350, 51, 51));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2:0, y2:1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 400, 51, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2:0, y2:1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(30, 400, 51, 51));
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2:0, y2:1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_diff = new QPushButton(centralwidget);
        pushButton_diff->setObjectName(QString::fromUtf8("pushButton_diff"));
        pushButton_diff->setGeometry(QRect(180, 400, 51, 51));
        pushButton_diff->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 151, 57);\n"
"	color: white;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 400, 51, 51));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2:0, y2:1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(30, 450, 101, 51));
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2:0, y2:1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_calc = new QPushButton(centralwidget);
        pushButton_calc->setObjectName(QString::fromUtf8("pushButton_calc"));
        pushButton_calc->setGeometry(QRect(180, 450, 51, 51));
        pushButton_calc->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 151, 57);\n"
"	color: white;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setGeometry(QRect(130, 450, 51, 51));
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(93, 93, 93);\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        result->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_unary->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_diff->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_calc->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
