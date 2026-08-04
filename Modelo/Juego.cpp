//
// Created by chelokito on 27/7/26.
//

#include "Juego.h"

Juego::Juego()
{
    nronda=0;
    cantidadDeElementos=5;
    dificultad=1;
    ganador=nullptr;
}

void Juego::crearia()
{
    jugadores.push_back(new Humano("Jugador",cantidadDeElementos,matriz));

    switch (dificultad)
    {
    case 1:
        {
            jugadores.push_back(new Random("Maki Gero",cantidadDeElementos,matriz));
            break;
        }
    case 2:
        {
            jugadores.push_back(new Estrategica("Skynet",cantidadDeElementos,matriz));
            break;
        }
    case 3:
        {
            jugadores.push_back(new Super("Samaritan",cantidadDeElementos,matriz));
            break;
        }
    }
}

void Juego::ronda()
{
    while (!ganador)
    {
        
    }
}
