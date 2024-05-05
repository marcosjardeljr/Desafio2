#include "redmetro.h"


redMetro::redMetro() {
    capacidadLineas = 2;
    lineas = new lineaMetro*[capacidadLineas];
    cantidadLineas = 0;
}

redMetro::~redMetro() {
    for (int i = 0; i < cantidadLineas; ++i) {
        delete lineas[i];
    }
    delete[] lineas;
}

bool redMetro::agregarLinea(lineaMetro* linea) {
    if (cantidadLineas == capacidadLineas) {
        capacidadLineas *= 2;
        lineaMetro** nuevoArray = new lineaMetro*[capacidadLineas];
        for (int i = 0; i < cantidadLineas; ++i) {
            nuevoArray[i] = lineas[i];
        }
        delete[] lineas;
        lineas = nuevoArray;
    }
    lineas[cantidadLineas++] = linea;
    return true;
}

