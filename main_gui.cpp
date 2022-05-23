#include "ventppal.h"
#include <QApplication>
#include <QString>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ventppal w;
    w.show();    
    return a.exec();
    }

