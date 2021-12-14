#include <QApplication>
#include "frskyupdate.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    frskyUpdate w;
    w.show();
    return a.exec();
}
