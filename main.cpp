#include <QApplication>
#include "Modelo/Juego.h"
#include "Vista/nueva.h"
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Juego juego;
    Nueva nueva(&juego);
    nueva.show();
    return a.exec();
}
