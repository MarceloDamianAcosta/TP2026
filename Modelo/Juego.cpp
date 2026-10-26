//
// Created by chelokito on 27/7/26.
//

#include "Juego.h"

Juego::Juego()
{
    nronda=1;
    ganador=nullptr;
    humano=nullptr;
    ia=nullptr;
}

Juego::~Juego()
{
    for (Jugador* jugador : jugadores)
        delete jugador;
}

Configuracion Juego::getConfiguracion() const
{
    return fabrica.getConfiguracion();
}

void Juego::iniciar(std::string nombre, const Configuracion& configuracion)
{
    limpiar();
    fabrica.setConfiguracion(configuracion);
    humano=fabrica.crearJugador(nombre);
    jugadores.push_back(humano);
    crearia();
    fabrica.crearE(jugadores);
}

// si viene de una partida anterior, arranca de cero
void Juego::limpiar()
{
    for (Jugador* jugador : jugadores)
        delete jugador;
    jugadores.clear();
    nronda=1;
    ganador=nullptr;
}

bool Juego::enCurso() const
{
    return !jugadores.empty() && !ganador;
}

void Juego::guardar(std::string archivo) const
{
    Partida partida{nronda, humano->getNombre(), {}, {}};
    for (Elemento* elemento : humano->getElementos())
        partida.elementosHumano.push_back({elemento->getTipo(), elemento->getVida()});
    for (Elemento* elemento : ia->getElementos())
        partida.elementosIA.push_back({elemento->getTipo(), elemento->getVida()});
    fabrica.guardar(archivo, partida);
}

bool Juego::cargar(std::string archivo)
{
    Partida partida;
    if (!fabrica.cargar(archivo, partida))
        return false;
    limpiar();
    nronda=partida.ronda;
    humano=fabrica.crearJugador(partida.humano);
    jugadores.push_back(humano);
    crearia();
    fabrica.crearE(humano, partida.elementosHumano);
    fabrica.crearE(ia, partida.elementosIA);
    return true;
}

unsigned short Juego::getRonda() const
{
    return nronda;
}

Jugador* Juego::getJugador(unsigned short i) const
{
    return jugadores[i];
}

Jugador* Juego::getGanador() const
{
    return ganador;
}

void Juego::crearia()
{
    ia=fabrica.crearIA();
    jugadores.push_back(ia);
}

void Juego::ronda(unsigned short lugar)
{
    humano->elegido(lugar);
    ia->elegir(humano->getAtacante());
    intercambio(humano, ia);
    // si el humano le mata el elemento, la IA elige otro y contraataca igual
    if (ia->muerto() && !ia->perder())
        ia->elegir(humano->getAtacante());
    if (!ia->perder())
    {
        intercambio(ia, humano);
        humano->muerto();
    }
    fin();
    nronda++;
}

void Juego::fin()
{
    if (jugadores[0]->perder())
        ganador=jugadores[1];
    if (jugadores[1]->perder())
        ganador=jugadores[0];
}

void Juego::intercambio(Jugador* a, Jugador* b)
{
    b->getAtacante()->defender(a->getAtacante()->getTipo());
}
