//
// Created by chelokito on 25/10/26.
//

// You may need to build the project (run Qt uic code generator) to get "ui_guardar_partida.h" resolved

#include "guardar_partida.h"
#include "ui_guardar_partida.h"


guardar_partida::guardar_partida(QWidget* parent) :
    QWidget(parent), ui(new Ui::guardar_partida)
{
    ui->setupUi(this);
}

guardar_partida::~guardar_partida()
{
    delete ui;
}
