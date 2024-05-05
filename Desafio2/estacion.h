#ifndef ESTACION_H
#define ESTACION_H

class Estacion {
private:
    char* nombre;
    bool esTransferencia;

public:
    Estacion(const char* nom, bool transferencia = false);
    ~Estacion();
};

#endif
