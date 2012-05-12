#include "ui/windows/mainwindow.h"

#include <QtGui>
#include <QApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
	qDebug() << "Iniciando aplicacion en modo debug. Solo para valientes...";
    QApplication a(argc, argv);
    mainwindow w;
    w.show();
    return a.exec();
}
