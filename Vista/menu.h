//
// Created by chelokito on 26/10/26.
//

#ifndef ELEMENTOS_MENU_H
#define ELEMENTOS_MENU_H

#include <QWidget>
#include "../Modelo/Juego.h"
#include "ventanajuego.h"


QT_BEGIN_NAMESPACE

namespace Ui
{
    class Menu;
}

QT_END_NAMESPACE

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(Juego* juego, QWidget* parent = nullptr);
    ~Menu() override;

private:
    Ui::Menu* ui;
    Juego* juego;
    VentanaJuego* ventana;
    void nueva();
    void cargar();
    void guardar();
    void volver();
    void abrirJuego();
    void mostrar();
};


#endif //ELEMENTOS_MENU_H
