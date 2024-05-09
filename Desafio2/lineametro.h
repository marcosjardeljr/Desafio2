#ifndef LINEAMETRO_H
#define LINEAMETRO_H
#include <estacion.h>
#include <string>

class lineaMetro {
private:
    string nombre;
    Estacion** estaciones; // almacenamos un arreglo dinamico de punteros a objetos Estacion.
    int cantidadEstaciones;
    int capacidadEstaciones;
    int* tiempos;  // Tiempos entre estaciones consecutivas
    int numEstaciones;

public:
    lineaMetro(const string& nom); // Constructor que inicializa la linea de metro con un nombre.
    ~lineaMetro();
    bool agregarEstacion(Estacion* estacion, int posicion = -1);
    bool eliminarEstacion(const string& nom);
    int getCantidadEstaciones() const;
    bool contieneEstacion(const string& nom) const;
    const string& getNombre() const;
    bool estacionExiste(const string& nom) const;
    bool esPosicionValida(int posicion) const;
    Estacion* getEstacion(int index) const; // Obtiene una estacion en un indice especifico.
    void setTiempoEntreEstaciones(int index, int tiempo);
    int calcularTiempoDeLlegada(const string& origen, const string& destino) const;
};

#endif // LINEAMETRO_H
