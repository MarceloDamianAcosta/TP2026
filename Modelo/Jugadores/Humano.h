//
// Created by chelokito on 27/7/26.
//

#ifndef ELEMENTOS_HUMANO_H
#define ELEMENTOS_HUMANO_H
#include "Jugador.h"

class Humano:public Jugador
{
    public:
    Humano(std::string nombre): Jugador(nombre){};
};


#endif //ELEMENTOS_HUMANO_H
