//
// Created by chelokito on 27/7/26.
//

#ifndef ELEMENTOS_JUEGO_H
#define ELEMENTOS_JUEGO_H
#include "Elementos/Elemento.h"
#include "Elementos/tipos.h"
#include "Jugadores/Jugador.h"
#include "Jugadores/Humano.h"
#include "Fabrica.h"


class Juego
{
    unsigned short nronda;
    std::vector<Jugador*> jugadores;
    Jugador* ganador;
    Fabrica fabrica;
public:
    Juego();
    Configuracion getConfiguracion() const;
    void iniciar(std::string nombre, const Configuracion& configuracion);
    void ronda();
    void crearia();
    void intercambio(Jugador *A, Jugador *B);
    void fin();

};


#endif //ELEMENTOS_JUEGO_H
