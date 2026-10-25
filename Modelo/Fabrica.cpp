//
// Created by chelokito on 23/10/26.
//

#include "Fabrica.h"
#include <random>

Jugador* Fabrica::crearIA(short dificultad, Humano* Adan)
{
        IA* x=nullptr;
        switch (dificultad)
        {
        case 1:
                return (delete x, new Random("JOSHUA"));
        case 2:
                {
                        x = new Estrategica("RED QUEEN");
                        break;
                }
        case 3:
                {
                        x = new Super("SAMARITAN");
                        break;
                }
        default :
                return nullptr;
        }
        x->elegir(Adan->getAtacante());
        return x;
}

void Fabrica::crearE(std::vector<Jugador*>&Jugadores ,unsigned short cantidad)
{
        std::random_device rd;
        std::mt19937 generador(rd());
        std::uniform_int_distribution<> rango(0, 5);
        for (auto &J: Jugadores)
        {
                for (unsigned short i = 0; i < cantidad; i++)
                {
                        switch (rango(generador))
                        {
                        case agua:
                                {
                                        J->agregar(new Elemento (matrix[0],agua));
                                        break;
                                }
                        case fuego:
                                {
                                        J->agregar(new Elemento (matrix[1],fuego));
                                        break;
                                }
                        case tierra:
                                {
                                        J->agregar(new Elemento(matrix[2],tierra));
                                        break;
                                }
                        case barro:
                                {
                                        J->agregar(new Elemento(matrix[3],barro));
                                        break;
                                }
                        case lava:
                                {
                                        J->agregar(new Elemento(matrix[4],lava));
                                        break;
                                }
                        case vapor:
                                {
                                        J->agregar(new Elemento(matrix[5],vapor));
                                        break;
                                }
                        }
                }
        }
}

Jugador* Fabrica::crearJugador(std::string nombre)
{
        return new Humano(nombre);
}