//
// Created by chelokito on 20/7/26.
#include <random>
#include "../Elementos/Agua.h"
#include "../Elementos/Fuego.h"
#include "../Elementos/Barro.h"
#include "../Elementos/Lava.h"
#include "../Elementos/Tierra.h"
#include "../Elementos/Vapor.h"
#include "Jugador.h"

Jugador::Jugador(std::string nombre,unsigned short cantidad, unsigned short matrix[][5])
{
    this->nombre = nombre;
    crearElementos(cantidad, matrix);
}

void Jugador::crearElementos(unsigned short cantidad, unsigned short matrix[][5])
{
    std::random_device rd;
    std::mt19937 generador(rd());
    std::uniform_int_distribution<> rango(0, 5);
    for (unsigned short i = 0; i < cantidad; i++)
    {
        switch (rango(generador))
        {
        case agua:
            {
                elementos.push_back(new Agua(matrix[0]));
                break;
            }
        case fuego:
            {
                elementos.push_back(new Fuego(matrix[1]));
                break;
            }
        case tierra:
            {
                elementos.push_back(new Tierra(matrix[2]));
                break;
            }
        case barro:
            {
                elementos.push_back(new Barro(matrix[3]));
                break;
            }
        case lava:
            {
                elementos.push_back(new Lava(matrix[4]));
                break;
            }
        case vapor:
            {
                elementos.push_back(new Vapor(matrix[5]));
                break;
            }
        }
    }
}

std::string Jugador::getNombre()
{
    return this->nombre;
}

void Jugador::elegido(unsigned short lugar)
{
    atacante=elementos[lugar];
    this->lugar=lugar;
}

bool Jugador::muerto()
{
    if (atacante->getVida())
        return false;
    achicar();
    return true;
}

bool Jugador::perder()
{
    return elementos.empty();
}

void Jugador::achicar()
{
    elementos.erase(elementos.begin()+lugar);
    atacante->~Elemento();
    atacante=nullptr;
}

Elemento* Jugador::getAtacante()
{
    return atacante;
}

Jugador::~Jugador() {}