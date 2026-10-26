//
// Created by chelokito on 27/7/26.
//

#ifndef ELEMENTOS_JUEGO_H
#define ELEMENTOS_JUEGO_H
#include "Elementos/Elemento.h"
#include "Elementos/tipos.h"
#include "Jugadores/Jugador.h"
#include "Jugadores/Humano.h"
#include "Jugadores/IA.h"
#include "Fabrica.h"


class Juego
{
    unsigned short nronda;
    std::vector<Jugador*> jugadores;
    Humano* humano;
    IA* ia;
    Jugador* ganador;
    Fabrica fabrica;
    void limpiar();
public:
    Juego();
    ~Juego();
    Configuracion getConfiguracion() const;
    void iniciar(std::string nombre, const Configuracion& configuracion);
    unsigned short getRonda() const;
    Jugador* getJugador(unsigned short i) const;
    Jugador* getGanador() const;
    bool enCurso() const;
    void guardar(std::string archivo) const;
    bool cargar(std::string archivo);
    void ronda(unsigned short lugar);
    void crearia();
    void intercambio(Jugador *A, Jugador *B);
    void fin();

};


#endif //ELEMENTOS_JUEGO_H
