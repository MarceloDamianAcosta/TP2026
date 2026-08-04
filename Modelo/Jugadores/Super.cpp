//
// Created by chelokito on 27/7/26.
//

#include "Super.h"
#include <algorithm>
void Super::elegir(Elemento* enemigo)
{
    std::vector<unsigned short>ordenDanio;
    for (unsigned short i = 0; i < elementos.size(); i++)
    {
        ordenDanio.push_back(i);
    }
    std::sort(ordenDanio.begin(), ordenDanio.end(),[&](unsigned short& a, unsigned short& b){return enemigo->getDefensas()[elementos[a]->gettipo()] < enemigo->getDefensas()[elementos[b]->gettipo()];});
    for (int i = 0; i < ordenDanio.size(); i++)
    {
        if (enemigo->getDefensas()[elementos[ordenDanio[i]]->gettipo()]>=enemigo->getVida() )
        {
            elegido(ordenDanio[i]);
            break;
        }
    }
}