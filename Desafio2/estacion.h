#ifndef ESTACION_H
#define ESTACION_H
#include <string>

using namespace std;

class Estacion {
private:
    string nombre;
    bool esTransferencia;

public:
    Estacion(const std::string& nom);
    const string& getNombre() const;
    bool esEstacionDeTransferencia() const;
    void marcarComoTransferencia();
};

#endif // ESTACION_H
