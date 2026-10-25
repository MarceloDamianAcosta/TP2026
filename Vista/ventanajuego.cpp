//
// Created by chelokito on 16/8/26.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ventanajuego.h" resolved

#include "ventanajuego.h"
#include "ui_ventanajuego.h"


VentanaJuego::VentanaJuego(Juego* juego, QWidget* parent) :
    QWidget(parent), ui(new Ui::VentanaJuego), juego(juego)
{
    ui->setupUi(this);
}

VentanaJuego::~VentanaJuego()
{
    delete ui;
}
