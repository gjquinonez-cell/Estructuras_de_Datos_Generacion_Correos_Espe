#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include <string>
#include <cctype>
#include "ListaDoble.h"

using namespace std;

string limpiarEspacios(string texto) {
    size_t inicio = texto.find_first_not_of(" \t\r");
    size_t fin = texto.find_last_not_of(" \t\r");
    if (inicio == string::npos) return "";
    return texto.substr(inicio, fin - inicio + 1);
}

string pedirTexto(string mensaje, bool obligatorio) {
    string texto;
    do {
        cout << mensaje;
        if (!getline(cin, texto)) return "";
        texto = limpiarEspacios(texto);
        if (obligatorio && texto.empty()) cout << "Este campo es obligatorio.\n";
    } while (obligatorio && texto.empty());
    return texto;
}

// Solo comprueba longitud y digitos, no el digito verificador.
bool cedulaValida(string cedula) {
    if (cedula.size() != 10) return false;
    for (size_t i = 0; i < cedula.size(); i++) {
        if (!isdigit(static_cast<unsigned char>(cedula[i]))) return false;
    }
    return true;
}

int main() {
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif
    ListaDoble lista;
    const string archivo = "personas.txt";
    lista.cargarArchivo(archivo);
    string opcion;
    do {
        cout << "\n=================================\n"
             << "      REGISTRO DE PERSONAS\n"
             << "=================================\n"
             << "1. Registrar persona\n2. Mostrar personas\n3. Salir\n"
             << "Seleccione una opcion: ";
        if (!getline(cin, opcion)) break;
        opcion = limpiarEspacios(opcion);
        if (opcion == "1") {
            string cedula;
            do {
                cedula = pedirTexto("Cedula: ", true);
                if (!cin) break;
                if (!cedulaValida(cedula)) cout << "Ingrese una cedula de 10 digitos.\n";
            } while (!cedulaValida(cedula));
            if (!cin) break;
            string nombre1 = pedirTexto("Primer nombre: ", true);
            string nombre2 = pedirTexto("Segundo nombre (Enter si no tiene): ", false);
            string apellido1 = pedirTexto("Primer apellido: ", true);
            string apellido2 = pedirTexto("Segundo apellido (Enter si no tiene): ", false);
            if (!cin) break;
            lista.registrar(cedula, nombre1, nombre2, apellido1, apellido2, archivo);
        } else if (opcion == "2") {
            lista.mostrar();
        } else if (opcion == "3") {
            cout << "Programa finalizado.\n";
        } else {
            cout << "Opcion incorrecta.\n";
        }
    } while (opcion != "3");
    return 0;
}
