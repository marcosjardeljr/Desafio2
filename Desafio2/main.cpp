/*
Desafio 2
Marcos Jardel Murillo Hernandez  -  C.C.1017238240
Juan David Escalante Fonseca  -  C.C. 1054091027
*/

#include "redmetro.h"
#include <iostream>


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
    int posicion;
    char opcion;
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
        cout << "X. Salir." << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 'A':
            {
                cout << "Ingrese el nombre de la linea: ";
                cin.ignore();
                getline(cin, nombreLinea);
                cout << "Ingrese el nombre de la estacion: ";
                getline(cin, nombreEstacion);
                cout << "Ingrese la posicion (ingrese -1 para agregar al final): ";
                cin >> posicion;
                lineaMetro* linea = redMetro.buscarLinea(nombreLinea);
                if (linea != nullptr)
                {
                    if (!linea->estacionExiste(nombreEstacion))
                    {
                        if (linea->esPosicionValida(posicion))
                        {
                        Estacion* estacion = new Estacion(nombreEstacion);
                            if (linea->agregarEstacion(estacion, posicion))
                            {
                                cout << "Estacion agregada correctamente.\n";
                            }
                        else
                        {
                            cout << "Error al agregar la estacion.";
                            delete estacion;
                        }
                    }
                        else
                        {
                            cout << "La posicion no es valida.\n";
                        }
                    }
                    else
                    {
                        cout << "La posicion no es valida.\n";
                    }
                }
                else
                {
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
                cin.ignore();
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
                cout << "Ingrese el nombre de la nueva linea: ";
                cin.ignore();
                getline(cin, nombreLinea);
                if (redMetro.buscarLinea(nombreLinea) != nullptr)
                {
                    cout << "Error: Una linea con ese nombre ya existe. Intente nuevamente con un nombre diferente." << endl;
                }
                else
                {
                    lineaMetro* nuevaLinea = new lineaMetro(nombreLinea);
                    redMetro.agregarLinea(nuevaLinea);
                    cout << "Linea agregada correctamente." << endl;
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
                break;
            }
            case 'X':
            {
                break;
            }
            default:
                cout << "Opción no valida. Por favor, seleccione una opcion valida." << endl;
        }
    } while(opcion != 'X');

}
