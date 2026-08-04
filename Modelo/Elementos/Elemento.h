//
// Created by chelokito on 8/7/26.
//

#ifndef ELEMENTOS_ELEMENTO_H
#define ELEMENTOS_ELEMENTO_H
#include "tipos.h"

class Elemento
{
    protected:
    Tipo id;
    unsigned short vida;
    unsigned short* defensa;
    public:
    Elemento(unsigned short* defensas, Tipo id);
    unsigned short getVida() const;
    void defender(Tipo atacante);
    unsigned short* getDefensas() const;
    virtual ~Elemento()=0;
    Tipo gettipo() const;
};


#endif //ELEMENTOS_ELEMENTO_H
