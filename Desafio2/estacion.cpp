#include "estacion.h"
#include <cstring>
using namespace std;

Estacion::Estacion(const string& nom, bool transferencia) : nombre(nom), esTransferencia(transferencia) {

}

const string& Estacion::getNombre() const {
    return nombre;
}

bool Estacion::esEstacionDeTransferencia() const {
    return esTransferencia;
}
