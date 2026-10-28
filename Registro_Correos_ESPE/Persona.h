#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;
class Persona {
private:
    string cedula;
    string primerNombre;
    string segundoNombre;
    string primerApellido;
    string segundoApellido;
    string correo;
public:
    Persona();
    Persona(string cedula, string primerNombre, string segundoNombre, string primerApellido, string segundoApellido, string correo);
    string getCedula() const;
    string getPrimerNombre() const;
    string getSegundoNombre() const;
    string getPrimerApellido() const;
    string getSegundoApellido() const;
    string getCorreo() const;
 };
#endif
