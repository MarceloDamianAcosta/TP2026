//
// Created by chelokito on 27/7/26.
//

#ifndef ELEMENTOS_ESTRATEGICA_H
#define ELEMENTOS_ESTRATEGICA_H
#include "IA.h"

class Estrategica:public IA
{
    public:
    Estrategica(std::string nombre,unsigned short cantidad, unsigned short matrix[][5]):IA(nombre,cantidad,matrix){};
    void elegir(Elemento* enemigo) override;
    
};


#endif //ELEMENTOS_ESTRATEGICA_H
