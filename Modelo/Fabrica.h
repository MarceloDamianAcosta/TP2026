//
// Created by chelokito on 23/10/26.
//

#ifndef ELEMENTOS_FABRICA_H
#define ELEMENTOS_FABRICA_H

#include "Elementos/Elemento.h"
#include "Jugadores/Jugador.h"
#include "Jugadores/Humano.h"
#include "Jugadores/IA.h"
#include "Jugadores/Estrategica.h"
#include "Jugadores/Super.h"
#include "Jugadores/Random.h"

class Fabrica
{
   unsigned short**matrix;
public:
    Jugador* crearIA(short a, Humano* Adan);
    void crearE(std::vector<Jugador*>&J, unsigned short cantidad);
    Jugador* crearJugador(std::string nombre);
};


#endif //ELEMENTOS_FABRICA_H
