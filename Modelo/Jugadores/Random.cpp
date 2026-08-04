//
// Created by chelokito on 26/7/26.
//
#include "Random.h"
#include <random>

void Random::elegir(Elemento* enemigo)
{
    std::random_device rd;
    std::mt19937 generador(rd());
    std::uniform_int_distribution<unsigned short> rango(0, elementos.size() - 1);
    elegido(rango(generador));
}
