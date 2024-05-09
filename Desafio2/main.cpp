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
    redMetro redMetro;
    string nombreLinea;
    string nombreEstacion;
    string origen, destino;
    int posicion;
    char opcion;
    bool conexionEstablecida = false;
    do {
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
                int tiempo;

                cout << "Ingrese el nombre de la linea: ";
                cin.ignore();
                getline(cin, nombreLinea);
                cout << "Ingrese el nombre de la estacion: ";
                getline(cin, nombreEstacion);
                cout << "Ingrese la posicion (ingrese -1 para agregar al final): ";
                cin >> posicion;

                lineaMetro* linea = redMetro.buscarLinea(nombreLinea);
                if (linea != nullptr) {
                    if (!linea->estacionExiste(nombreEstacion)) {
                        if (linea->esPosicionValida(posicion)) {
                            Estacion* estacion = new Estacion(nombreEstacion);
                            if (linea->agregarEstacion(estacion, posicion)) {
                                cout << "Estacion agregada correctamente.\n";
                                cout << "Ingrese tiempo en segundos hasta la siguiente estacion: ";
                                cin >> tiempo;
                                linea->setTiempoEntreEstaciones(posicion, tiempo);
                            } else {
                                cout << "Error al agregar la estacion.\n";
                                delete estacion;
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
                lineaMetro* linea = redMetro.buscarLinea(nombreLinea);
                if (linea != nullptr)
                {
                    if (linea->eliminarEstacion(nombreEstacion)) {
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
                if (linea != nullptr)
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
                //cin.ignore();
                getline(cin, nombreLinea);
                lineaMetro* linea = redMetro.buscarLinea(nombreLinea);
                if (linea != nullptr)
                {
                    if (linea->contieneEstacion(nombreEstacion))
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
                bool nombreValido = false;
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
            lineaMetro* nuevaLinea = new lineaMetro(nombreLinea);
            if (redMetro.getCantidadLineas() > 0) {
                cout << "Lineas disponibles para conectar:\n";
                for (int i = 0; i < redMetro.getCantidadLineas(); ++i) {
                    cout << i + 1 << ". " << redMetro.buscarLineaPorIndice(i)->getNombre() << "\n";
                }
                cout << "Seleccione el numero de linea para conectar: ";
                int indiceLinea;
                cin >> indiceLinea;
                cin.ignore();

                if (indiceLinea > 0 && indiceLinea <= redMetro.getCantidadLineas()) {
                    lineaMetro* lineaConectar = redMetro.buscarLineaPorIndice(indiceLinea - 1);
                    if (lineaConectar->getCantidadEstaciones() > 0) {
                        cout << "Estaciones disponibles en " << lineaConectar->getNombre() << ":\n";
                        for (int j = 0; j < lineaConectar->getCantidadEstaciones(); ++j) {
                            cout << j + 1 << ". " << lineaConectar->getEstacion(j)->getNombre() << "\n";
                        }
                        cout << "Seleccione el numero de estacion para conectar como estacion de transferencia: ";
                        int indiceEstacion;
                        cin >> indiceEstacion;
                        cin.ignore();

                        if (indiceEstacion > 0 && indiceEstacion <= lineaConectar->getCantidadEstaciones()) {
                            Estacion* estacionConectar = lineaConectar->getEstacion(indiceEstacion - 1);
                            estacionConectar->marcarComoTransferencia();
                            nuevaLinea->agregarEstacion(new Estacion(estacionConectar->getNombre(), true));
                            conexionEstablecida = true;
                        } else {
                            cout << "Numero de estacion no valido. No se agregara la linea." << endl;
                            conexionEstablecida = false; // Asegúrate de setear esto si la entrada no es válida
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

            // Solo agregar la línea si se ha establecido una conexión válida.
            if (conexionEstablecida) {
                redMetro.agregarLinea(nuevaLinea);
                cout << "Linea agregada correctamente." << endl;
            } else {
                delete nuevaLinea; // Limpia la memoria si la línea no se agrega.
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
                    cin.ignore();  // Asegurarse de limpiar el buffer para una entrada limpia
                    getline(cin, nombreLinea);
                    lineaMetro* linea = redMetro.buscarLinea(nombreLinea);
                    linea = redMetro.buscarLinea(nombreLinea);  // Obtener la línea correcta

                    if (linea != nullptr) {
                        cout << "Ingrese el nombre de la estacion de origen: ";
                        getline(cin, origen);
                        cout << "Ingrese el nombre de la estacion de destino: ";
                        getline(cin, destino);

                        int tiempo = linea->calcularTiempoDeLlegada(origen, destino);
                        if (tiempo > 0) {
                            cout << "Tiempo estimado de llegada: " << tiempo << " segundos.\n";
                        } else {
                            cout << "No se pudo calcular el tiempo de llegada. Asegurese de que las estaciones ingresadas son correctas y pertenecen a la linea.\n";
                        }
                    } else {
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
