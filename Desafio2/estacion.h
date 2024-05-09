#ifndef ESTACION_H
#define ESTACION_H
#include <string>

using namespace std;

class Estacion { // se definde la clase estacion
private:
    string nombre; // Variable privada para almacenar el nombre de la estación
    bool esTransferencia; // Variable privada para indicar si la estación es de transferencia
    int tiempoHastaSiguiente; // Variable privada para almacenar el tiempo hasta la siguiente estación

public:
    // Constructor de la clase que permite inicializar el nombre, si es estación de transferencia y el tiempo hasta la siguiente
    Estacion(const string& nom, bool transferencia = false, int tiempoSiguiente = 0);
    const string& getNombre() const;  // Funcion constante que devuelve una referencia al nombre de la estacion
    bool esEstacionDeTransferencia() const;  // Funcion constante que indica si la estacion es de transferencia
    void marcarComoTransferencia();
    int getTiempoHastaSiguiente() const;
    void setTiempoHastaSiguiente(int tiempo);


};

#endif // ESTACION_H
