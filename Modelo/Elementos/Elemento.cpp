//
// Created by chelokito on 8/7/26.
//

#include "Elemento.h"

Elemento::Elemento(unsigned short* defensa, Tipo id):defensa(defensa), id(id),vida(100){}

unsigned short Elemento::getVida() const
{
    return this->vida;
}

void Elemento::defender(Tipo atacante)
{
    vida=-(100-defensa[atacante]);
}

unsigned short* Elemento::getDefensas() const
{
    return this->defensa;
}

Tipo Elemento::getTipo() const
{
    return this->id;
}

Elemento::~Elemento() {}