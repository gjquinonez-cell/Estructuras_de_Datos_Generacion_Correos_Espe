#include "Nodo.h"
Nodo::Nodo() { siguiente = nullptr; anterior = nullptr; }
Nodo::Nodo(Persona dato) {
    this->dato = dato;
    siguiente = nullptr;
    anterior = nullptr;
}
const Persona& Nodo::getDato() const { return dato; }
Nodo* Nodo::getSiguiente() const { return siguiente; }
void Nodo::setSiguiente(Nodo* siguiente) { this->siguiente = siguiente; }
Nodo* Nodo::getAnterior() const { return anterior; }
void Nodo::setAnterior(Nodo* anterior) { this->anterior = anterior; }
