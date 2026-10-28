#include "ListaDoble.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>
using namespace std;

ListaDoble::ListaDoble() { cabeza = nullptr; cola = nullptr; }
ListaDoble::~ListaDoble() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* auxiliar = actual;
        actual = actual->getSiguiente();
        delete auxiliar;
    }
}

void ListaDoble::insertar(Persona persona) {
    Nodo* nuevo = new Nodo(persona);
    if (cabeza == nullptr) {
        cabeza = nuevo;
        cola = nuevo;
    } else {
        cola->setSiguiente(nuevo);
        nuevo->setAnterior(cola);
        cola = nuevo;
    }
}

bool ListaDoble::existeCorreo(string correo) const {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->getDato().getCorreo() == correo) return true;
        actual = actual->getSiguiente();
    }
    return false;
}

string ListaDoble::normalizar(string texto) const {
    const string originales[] = {
        "á", "é", "í", "ó", "ú", "ü", "ñ",
        "Á", "É", "Í", "Ó", "Ú", "Ü", "Ñ"
    };
    const string reemplazos[] = {
        "a", "e", "i", "o", "u", "u", "n",
        "a", "e", "i", "o", "u", "u", "n"
    };
    for (int i = 0; i < 14; i++) {
        size_t posicion = texto.find(originales[i]);
        while (posicion != string::npos) {
            texto.replace(posicion, originales[i].size(), reemplazos[i]);
            posicion = texto.find(originales[i], posicion + 1);
        }
    }
    string resultado;
    for (size_t i = 0; i < texto.size(); i++) {
        unsigned char caracter = static_cast<unsigned char>(texto[i]);
        if (caracter < 128 && isalpha(caracter))
            resultado += static_cast<char>(tolower(caracter));
    }
    return resultado;
}

string ListaDoble::generarCorreo(string primerNombre, string segundoNombre,
                                string primerApellido) const {
    string nombre1 = normalizar(primerNombre);
    string nombre2 = normalizar(segundoNombre);
    string apellido = normalizar(primerApellido);
    string base;
    base += nombre1[0];
    base += nombre2.empty() ? '_' : nombre2[0];
    base += apellido;
    string dominio = "@espe.edu.ec";
    string correo = base + dominio;
    int numero = 1;
    while (existeCorreo(correo)) {
        correo = base + to_string(numero) + dominio;
        numero++;
    }
    return correo;
}

bool ListaDoble::registrar(string cedula, string primerNombre,
                          string segundoNombre, string primerApellido,
                          string segundoApellido, string archivo) {
    if (normalizar(primerNombre).empty() || normalizar(primerApellido).empty()) {
        cout << "El primer nombre y el primer apellido deben contener letras validas.\n";
        return false;
    }
    if (!segundoNombre.empty() && normalizar(segundoNombre).empty()) {
        cout << "El segundo nombre no es valido.\n";
        return false;
    }
    string correo = generarCorreo(primerNombre, segundoNombre, primerApellido);
    ofstream salida(archivo, ios::app);
    if (!salida) {
        cout << "No se pudo abrir el archivo para guardar.\n";
        return false;
    }
    salida << quoted(cedula) << " " << quoted(primerNombre) << " "
           << quoted(segundoNombre) << " " << quoted(primerApellido) << " "
           << quoted(segundoApellido) << " " << quoted(correo) << "\n";
    salida.close();
    if (!salida) {
        cout << "No se pudo completar el guardado.\n";
        return false;
    }
    Persona persona(cedula, primerNombre, segundoNombre, primerApellido,
                    segundoApellido, correo);
    insertar(persona);
    cout << "\nPersona registrada correctamente.\nCorreo generado: " << correo << "\n";
    return true;
}

void ListaDoble::mostrar() const {
    if (cabeza == nullptr) {
        cout << "\nNo hay personas registradas.\n";
        return;
    }
    Nodo* actual = cabeza;
    int numero = 1;
    while (actual != nullptr) {
        const Persona& persona = actual->getDato();
        cout << "\n---------- Registro " << numero << " ----------\n"
             << "Cedula: " << persona.getCedula() << "\n"
             << "Primer nombre: " << persona.getPrimerNombre() << "\n"
             << "Segundo nombre: " << persona.getSegundoNombre() << "\n"
             << "Primer apellido: " << persona.getPrimerApellido() << "\n"
             << "Segundo apellido: " << persona.getSegundoApellido() << "\n"
             << "Correo: " << persona.getCorreo() << "\n";
        actual = actual->getSiguiente();
        numero++;
    }
}

void ListaDoble::cargarArchivo(string archivo) {
    ifstream entrada(archivo);
    if (!entrada) return;
    string linea;
    int numeroLinea = 0;
    while (getline(entrada, linea)) {
        numeroLinea++;
        if (linea.empty()) continue;
        string cedula, nombre1, nombre2, apellido1, apellido2, correo;
        istringstream registro(linea);
        if (!(registro >> quoted(cedula) >> quoted(nombre1) >> quoted(nombre2)
                       >> quoted(apellido1) >> quoted(apellido2) >> quoted(correo))) {
            cout << "Aviso: registro no valido en la linea " << numeroLinea << ".\n";
            continue;
        }
        insertar(Persona(cedula, nombre1, nombre2, apellido1, apellido2, correo));
    }
}
