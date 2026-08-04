//
// Created by chelokito on 27/7/26.
//

#ifndef ELEMENTOS_SUPER_H
#define ELEMENTOS_SUPER_H
#include "IA.h"

class Super: public IA
{
    public:
    Super(std::string nombre,unsigned short cantidad, unsigned short matrix[][5]):IA(nombre,cantidad,matrix){}
    void elegir(Elemento* enemigo) override;
};


#endif //ELEMENTOS_SUPER_H
