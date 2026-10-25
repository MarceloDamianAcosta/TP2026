//
// Created by chelokito on 26/7/26.
//

#ifndef ELEMENTOS_IA_H
#define ELEMENTOS_IA_H
#include "Jugador.h"

class IA :public Jugador
{
public:
    IA(std::string nombre):Jugador(nombre){}
    virtual void elegir(Elemento* enemigo)=0;
};


#endif //ELEMENTOS_IA_H
