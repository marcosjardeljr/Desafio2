#ifndef REDMETRO_H
#define REDMETRO_H
#include <lineametro.h>

class redMetro
{
private:
    lineaMetro** lineas;
    int cantidadLineas;
    int capacidadLineas;
public:
    redMetro();
    ~redMetro();
    bool agregarLinea(lineaMetro* linea);
    bool eliminarLinea(const char* nom);
    int getTotalEstaciones() const;
    int getCantidadLineas() const;
    lineaMetro* buscarLinea(const char* nombre) const;
};

#endif // REDMETRO_H
