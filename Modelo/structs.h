//
// Created by chelokito on 26/10/26.
//

#ifndef ELEMENTOS_STRUCTS_H
#define ELEMENTOS_STRUCTS_H

#include <string>
#include <utility>
#include <vector>
#include "Elementos/tipos.h"

struct Configuracion
{
    unsigned short dificultad;
    unsigned short cantidad;
    unsigned short danio[6][6];
};

using Carta = std::pair<Tipo, unsigned short>; // tipo, vida

struct Partida
{
    unsigned short ronda;
    std::string humano;
    std::vector<Carta> elementosHumano;
    std::vector<Carta> elementosIA;
};


#endif //ELEMENTOS_STRUCTS_H
