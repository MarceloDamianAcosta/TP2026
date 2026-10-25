//
// Created by chelokito on 16/8/26.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VentanaJuego.h" resolved

#include "ventanajuego.h"
#include "ui_VentanaJuego.h"


VentanaJuego::VentanaJuego(QWidget* parent) :
    QWidget(parent), ui(new Ui::VentanaJuego)
{
    ui->setupUi(this);
}

VentanaJuego::~VentanaJuego()
{
    delete ui;
}
