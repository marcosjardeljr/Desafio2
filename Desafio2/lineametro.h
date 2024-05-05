#ifndef LINEAMETRO_H
#define LINEAMETRO_H
#include "Estacion.h"

class lineaMetro {
private:
    char* nombre;
    Estacion** estaciones;
    int cantidadEstaciones;
    int capacidadEstaciones;

public:
    lineaMetro(const char* nom);
    ~lineaMetro();

};

#endif // LINEAMETRO_H
