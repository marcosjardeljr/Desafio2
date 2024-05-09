#include "lineametro.h"
#include <iostream>


lineaMetro::lineaMetro
(const string& nom) : nombre(nom), estaciones(nullptr), cantidadEstaciones(0), capacidadEstaciones(5)
{
    estaciones = new Estacion*[capacidadEstaciones];
    tiempos = new int[capacidadEstaciones];
}

lineaMetro::~lineaMetro() {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        delete estaciones[i];
    }
    delete[] estaciones;
    delete[] tiempos;
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
        int* nuevosTiempos = new int[capacidadEstaciones - 1];
        for (int i = 0; i < cantidadEstaciones; ++i) {
            nuevoArray[i] = estaciones[i];
            if (i < cantidadEstaciones - 1) {
                nuevosTiempos[i] = tiempos[i];
            }
        }
        delete[] estaciones;
        delete[] tiempos;
        estaciones = nuevoArray;
        tiempos = nuevosTiempos;
    }

    for (int i = cantidadEstaciones; i > posicion; --i) {
        estaciones[i] = estaciones[i - 1];
        tiempos[i] = tiempos[i - 1];
    }
    estaciones[posicion] = estacion;
    tiempos[posicion] = 0;
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

int lineaMetro::calcularTiempoDeLlegada(const string& origen, const string& destino) const {
    if (!contieneEstacion(origen) || !contieneEstacion(destino)) {
        return -1;
    }

    int tiempoTotal = 0;
    bool empezarConteo = false;

    for (int i = 0; i < cantidadEstaciones - 1; ++i) {
        if (estaciones[i]->getNombre() == origen) {
            empezarConteo = true;
        }
        if (empezarConteo) {
            tiempoTotal += tiempos[i];
            if (estaciones[i+1]->getNombre() == destino) {
                return tiempoTotal;
            }
        }
    }

    return -1;
}
