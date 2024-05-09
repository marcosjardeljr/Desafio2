/*
Desafio 2
Marcos Jardel Murillo Hernandez  -  C.C.1017238240
Juan David Escalante Fonseca  -  C.C. 1054091027
*/

#include "redmetro.h"
#include <iostream>
#include "lineametro.h"

void mostrarMenu();
using namespace std;

int main()
{

    mostrarMenu();
    return 0;
}


void mostrarMenu() {
    redMetro redMetro; // Creamos un objeto de la clase red Metro donde administramos las lineas
    string nombreLinea, nombreEstacion, origen, destino;
    int posicion; // Almacenamos la posicion de una estacion dentro de una linea
    char opcion;
    bool conexionEstablecida = false; // Flag para verificar si se ha establecido una conexión (estacion de transf).
    do {
        cout << "BIENVENIDO A SU RED METRO" << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "A. Agregar una estacion a una linea." << endl;
        cout << "B. Eliminar una estacion de una linea." << endl;
        cout << "C. Saber cuantas lineas tiene la red Metro." << endl;
        cout << "D. Saber cuantas estaciones tiene una linea." << endl;
        cout << "E. Saber si una estacion dada pertenece a una linea especifica." << endl;
        cout << "F. Agregar una linea a la red Metro." << endl;
        cout << "G. Eliminar una linea de la red Metro." << endl;
        cout << "H. Saber cuantas estaciones tiene la red Metro." << endl;
        cout << "I. tiempo entre estaciones." << endl;
        cout << "X. Salir." << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 'A':
            {
                int tiempo; // almacenamos el tiempo entre estaciones.

                cout << "Ingrese el nombre de la linea: ";
                cin.ignore();
                getline(cin, nombreLinea);
                cout << "Ingrese el nombre de la estacion: ";
                getline(cin, nombreEstacion);
                cout << "Ingrese la posicion (ingrese -1 para agregar al final): ";
                cin >> posicion;

                // Busca la linea por nombre.
                lineaMetro* linea = redMetro.buscarLinea(nombreLinea);
                if (linea != nullptr) { //verificamos que la linea exista
                    if (!linea->estacionExiste(nombreEstacion)) { // Verifica que la estación no exista ya en la línea.
                        if (linea->esPosicionValida(posicion)) {  // Verifica que la posición sea válida.
                            Estacion* estacion = new Estacion(nombreEstacion); // se crea la estacion
                            if (linea->agregarEstacion(estacion, posicion)) { // Se agrega la estación a la linea
                                cout << "Estacion agregada correctamente.\n";
                                cout << "Ingrese tiempo en segundos hasta la siguiente estacion: ";
                                cin >> tiempo;
                                linea->setTiempoEntreEstaciones(posicion, tiempo); // Establece el tiempo entre estaciones.
                            } else {
                                cout << "Error al agregar la estacion.\n";
                                delete estacion; // se libera la memoria de la estacion no agregada
                            }
                        } else {
                            cout << "La posicion no es valida.\n";
                        }
                    } else {
                        cout << "La estacion ya existe.\n";
                    }
                } else {
                    cout << "Linea no encontrada.\n";
                }

            break;
            }
            case 'B':
            {
                cout << "Ingrese el nombre de la linea de la cual eliminar la estacion: ";
                cin.ignore();
                getline(cin, nombreLinea);
                cout << "Ingrese el nombre de la estacion a eliminar: ";
                getline(cin, nombreEstacion);
                // Busca la linea por nombre.
                lineaMetro* linea = redMetro.buscarLinea(nombreLinea);
                if (linea != nullptr) // Se verifica que la linea exista.
                {
                    if (linea->eliminarEstacion(nombreEstacion)) { // Se elimina la estacion si la linea existe
                    cout << "Estacion eliminada correctamente.\n";
                }
                    else
                    {
                    cout << "No se pudo eliminar la estacion (puede ser de transferencia o no existir).\n";
                    }
                }
                else
                {
                    cout << "Linea no encontrada.\n";
                }

                break;
            }
            case 'C':
            {
                cout << "La red tiene " << redMetro.getCantidadLineas() << " lineas.\n";
                redMetro.mostrarLineas();
                break;
            }
            case 'D':
            {
                cout << "Ingrese el nombre de la linea: ";
                cin.ignore();
                getline(cin, nombreLinea);
                lineaMetro* linea = redMetro.buscarLinea(nombreLinea);
                if (linea != nullptr) // Se verifica que la linea exista
                {
                    cout << "La linea " << nombreLinea << " tiene " << linea->getCantidadEstaciones() << " estaciones.";
                }
                else
                {
                    cout << "Linea no encontrada.\n";
                }
                break;
            }
            case 'E':
            {
                cout << "Ingrese el nombre de la estacion: ";
                cin.ignore();
                getline(cin, nombreEstacion);
                cout << "Ingrese el nombre de la linea: ";
                getline(cin, nombreLinea);
                lineaMetro* linea = redMetro.buscarLinea(nombreLinea);
                if (linea != nullptr)
                {
                    if (linea->contieneEstacion(nombreEstacion)) // Verifica si la estacion pertenece a la linea.
                    {
                    cout << "La estacion " << nombreEstacion << " pertenece a la linea " << nombreLinea << ".";
                    }
                    else
                    {
                        cout << "La estacion no pertenece a la linea.";
                    }
                }
                else
                {
                    cout << "Linea no encontrada.";
                }
                break;
            }
            case 'F':
            {
                bool nombreValido = false; // Variable para controlar la validez del nombre de la nueva linea.
                do {
                    cout << "Ingrese el nombre de la nueva linea: ";
                    cin.ignore();
                    getline(cin, nombreLinea);
                    if (redMetro.lineaExiste(nombreLinea)) {
                    cout << "Una linea con ese nombre ya existe. Por favor, elija un nombre diferente." << endl;
                } else {
                    nombreValido = true;
                }
                } while (!nombreValido);
            lineaMetro* nuevaLinea = new lineaMetro(nombreLinea); // Creamos una nueva linea
            if (redMetro.getCantidadLineas() > 0) { // se verifica si hay lineas existentes para posibles conexiones.
                cout << "Lineas disponibles para conectar:\n";
                for (int i = 0; i < redMetro.getCantidadLineas(); ++i) {  // se itera sobre las lineas existentes.
                    cout << i + 1 << ". " << redMetro.buscarLineaPorIndice(i)->getNombre() << endl;
                }
                cout << "Seleccione el numero de linea para conectar: ";
                int indiceLinea;
                cin >> indiceLinea;
                cin.ignore();

                if (indiceLinea > 0 && indiceLinea <= redMetro.getCantidadLineas()) { // se verifica que el indice sea valido.
                    lineaMetro* lineaConectar = redMetro.buscarLineaPorIndice(indiceLinea - 1); // se obtiene la linea a conectar.
                    if (lineaConectar->getCantidadEstaciones() > 0) { // se verifica que la linea a conectar tenga estaciones.
                        cout << "Estaciones disponibles en " << lineaConectar->getNombre() << endl;
                        for (int j = 0; j < lineaConectar->getCantidadEstaciones(); ++j) {
                            cout << j + 1 << ". " << lineaConectar->getEstacion(j)->getNombre() << endl; // se muestra cada estacion disponible
                        }
                        cout << "Seleccione el numero de estacion para conectar como estacion de transferencia: ";
                        int indiceEstacion;
                        cin >> indiceEstacion;
                        cin.ignore();
                        // seVerifica que el indice de la estacion sea valido.
                        if (indiceEstacion > 0 && indiceEstacion <= lineaConectar->getCantidadEstaciones()) {
                            Estacion* estacionConectar = lineaConectar->getEstacion(indiceEstacion - 1);
                            estacionConectar->marcarComoTransferencia(); // se marca la estacion como de transferencia.
                            // Se agrega la estación como de transferencia a la nueva linea.
                            nuevaLinea->agregarEstacion(new Estacion(estacionConectar->getNombre(), true));
                            conexionEstablecida = true;
                        } else {
                            cout << "Numero de estacion no valido. No se agregara la linea." << endl;
                            conexionEstablecida = false;
                        }
                    } else {
                        cout << "No hay estaciones disponibles para conectar. No se agregara la linea." << endl;
                        conexionEstablecida = false;
                    }
                } else {
                    cout << "Numero de linea no valido. No se agregara la linea." << endl;
                    conexionEstablecida = false;
                }
            } else {
                cout << "No hay lineas existentes. La nueva linea se agregara sin necesidad de conexion de transferencia." << endl;
                conexionEstablecida = true;
            }

            // solo se agrega la linea si se ha establecido una conexion valida.
            if (conexionEstablecida) {
                redMetro.agregarLinea(nuevaLinea);
                cout << "Linea agregada correctamente." << endl;
            } else {
                delete nuevaLinea; // Se libera la memoria si la linea no se agrega.
            }
                 break;
            }
            case 'G':
            {
                cout << "Ingrese el nombre de la linea: ";
                cin.ignore();
                getline(cin, nombreLinea);
                lineaMetro* linea = redMetro.buscarLinea(nombreLinea);
                if (linea != nullptr)
                {
                    if (redMetro.getCantidadLineas() >= 2) {
                        cout << "No se puede eliminar la linea porque ya estan conectadas por medio de estaciones de transferencia.";
                    }
                    else
                    {
                        if (redMetro.eliminarLinea(nombreLinea))
                        {
                            cout << "Linea eliminada exitosamente.";
                        }
                        else
                        {
                            cout << "Error al eliminar la linea.";
                        }
                    }
                }
                else
                {
                cout << "Linea no encontrada.";
                }
                break;
            }
            case 'H':
            {
                cout << "La red tiene un total de " << redMetro.getTotalEstaciones() << " estaciones.\n";
                break;
            }
            case 'I':
            {
                cout << "Ingrese el nombre de la linea para calcular el tiempo entre estaciones: ";
                cin.ignore();
                getline(cin, nombreLinea);
                lineaMetro* linea = redMetro.buscarLinea(nombreLinea);
                linea = redMetro.buscarLinea(nombreLinea);  // Obtener la línea correcta
                if (linea != nullptr)
                {
                    cout << "Ingrese el nombre de la estacion de origen: ";
                    getline(cin, origen);
                    cout << "Ingrese el nombre de la estacion de destino: ";
                    getline(cin, destino);
                    int tiempo = linea->calcularTiempoDeLlegada(origen, destino);
                    if (tiempo > 0)
                    {
                        cout << "Tiempo estimado de llegada: " << tiempo << " segundos.\n";
                    }
                    else
                    {
                        cout << "No se pudo calcular el tiempo de llegada. Asegurese de que las estaciones ingresadas son correctas y pertenecen a la linea.\n";
                    }
                }
                else
                {
                    cout << "Linea no encontrada. Por favor, verifique el nombre e intente de nuevo." << endl;
                }

                break;
            }
            case 'X':
            {
                break;
            }
            default:
                cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
        }
    } while(opcion != 'X');
}

