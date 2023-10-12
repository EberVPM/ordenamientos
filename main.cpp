#include <iostream>
#include "Lista.h"

int main() {
    int opcion;
    Lista lista;
    Constancia constancia;

    do {
        std::cout << "1. Dar de alta la solicitud de un alumno" << std::endl;
        std::cout << "2. Buscar una solicitud" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                if (lista.llena()) {
                    std::cout << "La lista esta llena" << std::endl;
                } else {
                    std::cin >> constancia;
                    lista.agrega(constancia);
                }
                break;
            case 2:
                if (lista.vacia()) {
                    std::cout << "No hay solicitudes" << std::endl;
                } else {
                    std::cout << "Ingrese la solicitud a buscar: " << std::endl;
                    std::cin >> constancia;

                    int posicion = lista.busquedaBinaria(constancia);

                    if (posicion != -1) {
                        std::cout << "Posicion: " << posicion << std::endl;
                        std::cout << "Datos del alumno: " << std::endl;
                        lista.print(posicion - 1);
                    } else {
                        std::cout << "Primero debes de dar de alta una solicitud" << std::endl;
                    }
                }
                break;
            case 3:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion incorrecta" << std::endl;
        }
    } while (opcion != 3);

    return 0;
}
