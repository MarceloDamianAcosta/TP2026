//
// Created by chelokito on 27/7/26.
//

#include "Juego.h"

Juego::Juego()
{
    nronda=1;
    ganador=nullptr;
}

void Juego::crearia()
{

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
