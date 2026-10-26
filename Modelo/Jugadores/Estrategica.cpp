//
// Created by chelokito on 27/7/26.
//

#include "Estrategica.h"
void Estrategica::elegir(Elemento* enemigo)
{
    unsigned short candidato=0;
    unsigned short lugarzinio=0;
    elegido(0);
    for (auto &x:elementos)
    {
        if (enemigo->getDanios()[x->getTipo()]>candidato)
        {
            candidato=enemigo->getDanios()[x->getTipo()];
            lugar=lugarzinio;
            elegido(lugar);
        }
        lugarzinio++;
    }

}