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

IA* Fabrica::crearIA()
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

void Fabrica::crearE(Jugador* jugador, const std::vector<Carta>& cartas)
{
        for (const Carta& carta : cartas)
                jugador->agregar(new Elemento(matrix[carta.first], carta.first, carta.second));
}

void Fabrica::guardar(std::string archivo, const Partida& partida) const
{
        Cabecera cabecera{};
        cabecera.dificultad = dificultad;
        cabecera.cantidad = cantidad;
        for (unsigned short defensor = agua; defensor <= tierra; defensor++)
                for (unsigned short atacante = agua; atacante <= tierra; atacante++)
                        cabecera.danio[defensor][atacante] = matrix[defensor][atacante];
        cabecera.ronda = partida.ronda;
        // cabecera{} dejo todo en 0, asi el nombre siempre termina en '\0'
        partida.humano.copy(cabecera.humano, sizeof(cabecera.humano) - 1);
        cabecera.cantHumano = partida.elementosHumano.size();
        cabecera.cantIA = partida.elementosIA.size();

        std::ofstream salida(archivo, std::ios::binary);
        salida.write(reinterpret_cast<const char*>(&cabecera), sizeof(cabecera));
        escribirCartas(salida, partida.elementosHumano);
        escribirCartas(salida, partida.elementosIA);
}

// devuelve false si el archivo no es una partida valida, y en ese caso no cambia nada
bool Fabrica::cargar(std::string archivo, Partida& partida)
{
        std::ifstream entrada(archivo, std::ios::binary);
        Cabecera cabecera;
        entrada.read(reinterpret_cast<char*>(&cabecera), sizeof(cabecera));
        if (!entrada || !validar(cabecera)
            || !leerCartas(entrada, cabecera.cantHumano, partida.elementosHumano)
            || !leerCartas(entrada, cabecera.cantIA, partida.elementosIA))
                return false;
        partida.ronda = cabecera.ronda;
        partida.humano = cabecera.humano;
        dificultad = cabecera.dificultad;
        cantidad = cabecera.cantidad;
        for (unsigned short defensor = agua; defensor <= tierra; defensor++)
                for (unsigned short atacante = agua; atacante <= tierra; atacante++)
                        matrix[defensor][atacante] = cabecera.danio[defensor][atacante];
        completar(matrix);
        return true;
}

bool Fabrica::validar(const Cabecera& cabecera)
{
        bool valida = cabecera.dificultad >= 1 && cabecera.dificultad <= 3
                && cabecera.cantidad >= 1 && cabecera.cantidad <= 6
                && cabecera.ronda >= 1
                && cabecera.humano[0] != '\0' && cabecera.humano[sizeof(cabecera.humano) - 1] == '\0'
                && cabecera.cantHumano >= 1 && cabecera.cantHumano <= cabecera.cantidad
                && cabecera.cantIA >= 1 && cabecera.cantIA <= cabecera.cantidad;
        for (unsigned short defensor = agua; defensor <= tierra; defensor++)
                for (unsigned short atacante = agua; atacante <= tierra; atacante++)
                        valida = valida && cabecera.danio[defensor][atacante] <= 100;
        return valida;
}

// std::pair no se puede escribir de un solo write, va campo por campo
void Fabrica::escribirCartas(std::ostream& salida, const std::vector<Carta>& cartas)
{
        for (const Carta& carta : cartas)
        {
                unsigned short tipo = carta.first;
                salida.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));
                salida.write(reinterpret_cast<const char*>(&carta.second), sizeof(carta.second));
        }
}

bool Fabrica::leerCartas(std::istream& entrada, unsigned short cantidad, std::vector<Carta>& cartas)
{
        for (unsigned short i = 0; i < cantidad; i++)
        {
                unsigned short tipo, vida;
                entrada.read(reinterpret_cast<char*>(&tipo), sizeof(tipo));
                entrada.read(reinterpret_cast<char*>(&vida), sizeof(vida));
                if (!entrada || tipo > vapor || vida < 1 || vida > 100)
                        return false;
                cartas.push_back({static_cast<Tipo>(tipo), vida});
        }
        return true;
}

Humano* Fabrica::crearJugador(std::string nombre)
{
        return new Humano(nombre);
}