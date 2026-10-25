//
// Created by chelokito on 27/7/26.
//

#ifndef ELEMENTOS_JUEGO_H
#define ELEMENTOS_JUEGO_H
#include <QObject>
#include "Elementos/Elemento.h"
#include "Elementos/tipos.h"
#include "Jugadores/Jugador.h"
#include "Jugadores/Humano.h"


class Juego
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
    void intercambio(Jugador *A, Jugador *B);
    void fin();

};


#endif //ELEMENTOS_JUEGO_H
