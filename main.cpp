#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mw;

//    if (mw.dblogin->isConnected){
//        mw.show();
//        return a.exec();

//    }
    mw.show();
    return a.exec();





}
