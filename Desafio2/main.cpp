/*
Desafio 2
Marcos Jardel Murillo Hernandez  -  C.C.1017238240
Juan David Escalante Fonseca  -  C.C. 1054091027
*/

#include "redMetro.h"
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
    char nombreLinea[100];
    char nombreEstacion[100];
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
                cout << "Ingrese el nombre de la línea: ";
                cin.getline(nombreLinea, 100);
                cout << "Ingrese el nombre de la estación: ";
                cin.getline(nombreEstacion, 100);
                cout << "Ingrese la posición (ingrese -1 para añadir al final): ";
                cin >> posicion;
                lineaMetro* linea = redMetro.buscarLinea(nombreLinea);
                if (linea != nullptr) {
                    /*Estacion* estacion = new Estacion(nombreEstacion);
                    linea->agregarEstacion(estacion, posicion);
                    cout << "Estación agregada correctamente.\n";
                } else {
                    cout << "Línea no encontrada.\n";*/
                }
                break;
            }
            case 'B':
            {
                break;
            }
            case 'C':
            {
                break;
            }
            case 'D':
            {
                break;
            }
            case 'E':
            {
                break;
            }
            case 'F':
            {
                break;
            }
            case 'G':
            {
                break;
            }
            case 'H':
            {
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
