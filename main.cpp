#include "mainwindow.h"
#include <QApplication>

#include "turbine.h"

#include <qdebug.h>
int main(int argc, char *argv[])
{
   /* Read read(":/files/test/a170504.csv");
    read.ReadStoreData();
    WindSpeed wind(0.5,read);
    Turbine turbine(0.5,0.5,wind);

    turbine.wind->averageWind("5/4/17,0:00:00","5/4/17,1:00:00");

    qDebug() << turbine.TurbinePower() << endl;
*/
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
