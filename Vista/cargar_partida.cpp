//
// Created by chelokito on 25/10/26.
//

// You may need to build the project (run Qt uic code generator) to get "ui_cargar_partida.h" resolved

#include "cargar_partida.h"
#include "ui_cargar_partida.h"


Cargar_Partida::Cargar_Partida(QWidget* parent) :
    QWidget(parent), ui(new Ui::Cargar_Partida)
{
    ui->setupUi(this);
}

Cargar_Partida::~Cargar_Partida()
{
    delete ui;
}
