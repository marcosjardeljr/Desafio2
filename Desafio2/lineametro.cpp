#include "lineametro.h"
#include <iostream>

lineaMetro::lineaMetro
(const string& nom) : nombre(nom), estaciones(nullptr), cantidadEstaciones(0), capacidadEstaciones(0)
{
    capacidadEstaciones = 5;
    estaciones = new Estacion*[capacidadEstaciones];
}

lineaMetro::~lineaMetro() {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        delete estaciones[i];
    }
    delete[] estaciones;
}

const string& lineaMetro::getNombre() const {
    return nombre;
}

void lineaMetro::imprimirEstaciones() const {
    cout << "Estaciones en la linea " << nombre << ":\n";
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i] != nullptr) {
            cout << i + 1 << ". " << estaciones[i]->getNombre() << "\n";
        } else {
            cout << i + 1 << ". [Estacion no disponible]\n";
        }
    }
    if (cantidadEstaciones == 0) {
        cout << "No hay estaciones en esta linea.\n";
    }
}

bool lineaMetro::agregarEstacion(Estacion* estacion, int posicion) {
    if (posicion < 0 || posicion > cantidadEstaciones) {
        posicion = cantidadEstaciones; // Agregar al final si la posición no es válida
    }
    if (cantidadEstaciones == capacidadEstaciones) {
        capacidadEstaciones *= 2;
        Estacion** nuevoArray = new Estacion*[capacidadEstaciones];
        for (int i = 0; i < cantidadEstaciones; ++i) {
            nuevoArray[i] = estaciones[i];
        }
        delete[] estaciones;
        estaciones = nuevoArray;
    }
    for (int i = cantidadEstaciones; i > posicion; --i) {
        estaciones[i] = estaciones[i - 1];
    }
    estaciones[posicion] = estacion;
    cantidadEstaciones++;
    return true;
}
/*
bool lineaMetro::contieneEstacion(const string& nom) const {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i]->getNombre() == nom) {
            return true;
        }
    }
    return false;
}
*/
bool lineaMetro::contieneEstacion(const string& nombreEstacion) const {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i]->getNombre() == nombreEstacion) {
            return true;
        }
    }
    return false;
}

Estacion* lineaMetro::getEstacion(int index) const {
    if (index >= 0 && index < cantidadEstaciones) {
        return estaciones[index];
    }
    return nullptr;
}
int lineaMetro::getCantidadEstaciones() const {
    return cantidadEstaciones;
}

bool lineaMetro::eliminarEstacion(const string& nom) {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i]->getNombre() == nom) {
            delete estaciones[i];
            for (int j = i; j < cantidadEstaciones - 1; ++j) {
                estaciones[j] = estaciones[j + 1];
            }
            cantidadEstaciones--;
            return true;
        }
    }
    return false;
}
