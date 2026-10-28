#include "Persona.h"
Persona::Persona() {}
Persona::Persona(string cedula, string primerNombre, string segundoNombre, string primerApellido, string segundoApellido, string correo) {
    this->cedula = cedula;
    this->primerNombre = primerNombre;
    this->segundoNombre = segundoNombre;
    this->primerApellido = primerApellido;
    this->segundoApellido = segundoApellido;
    this->correo = correo;
}
string Persona::getCedula() const { return cedula; }
string Persona::getPrimerNombre() const { return primerNombre; }
string Persona::getSegundoNombre() const { return segundoNombre; }
string Persona::getPrimerApellido() const { return primerApellido; }
string Persona::getSegundoApellido() const { return segundoApellido; }
string Persona::getCorreo() const { return correo; }
