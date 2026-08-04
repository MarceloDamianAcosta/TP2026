//
// Created by chelokito on 27/7/26.
//

#ifndef ELEMENTOS_HUMANO_H
#define ELEMENTOS_HUMANO_H
#include "Jugador.h"

class Humano:public Jugador
{
    public:
    Humano(std::string nombre,unsigned short cantidad, unsigned short matrix[][5]): Jugador(nombre,cantidad,matrix){};
};


#endif //ELEMENTOS_HUMANO_H
