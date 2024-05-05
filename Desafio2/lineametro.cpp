#include "lineametro.h"


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


