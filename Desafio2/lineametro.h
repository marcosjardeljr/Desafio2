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
    int tiempos[17];  // Tiempos entre estaciones consecutivas
    int numEstaciones;

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
    Estacion* getEstacion(int index) const;
    void setTiempoEntreEstaciones(int index, int tiempo);
    int calcularTiempoDeLlegada(const string& origen, const string& destino) const;
};

#endif // LINEAMETRO_H
