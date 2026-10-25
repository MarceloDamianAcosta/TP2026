//
// Created by chelokito on 16/8/26.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ventanajuego.h" resolved

#include "ventanajuego.h"
#include "ui_ventanajuego.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>


VentanaJuego::VentanaJuego(Juego* juego, QWidget* parent) :
    QWidget(parent), ui(new Ui::VentanaJuego), juego(juego)
{
    ui->setupUi(this);
    new QHBoxLayout(ui->IA_gb);
    new QHBoxLayout(ui->Jugador_gb);
    actualizar();
}

void VentanaJuego::actualizar()
{
    ui->ronda_lcd->display(juego->getRonda());
    mostrarElementos(ui->Jugador_gb, juego->getJugador(0), true);
    mostrarElementos(ui->IA_gb, juego->getJugador(1), false);
}

void VentanaJuego::mostrarElementos(QGroupBox* caja, Jugador* jugador, bool elegible)
{
    const QString nombres[6] = {"agua", "fuego", "tierra", "barro", "lava", "vapor"};
    const int lado = 120;
    caja->setTitle(QString::fromStdString(jugador->getNombre()));
    QLayout* fila = caja->layout();
    while (QLayoutItem* item = fila->takeAt(0))
    {
        delete item->widget();
        delete item;
    }
    for (Elemento* elemento : jugador->getElementos())
    {
        auto* carta = new QWidget;
        auto* columna = new QVBoxLayout(carta);
        QPixmap imagen = QIcon(":/iconos/" + nombres[elemento->getTipo()] + ".svg").pixmap(lado - 16);
        // deshabilitado se veria gris, asi que usa la misma imagen
        QIcon icono;
        icono.addPixmap(imagen, QIcon::Normal);
        icono.addPixmap(imagen, QIcon::Disabled);
        auto* boton = new QPushButton(icono, "");
        boton->setFixedSize(lado, lado);
        boton->setIconSize(QSize(lado - 16, lado - 16));
        boton->setEnabled(elegible);
        auto* vida = new QLabel("Vida: " + QString::number(elemento->getVida()));
        vida->setAlignment(Qt::AlignCenter);
        columna->addWidget(boton);
        columna->addWidget(vida);
        fila->addWidget(carta);
    }
}

VentanaJuego::~VentanaJuego()
{
    delete ui;
}
