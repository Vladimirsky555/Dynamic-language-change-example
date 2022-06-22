#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QTranslator translator;
//    translator.load(":lan/ru");
//    qApp->installTranslator(&translator);

    MainWindow w;
    w.show();
    return a.exec();
}
