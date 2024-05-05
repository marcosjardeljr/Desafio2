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
                cout << "Ingrese el nombre de la nueva linea: ";
                cin.ignore();
                getline(cin, nombreLinea);
                lineaMetro* nuevaLinea = new lineaMetro(nombreLinea);
                redMetro.agregarLinea(nuevaLinea);
                cout << "Linea agregada correctamente.\n";
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
