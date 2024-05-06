#ifndef REDMETRO_H
#define REDMETRO_H
#include <lineametro.h>
#include<iostream>
#include<cstring>

using namespace std;
class redMetro
{
private:
    lineaMetro** lineas;
    int cantidadLineas;
    int capacidadLineas;
    string nombre;
public:
    redMetro();
    ~redMetro();
    bool agregarLinea(lineaMetro* linea);
    bool eliminarLinea(const string& nom);
    int getTotalEstaciones() const;
    int getCantidadLineas() const;
    lineaMetro* buscarLinea(const string& nombre) const;
    lineaMetro* buscarLineaPorIndice(int index) const;
    void mostrarLineas() const;

};

#endif // REDMETRO_H
