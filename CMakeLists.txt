cmake_minimum_required(VERSION 4.2)
project(Elementos)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Elementos main.cpp
        Modelo/Elementos/Elemento.cpp
        Modelo/Elementos/Elemento.h
        Modelo/Elementos/tipos.h
        Modelo/Elementos/Fuego.cpp
        Modelo/Elementos/Fuego.h
        Modelo/Elementos/Agua.cpp
        Modelo/Elementos/Agua.h
        Modelo/Elementos/Tierra.cpp
        Modelo/Elementos/Tierra.h
        Modelo/Elementos/Barro.cpp
        Modelo/Elementos/Barro.h
        Modelo/Elementos/Lava.cpp
        Modelo/Elementos/Lava.h
        Modelo/Elementos/Vapor.cpp
        Modelo/Elementos/Vapor.h
        Modelo/Jugadores/Jugador.cpp
        Modelo/Jugadores/Jugador.h
        Modelo/Jugadores/IA.h
        Modelo/Jugadores/Random.cpp
        Modelo/Jugadores/Random.h
        Modelo/Jugadores/Estrategica.cpp
        Modelo/Jugadores/Estrategica.h
        Modelo/Jugadores/Super.cpp
        Modelo/Jugadores/Super.h
        Modelo/Jugadores/Humano.cpp
        Modelo/Jugadores/Humano.h
        Modelo/Juego.cpp
        Modelo/Juego.h
)
target_link_libraries(Elementos
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

