# Estructuras_de_Datos_Generacion_Correos_Espe
En este repositorio se encontraran los archivos necesarios para la generacion de correos electronicos con dominio "@espe.edu.ec" usando listas dobles
# Generación de correos ESPE

Programa en C++ que registra personas en una lista doblemente enlazada y genera correos con el dominio `@espe.edu.ec`.

## Funcionamiento

Se ingresa la cédula, los nombres y los apellidos. El correo se forma con:

- Inicial del primer nombre.
- Inicial del segundo nombre o `_` si no tiene.
- Primer apellido.

Los correos se generan en minúsculas y sin tildes. Si se repiten, se agrega un número consecutivo.

Ejemplos:
- `gjquinonez@espe.edu.ec`
- `gjquinonez1@espe.edu.ec`
- `e_lascano@espe.edu.ec`

Los registros se guardan en `personas.txt` y se recuperan al iniciar el programa.

## Compilar y ejecutar

Abra la carpeta en VS Code y ejecute en la terminal:

```powershell
g++ -std=c++17 main.cpp Persona.cpp Nodo.cpp ListaDoble.cpp -o programa.exe
.\programa.exe
```

Requiere tener instalado `g++`.

## Menú

1. Registrar persona.
2. Mostrar personas.
3. Salir.

El programa genera direcciones como texto; no crea cuentas de correo reales.
