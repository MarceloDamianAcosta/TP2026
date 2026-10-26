//
// Created by chelokito on 8/7/26.
//

#include "Elemento.h"

Elemento::Elemento(unsigned short* danios, Tipo id, unsigned short vida):danios(danios), id(id),vida(vida){}

unsigned short Elemento::getVida() const
{
    return this->vida;
}

void Elemento::defender(Tipo atacante)
{
    if (danios[atacante] >= vida)
        vida=0;
    else
        vida-=danios[atacante];
}

unsigned short* Elemento::getDanios() const
{
    return this->danios;
}

Tipo Elemento::getTipo() const
{
    return this->id;
}
