//
// Created by chelokito on 27/7/26.
//

#include "Juego.h"

Juego::Juego()
{
    nronda=1;
    ganador=nullptr;
}

Configuracion Juego::getConfiguracion() const
{
    return fabrica.getConfiguracion();
}

void Juego::iniciar(std::string nombre, const Configuracion& configuracion)
{
    fabrica.setConfiguracion(configuracion);
    jugadores.push_back(fabrica.crearJugador(nombre));
    crearia();
    fabrica.crearE(jugadores);
}

void Juego::crearia()
{
    jugadores.push_back(fabrica.crearIA());
}

void Juego::ronda()
{
    nronda++;
}

void Juego::fin()
{
    if (jugadores[0]->perder())
        ganador=jugadores[1];
    if (jugadores[1]->perder())
        ganador=jugadores[0];
}

void Juego::intercambio(Jugador* a, Jugador* b)
{
    b->getAtacante()->defender(a->getAtacante()->getTipo());
}
