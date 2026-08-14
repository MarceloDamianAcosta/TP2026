#include <QApplication>
#include <QWidget>
#include "ui_Nueva.h"
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QWidget ventana;
    Ui::Nueva nueva;
    nueva.setupUi(&ventana);
    ventana.show();
    return a.exec();
}
