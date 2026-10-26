//
// Created by chelokito on 26/10/26.
//

#include "menu.h"
#include "ui_Menu.h"
#include "nueva.h"
#include <QFileDialog>
#include <QMessageBox>


Menu::Menu(Juego* juego, QWidget* parent) :
    QWidget(parent), ui(new Ui::Menu), juego(juego), ventana(nullptr)
{
    ui->setupUi(this);
    connect(ui->nueva_pb, &QPushButton::clicked, this, &Menu::nueva);
    connect(ui->cargar_pb, &QPushButton::clicked, this, &Menu::cargar);
    connect(ui->guardar_pb, &QPushButton::clicked, this, &Menu::guardar);
    connect(ui->volver_pb, &QPushButton::clicked, this, &Menu::volver);
    connect(ui->salir_pb, &QPushButton::clicked, this, &Menu::close);
    mostrar();
}

Menu::~Menu()
{
    delete ui;
    delete ventana;
}

// guardar y volver solo tienen sentido con una partida en curso
void Menu::mostrar()
{
    ui->guardar_pb->setEnabled(juego->enCurso());
    ui->volver_pb->setEnabled(juego->enCurso());
    show();
}

void Menu::nueva()
{
    auto* nueva = new Nueva(juego);
    nueva->setAttribute(Qt::WA_DeleteOnClose);
    nueva->setWindowModality(Qt::ApplicationModal);
    connect(nueva, &Nueva::partidaCreada, this, &Menu::abrirJuego);
    nueva->show();
}

void Menu::cargar()
{
    QString archivo = QFileDialog::getOpenFileName(this, "Cargar partida", "", "Partidas (*.dat)");
    if (archivo.isEmpty())
        return;
    if (!juego->cargar(archivo.toStdString()))
    {
        QMessageBox::warning(this, "Cargar partida", "El archivo no es una partida válida o está dañado.");
        return;
    }
    abrirJuego();
}

void Menu::guardar()
{
    QString archivo = QFileDialog::getSaveFileName(this, "Guardar partida", "partida.dat", "Partidas (*.dat)");
    if (archivo.isEmpty())
        return;
    juego->guardar(archivo.toStdString());
}

void Menu::volver()
{
    ventana->show();
    hide();
}

// la ventana de la partida anterior se descarta y se abre una nueva
void Menu::abrirJuego()
{
    delete ventana;
    ventana = new VentanaJuego(juego);
    connect(ventana, &VentanaJuego::irAlMenu, this, [this] {
        ventana->hide();
        mostrar();
    });
    ventana->show();
    hide();
}
