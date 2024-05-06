#include "estacion.h"

/*Estacion::Estacion()
{

}
*/
const string& Estacion::getNombre() const {
    return nombre;
}
//Estacion::Estacion(const string&// nom)  {}

/*
Estacion::Estacion(const std::string& nom, bool transferencia) {
    nombre = nom;
    esTransferencia = transferencia;
}
*/
Estacion::Estacion(const std::string& nom) : nombre(nom) {}


bool Estacion::esEstacionDeTransferencia() const {
    return esTransferencia;
}

void Estacion::marcarComoTransferencia() {
    esTransferencia = true;
}


