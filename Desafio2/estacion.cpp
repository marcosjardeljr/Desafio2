#include "estacion.h"
#include <cstring>
using namespace std;

Estacion::Estacion(const string& nom, bool transferencia, int tiempoSiguiente) :
    nombre(nom), esTransferencia(transferencia),tiempoHastaSiguiente(tiempoSiguiente)  {

}

const string& Estacion::getNombre() const {
    return nombre;
}

bool Estacion::esEstacionDeTransferencia() const {
    return esTransferencia;
}


void Estacion::marcarComoTransferencia() {
        esTransferencia = true;
    }
int Estacion::getTiempoHastaSiguiente() const {
    return tiempoHastaSiguiente;
}

void Estacion::setTiempoHastaSiguiente(int tiempo) {
    tiempoHastaSiguiente = tiempo;
}
