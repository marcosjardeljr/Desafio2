#ifndef ESTACION_H
#define ESTACION_H
#include <string>

using namespace std;

class Estacion {
private:
    string nombre;
    bool esTransferencia;

public:
    Estacion(const string& nom, bool transferencia = false); // Check this declaration
    const string& getNombre() const;
    bool esEstacionDeTransferencia() const;
};

#endif // ESTACION_H
