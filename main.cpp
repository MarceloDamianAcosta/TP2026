#include <QApplication>
#include "Modelo/Juego.h"
#include "Vista/menu.h"
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Juego juego;
    Menu menu(&juego);
    return a.exec();
}
