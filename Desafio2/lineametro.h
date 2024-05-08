#ifndef LINEAMETRO_H
#define LINEAMETRO_H

#include <estacion.h>
#include <string>

class lineaMetro {
private:
    string nombre;
    Estacion** estaciones;
    int cantidadEstaciones;
    int capacidadEstaciones;

public:
    lineaMetro(const string& nom);
    ~lineaMetro();
    bool agregarEstacion(Estacion* estacion, int posicion = -1);
    bool eliminarEstacion(const string& nom);
    int getCantidadEstaciones() const;
    bool contieneEstacion(const string& nom) const;
    const string& getNombre() const;
    bool estacionExiste(const std::string& nom) const;
    bool esPosicionValida(int posicion) const;
};

#endif // LINEAMETRO_H
