//
// Created by chelokito on 20/7/26.
#include "../Elementos/Elemento.h"
#include "Jugador.h"

Jugador::Jugador(std::string nombre)
{
    this->nombre = nombre;
    atacante = nullptr;
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

void Jugador::agregar(Elemento* elemento)
{
    elementos.emplace_back(elemento);
}

void Jugador::achicar()
{
    elementos.erase(elementos.begin()+lugar);
    delete atacante;
    atacante=nullptr;
}

const std::vector<Elemento*>& Jugador::getElementos() const
{
    return elementos;
}

Elemento* Jugador::getAtacante()
{
    return atacante;
}

Jugador::~Jugador()
{
    for (Elemento* elemento : elementos)
        delete elemento;
}