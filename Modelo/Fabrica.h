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
#include "structs.h"

class Fabrica
{
   unsigned short matrix[6][6];
   unsigned short cantidad;
   unsigned short dificultad;
public:
    Fabrica();
    void leerConfiguracion(std::string archivo);
    void leerConfiguracion(std::istream& archivo);
    void guardar(std::string archivo, const Partida& partida) const;
    bool cargar(std::string archivo, Partida& partida);
    void crearE(Jugador* jugador, const std::vector<Carta>& cartas);
    static void completar(unsigned short danio[6][6]);
    Configuracion getConfiguracion() const;
    void setConfiguracion(const Configuracion& configuracion);
    IA* crearIA();
    void crearE(std::vector<Jugador*>&J);
    Humano* crearJugador(std::string nombre);
};


#endif //ELEMENTOS_FABRICA_H
