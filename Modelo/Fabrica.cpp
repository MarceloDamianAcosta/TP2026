//
// Created by chelokito on 23/10/26.
//

#include "Fabrica.h"
#include <random>
#include <fstream>

Fabrica::Fabrica():matrix{}, cantidad(1), dificultad(1)
{
        leerConfiguracion("configuracion.txt");
}

void Fabrica::leerConfiguracion(std::string archivo)
{
        std::ifstream configuracion(archivo);
        configuracion >> dificultad >> cantidad;
        for (unsigned short defensor = agua; defensor <= tierra; defensor++)
                for (unsigned short atacante = agua; atacante <= tierra; atacante++)
                        configuracion >> matrix[defensor][atacante];
        completar(matrix);
}

void Fabrica::completar(unsigned short danio[6][6])
{
        // barro ataca como agua y defiende como tierra, lava ataca como fuego y defiende como tierra, vapor ataca como fuego y defiende como agua
        const Tipo ataca[6] = {agua, fuego, tierra, agua, fuego, fuego};
        const Tipo defiende[6] = {agua, fuego, tierra, tierra, tierra, agua};
        for (unsigned short defensor = agua; defensor <= vapor; defensor++)
                for (unsigned short atacante = agua; atacante <= vapor; atacante++)
                        danio[defensor][atacante] = danio[defiende[defensor]][ataca[atacante]];
}

Configuracion Fabrica::getConfiguracion() const
{
        Configuracion configuracion{dificultad, cantidad, {}};
        for (unsigned short defensor = agua; defensor <= vapor; defensor++)
                for (unsigned short atacante = agua; atacante <= vapor; atacante++)
                        configuracion.danio[defensor][atacante] = matrix[defensor][atacante];
        return configuracion;
}

void Fabrica::setConfiguracion(const Configuracion& configuracion)
{
        dificultad = configuracion.dificultad;
        cantidad = configuracion.cantidad;
        for (unsigned short defensor = agua; defensor <= tierra; defensor++)
                for (unsigned short atacante = agua; atacante <= tierra; atacante++)
                        matrix[defensor][atacante] = configuracion.danio[defensor][atacante];
        completar(matrix);
}

Jugador* Fabrica::crearIA()
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
        return x;
}

void Fabrica::crearE(std::vector<Jugador*>&Jugadores)
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