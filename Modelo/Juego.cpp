//
// Created by chelokito on 27/7/26.
//

#include "Juego.h"

Juego::Juego()
{
    nronda=1;
    ganador=nullptr;
    humano=nullptr;
    ia=nullptr;
}

Juego::~Juego()
{
    for (Jugador* jugador : jugadores)
        delete jugador;
}

Configuracion Juego::getConfiguracion() const
{
    return fabrica.getConfiguracion();
}

void Juego::iniciar(std::string nombre, const Configuracion& configuracion)
{
    // si viene de una partida anterior, arranca de cero
    for (Jugador* jugador : jugadores)
        delete jugador;
    jugadores.clear();
    nronda=1;
    ganador=nullptr;
    fabrica.setConfiguracion(configuracion);
    humano=fabrica.crearJugador(nombre);
    jugadores.push_back(humano);
    crearia();
    fabrica.crearE(jugadores);
}

unsigned short Juego::getRonda() const
{
    return nronda;
}

Jugador* Juego::getJugador(unsigned short i) const
{
    return jugadores[i];
}

Jugador* Juego::getGanador() const
{
    return ganador;
}

void Juego::crearia()
{
    ia=fabrica.crearIA();
    jugadores.push_back(ia);
}

void Juego::ronda(unsigned short lugar)
{
    humano->elegido(lugar);
    ia->elegir(humano->getAtacante());
    intercambio(humano, ia);
    if (!ia->muerto())
    {
        intercambio(ia, humano);
        humano->muerto();
    }
    fin();
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
