#include "Lista.h"

Constancia::Constancia() {
    nombre = " ";
    carrera = " ";
    preparatoria = "";
    promedio = 0;
}

Constancia::Constancia(std::string n, std::string c, int m, float p) {
    nombre = n;
    carrera = c;
    preparatoria = m;
    promedio = p;
}

bool operator == (Constancia& c1, Constancia& c2) {
    return (
        c1.nombre == c2.nombre && c1.carrera == c2.carrera &&
        c1.preparatoria == c2.preparatoria && c1.promedio == c2.promedio
    );
}

bool operator != (Constancia& c1, Constancia& c2) {
    return !(c1 == c2);
}

std::istream& operator >> (std::istream& i, Constancia& c) {
    std::cout << "Nombre del alumno: ";
    i >> c.nombre;

    std::cout << "Carrera del alumno: ";
    i >> c.carrera;

    std::cout << "Preparatoria del alumno: ";
    i >> c.preparatoria;

    std::cout << "Promedio del alumno: ";
    i >> c.promedio;

    return i;
}

std::ostream& operator << (std::ostream& o, Constancia& c) {
    o << "Nombre del alumno: " << c.nombre << std::endl;
    o << "Carrera del alumno: " << c.carrera << std::endl;
    o << "Preparatoria del alumno: " << c.preparatoria << std::endl;
    o << "Promedio del alumno: " << c.promedio << std::endl;

    return o;
}

bool operator < (Constancia& c1, Constancia& c2) {
    return c1.promedio < c2.promedio;
}
bool operator > (Constancia& c1, Constancia& c2) {
    return c1.promedio > c2.promedio;
}
bool operator >= (Constancia& c1, Constancia& c2) {
    return c1.promedio >= c2.promedio;
}
bool operator <= (Constancia& c1, Constancia& c2) {
    return c1.promedio <= c2.promedio;
}

bool Lista::vacia() const {
    if (ult == -1) return true;
    return false;
}

bool Lista::llena() const {
    if (ult == TAM - 1) return true;
    return false;
}

int Lista::ultimo() const {
    return ult;
}

std::ostream& operator << (std::ostream& o, Lista& l) {
    int i = 0;
    std::cout << "\n";

    while (i <= l.ultimo()) {
        o << l.constancias[i];
        i++;
    }

    return o;
}

void Lista::agrega(Constancia& constancia) {
    inserta(constancia, ult + 1);
    insercion();
}

Constancia& Lista::dequeue() {
    ult--;
    return constancias[ult + 1];
}

bool Lista::elimina(int posicion) {
    if (vacia() || posicion < 0 || posicion > ult) {
        return false;
    }

    int i = posicion;
    while(i < ult) {
        constancias[i] = constancias[i + 1];
        i++;
    }

    return true;
}

int Lista::inserta(Constancia& constancia, int posicion) {
    if (llena() || posicion < 0 || posicion > ult + 1) return 0;

    int i = ult + 1;
    while(i > posicion) {
        constancias[i] = constancias[i - 1];
        i--;
    }

    constancias[posicion] = constancia;
    ult++;

    return 1;
}

int Lista::busquedaLineal (Constancia& constancia) {
    if(vacia()){
        return -1;
    }
    int contador = -1;
    for(int i = ult; i >= 0; i--){
        contador++;
        if(constancia == constancias[i]){
            return contador;
        }
    }
    return -1;
}

void Lista::insercion() {
    int i = 1, j;
    Constancia aux;
    while (i <= ult) {
        aux = constancias[i];
        j = i;
        while (j > 0 && aux < constancias[j - 1]) {
            constancias[j] = constancias[j - 1];
            j--;
        }
        if (i != j) {
            constancias[j] = aux;
        }
        i++;
    }
}

int Lista::busquedaBinaria(Constancia constancia) {
    int i = 0, j = ult;

    while(i <= j) {
        int medio = (i + j) / 2;
        if (constancias[medio] == constancia) {
            return (medio - ult) * -1 + 1;
        }

        if (constancia < constancias[medio]) {
            j = medio - 1;
        } else {
            i = medio + 1;
        }
    }

    return -1;
}

void Lista::print(int posicion) {
    std::cout << constancias[(posicion - ult) * -1] << std::endl;
}
