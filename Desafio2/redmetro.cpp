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
    return cantidadLineas;
}

lineaMetro* redMetro::buscarLinea(const string& nombre) const {
    for (int i = 0; i < cantidadLineas; ++i) {
        if (lineas[i]->getNombre() == nombre) {
            return lineas[i];
        }
    }
    return nullptr;
}

void redMetro::mostrarLineas() const {
    cout << "Lineas disponibles en la red de metro:\n";
    for (int i = 0; i < cantidadLineas; ++i) {
        cout << (i + 1) << ". " << lineas[i]->getNombre() << "\n";
    }
}

bool redMetro::eliminarLinea(const string& nom){
    for (int i = 0; i < cantidadLineas; ++i) {
        if (lineas[i]->getNombre() == nom) {
            delete lineas[i];
            for (int j = i; j < cantidadLineas - 1; ++j) {
                lineas[j] = lineas[j + 1];
            }
            cantidadLineas--;
            return true;
        }
    }
    return false;
}

int redMetro::getTotalEstaciones() const {
    int total = 0;
    for (int i = 0; i < cantidadLineas; ++i) {
        total += lineas[i]->getCantidadEstaciones();
    }
    return total;
}

lineaMetro* redMetro::buscarLineaPorIndice(int index) const {
    if (index >= 0 && index < cantidadLineas) {
        return lineas[index];
    }
    return nullptr;
}

bool redMetro::lineaExiste(const std::string& nombre) const {
    for (int i = 0; i < cantidadLineas; ++i) {
        if (lineas[i]->getNombre() == nombre) {
            return true;
        }
    }
    return false;
}


