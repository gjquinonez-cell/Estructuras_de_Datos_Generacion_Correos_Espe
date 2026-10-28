#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "Nodo.h"
#include <string>
using namespace std;
class ListaDoble {
private:
    Nodo* cabeza;
    Nodo* cola;
    void insertar(Persona persona);
    bool existeCorreo(string correo) const;
    string normalizar(string texto) const;
    string generarCorreo(string primerNombre, string segundoNombre,
                         string primerApellido) const;
public:
    ListaDoble();
    ~ListaDoble();
    ListaDoble(const ListaDoble&) = delete;
    ListaDoble& operator=(const ListaDoble&) = delete;
    bool registrar(string cedula, string primerNombre, string segundoNombre,
                   string primerApellido, string segundoApellido, string archivo);
    void mostrar() const;
    void cargarArchivo(string archivo);
};
#endif
