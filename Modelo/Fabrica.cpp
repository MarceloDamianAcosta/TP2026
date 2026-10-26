//
// Created by chelokito on 23/10/26.
//

#include "Fabrica.h"
#include <random>
#include <fstream>
#include <sstream>

Fabrica::Fabrica():matrix{}, cantidad(1), dificultad(1)
{
        leerConfiguracion("configuracion.txt");
}

void Fabrica::leerConfiguracion(std::string archivo)
{
        std::ifstream configuracion(archivo);
        leerConfiguracion(configuracion);
}

void Fabrica::leerConfiguracion(std::istream& configuracion)
{
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

// arriba lo que no cambia (igual que configuracion.txt), abajo los elementos
void Fabrica::guardar(std::string archivo, const Partida& partida) const
{
        std::ofstream salida(archivo);
        salida << dificultad << "\n" << cantidad << "\n";
        for (unsigned short defensor = agua; defensor <= tierra; defensor++)
                salida << matrix[defensor][agua] << " " << matrix[defensor][fuego] << " " << matrix[defensor][tierra] << "\n";
        salida << partida.ronda << "\n" << partida.humano << "\n";
        for (const std::vector<Carta>* cartas : {&partida.elementosHumano, &partida.elementosIA})
        {
                for (const Carta& carta : *cartas)
                        salida << carta.first << " " << carta.second << " ";
                salida << "\n";
        }
}

// devuelve false si el archivo no es una partida valida, y en ese caso no cambia nada
bool Fabrica::cargar(std::string archivo, Partida& partida)
{
        std::ifstream entrada(archivo);
        if (!entrada)
                return false;
        Configuracion anterior = getConfiguracion();
        leerConfiguracion(entrada);
        bool valida = entrada && dificultad >= 1 && dificultad <= 3 && cantidad >= 1 && cantidad <= 6;
        for (unsigned short defensor = agua; defensor <= tierra; defensor++)
                for (unsigned short atacante = agua; atacante <= tierra; atacante++)
                        valida = valida && matrix[defensor][atacante] <= 100;
        entrada >> partida.ronda >> std::ws;
        std::getline(entrada, partida.humano);
        valida = valida && entrada && partida.ronda >= 1 && !partida.humano.empty();
        for (std::vector<Carta>* cartas : {&partida.elementosHumano, &partida.elementosIA})
        {
                std::string linea;
                std::getline(entrada, linea);
                std::istringstream fila(linea);
                std::vector<unsigned short> numeros;
                unsigned short numero;
                while (fila >> numero)
                        numeros.push_back(numero);
                // solo numeros, y de a pares (tipo, vida)
                valida = valida && fila.eof() && !numeros.empty() && numeros.size() % 2 == 0;
                for (size_t i = 0; valida && i < numeros.size(); i += 2)
                {
                        valida = numeros[i] <= vapor && numeros[i + 1] >= 1 && numeros[i + 1] <= 100;
                        cartas->push_back({static_cast<Tipo>(numeros[i]), numeros[i + 1]});
                }
        }
        if (!valida)
                setConfiguracion(anterior);
        return valida;
}

Humano* Fabrica::crearJugador(std::string nombre)
{
        return new Humano(nombre);
}