#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QLabel>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QLabel* label = new QLabel("Hallo");
//    label->show();
//    valid_str();
//    QLabel* label = new QLabel(my_res);
//    label->show();
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "smart_calc_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();

}
