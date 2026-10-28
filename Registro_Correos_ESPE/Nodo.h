#ifndef NODO_H
#define NODO_H
#include "Persona.h"
class Nodo {
private:
    Persona dato;
    Nodo* siguiente;
    Nodo* anterior;
public:
    Nodo();
    Nodo(Persona dato);
    const Persona& getDato() const;
    Nodo* getSiguiente() const;
    void setSiguiente(Nodo* siguiente);
    Nodo* getAnterior() const;
    void setAnterior(Nodo* anterior);
};
#endif
