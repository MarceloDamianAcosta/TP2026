//
// Created by chelokito on 26/7/26.
//

#ifndef ELEMENTOS_RANDOM_H
#define ELEMENTOS_RANDOM_H
#include "IA.h"

class Random : public IA
{
    public:
    Random(std::string nombre,unsigned short cantidad, unsigned short matrix[][5]):IA(nombre,cantidad,matrix){};
    void elegir(Elemento* enemigo) override;
};


#endif //ELEMENTOS_RANDOM_H
