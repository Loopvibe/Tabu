#include "TabuMainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TabuMainWindow w;
    w.show();
    return a.exec();
}
