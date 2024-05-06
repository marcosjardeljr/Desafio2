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

int redMetro::getCantidadLineas() const {
    return cantidadLineas;  // Asume que tienes una variable miembro cantidadLineas que manejas adecuadamente.
}

lineaMetro* redMetro::buscarLinea(const string& nombre) const {
    for (int i = 0; i < cantidadLineas; ++i) {
        if (lineas[i]->getNombre() == nombre) {
            return lineas[i];
        }
    }
    return nullptr;  // Retorna nullptr si no se encuentra la línea con el nombre dado.
}

void redMetro::mostrarLineas() const {
    cout << "Lineas disponibles en la red de metro:\n";
    for (int i = 0; i < cantidadLineas; ++i) {
        cout << (i + 1) << ". " << lineas[i]->getNombre() << "\n";
    }
}

