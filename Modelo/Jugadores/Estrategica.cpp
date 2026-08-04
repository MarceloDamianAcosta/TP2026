//
// Created by chelokito on 27/7/26.
//

#include "Estrategica.h"
void Estrategica::elegir(Elemento* enemigo)
{
    unsigned short candidato=100;
    unsigned short lugarzinio=0;
    for (auto &x:elementos)
    {
        if (enemigo->getDefensas()[x->gettipo()]<candidato)
            candidato=enemigo->getDefensas()[x->gettipo()];
            lugar=lugarzinio;
            elegido(lugar);
        lugarzinio++;
    }

}