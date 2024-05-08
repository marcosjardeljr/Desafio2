#include "lineametro.h"
#include <iostream>


lineaMetro::lineaMetro
(const string& nom) : nombre(nom), estaciones(nullptr), cantidadEstaciones(0), capacidadEstaciones(5)
{
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

bool lineaMetro::agregarEstacion(Estacion* estacion, int posicion) {
    if (posicion < 0 || posicion > cantidadEstaciones) {
        posicion = cantidadEstaciones;
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

bool lineaMetro::estacionExiste(const string& nom) const {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i]->getNombre() == nom) {
            return true;
        }
    }
    return false;
}

bool lineaMetro::esPosicionValida(int posicion) const {
    return (posicion >= 0 && posicion <= cantidadEstaciones) || posicion == -1;
}

bool lineaMetro::eliminarEstacion(const string& nom) {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i]->getNombre() == nom && !estaciones[i]->esEstacionDeTransferencia()) {
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

int lineaMetro::getCantidadEstaciones() const {
    return cantidadEstaciones;
}

bool lineaMetro::contieneEstacion(const string& nombreEstacion) const {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i]->getNombre() == nombreEstacion) {
            return true;
        }
    }
    return false;
}

Estacion* lineaMetro::getEstacion(int index) const{
        if (index >= 0 && index < cantidadEstaciones) {
            return estaciones[index];
        }
        return nullptr;
    }

void lineaMetro::setTiempoEntreEstaciones(int index, int tiempo) {
    if (index >= 0 && index < numEstaciones - 1) {
        tiempos[index] = tiempo;
    }
}

int lineaMetro::calcularTiempoDeLlegada(const std::string& origen, const std::string& destino) const {
    int tiempoTotal = 0;
    bool empezarConteo = false;

    for (int i = 0; i < cantidadEstaciones; i++) {
        if (estaciones[i]->getNombre() == origen) {
            empezarConteo = true;
        }
        if (empezarConteo) {
            if (estaciones[i]->getNombre() == destino) {
                break;
            }
            tiempoTotal += estaciones[i]->getTiempoHastaSiguiente();
        }
    }

    return tiempoTotal;
}
