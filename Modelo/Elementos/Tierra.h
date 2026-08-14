//
// Created by chelokito on 20/7/26.
//

#ifndef ELEMENTOS_TIERRA_H
#define ELEMENTOS_TIERRA_H
#include "Elemento.h"

class Tierra:public Elemento
{
    public:
    Tierra(unsigned short* defensa);
    ~Tierra();
};


#endif //ELEMENTOS_TIERRA_H
