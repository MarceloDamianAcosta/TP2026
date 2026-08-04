//
// Created by chelokito on 27/7/26.
//

#ifndef ELEMENTOS_JUEGO_H
#define ELEMENTOS_JUEGO_H
#include <QObject>
#include "Elementos/Agua.h"
#include "Elementos/Barro.h"
#include "Elementos/Tierra.h"
#include "Elementos/Elemento.h"
#include "Elementos/Fuego.h"
#include "Elementos/Lava.h"
#include "Elementos/Vapor.h"
#include "Elementos/tipos.h"
#include "Jugadores/Jugador.h"
#include "Jugadores/Humano.h"
#include "Jugadores/IA.h"
#include "Jugadores/Estrategica.h"
#include "Jugadores/Super.h"
#include "Jugadores/Random.h"

class Juego:public QObject
{
    unsigned short nronda;
    unsigned short cantidadDeElementos;
    std::vector<Jugador*> jugadores;
    unsigned short matriz[5][5];
    unsigned short dificultad;
    Jugador* ganador;
public:
    Juego();
    void ronda();
    void crearia();
    bool fin();



};


#endif //ELEMENTOS_JUEGO_H
