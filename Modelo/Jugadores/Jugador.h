//
// Created by chelokito on 20/7/26.
//

#ifndef ELEMENTOS_JUGADOR_H
#define ELEMENTOS_JUGADOR_H
#include <string>
#include <vector>
#include "../Elementos/Elemento.h"


class Jugador
{
    protected:
    std::string nombre;
    std::vector<Elemento*> elementos;
    Elemento*atacante;
    unsigned short lugar;
    public:
    Jugador(std::string nombre,unsigned short cantidad, unsigned short matrix[][5]);
    void crearElementos(unsigned short cantidad, unsigned short matrix[][5]);
    std::string getNombre();
    void elegido(unsigned short lugar);
    Elemento* getAtacante();
    bool muerto();
    void achicar();
    bool perder();
    virtual ~Jugador()=0;
};


#endif //ELEMENTOS_JUGADOR_H
