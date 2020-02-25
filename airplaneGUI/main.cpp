#include "mainwindow.h"
#include <QApplication>
#include "latlng.h"
#include <unordered_map>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
