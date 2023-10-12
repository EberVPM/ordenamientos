#ifndef LISTA_H
#define LSITA_H
#include <iostream>

const int TAM = 100;

class Constancia {
    private:
        std::string nombre, carrera, preparatoria;
        float promedio;
    public:
        Constancia();
        Constancia(std::string n, std::string c, int m, float p);
        friend bool operator == (Constancia& c1, Constancia& c2);
        friend bool operator != (Constancia& c1, Constancia& c2);
        friend bool operator < (Constancia& c1, Constancia& c2);
        friend bool operator > (Constancia& c1, Constancia& c2);
        friend bool operator >= (Constancia& c1, Constancia& c2);
        friend bool operator <= (Constancia& c1, Constancia& c2);
        friend std::istream& operator >> (std::istream& i, Constancia& c);
        friend std::ostream& operator << (std::ostream& o, Constancia& c);
};

class Lista {
    private:
        Constancia constancias[100];
        int ult;
        bool elimina(int posicion);
        int inserta(Constancia& constancia, int posicion);
    public:
        Lista(): ult(-1) {}
        bool vacia() const;
        bool llena() const;
        int ultimo() const;
        friend std::ostream& operator << (std::ostream & o, Lista& l);
        void agrega(Constancia& constamcia);
        Constancia& dequeue();
        int busquedaLineal(Constancia& constancia);
        void insercion();
        int busquedaBinaria(Constancia constancia);
        void print(int posicion);
};

#endif // Lista_H
