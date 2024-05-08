#ifndef ESTACION_H
#define ESTACION_H
#include <string>

using namespace std;

class Estacion {
private:
    string nombre;
    bool esTransferencia;
    int tiempoHastaSiguiente;

public:
    Estacion(const string& nom, bool transferencia = false, int tiempoSiguiente = 0);
    const string& getNombre() const;
    bool esEstacionDeTransferencia() const;
    void marcarComoTransferencia();
    int getTiempoHastaSiguiente() const;
    void setTiempoHastaSiguiente(int tiempo);

};

#endif // ESTACION_H
