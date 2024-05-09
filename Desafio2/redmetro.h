#ifndef REDMETRO_H
#define REDMETRO_H
#include <lineametro.h>
#include<iostream>
#include<cstring>

using namespace std;
class redMetro
{
private:
    lineaMetro** lineas; // arreglo de punteros a objetos lineaMetro
    int cantidadLineas;
    int capacidadLineas;
public:
    redMetro(); // Constructor que inicializa la red de metro
    ~redMetro();
    bool agregarLinea(lineaMetro* linea);
    bool eliminarLinea(const string& nom);
    int getTotalEstaciones() const;
    int getCantidadLineas() const;
    lineaMetro* buscarLinea(const string& nombre) const; // buscamos una linea por nombre y devuelve un puntero si la encuentra
    void mostrarLineas() const;
    lineaMetro* buscarLineaPorIndice(int index) const; // Busca una linea por su indice en el arreglo
    bool lineaExiste(const string& nombre) const;
};

#endif // REDMETRO_H
