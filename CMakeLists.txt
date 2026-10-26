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

qt_add_executable(Elementos main.cpp
        Vista/Nueva.ui
        Vista/nueva.cpp
        Vista/nueva.h
        Vista/Menu.ui
        Vista/menu.cpp
        Vista/menu.h
        Vista/iconos.qrc
        Vista/ganadores.qrc
        Modelo/Elementos/Elemento.cpp
        Modelo/Elementos/Elemento.h
        Modelo/Elementos/tipos.h
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
        Vista/ventanajuego.cpp
        Vista/ventanajuego.h
        Vista/ventanajuego.ui
        Modelo/Fabrica.cpp
        Modelo/Fabrica.h
        Modelo/structs.h
)
target_link_libraries(Elementos PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

configure_file(configuracion.txt ${CMAKE_CURRENT_BINARY_DIR}/configuracion.txt COPYONLY)

set_target_properties(Elementos PROPERTIES
        AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/Vista"
)