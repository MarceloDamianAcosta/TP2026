//
// Created by chelokito on 16/8/26.
//

#ifndef ELEMENTOS_VENTANAJUEGO_H
#define ELEMENTOS_VENTANAJUEGO_H

#include <QWidget>
#include <QGroupBox>
#include "../Modelo/Juego.h"


QT_BEGIN_NAMESPACE

namespace Ui
{
    class VentanaJuego;
}

QT_END_NAMESPACE

class VentanaJuego : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaJuego(Juego* juego, QWidget* parent = nullptr);
    ~VentanaJuego() override;

private:
    Ui::VentanaJuego* ui;
    Juego* juego;
    void actualizar();
    void mostrarElementos(QGroupBox* caja, Jugador* jugador, bool elegible);
};


#endif //ELEMENTOS_VENTANAJUEGO_H
