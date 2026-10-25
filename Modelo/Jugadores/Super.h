//
// Created by chelokito on 27/7/26.
//

#ifndef ELEMENTOS_SUPER_H
#define ELEMENTOS_SUPER_H
#include "IA.h"

class Super: public IA
{
    public:
    Super(std::string nombre):IA(nombre){}
    void elegir(Elemento* enemigo) override;
};


#endif //ELEMENTOS_SUPER_H
