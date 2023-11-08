#ifndef FUNCION_VERIFICAREXISTENCIA_GENERO_H_INCLUDED
#define FUNCION_VERIFICAREXISTENCIA_GENERO_H_INCLUDED

#include "clase_Genero.h"
#include "clase_ArchivoGeneros.h"

bool VerificarExistenciaGenero(const char *primgenero) {
    // Crea una instancia del archivo de g�neros.
    ArchivoGeneros archgen("generos.dat");

    // Obtiene la cantidad de registros en el archivo.
    int cantReg = archgen.contarRegistros();

    // Declara un objeto Genero para almacenar los registros.
    Genero reg;

    // Recorre todos los registros en busca del g�nero.
    for (int i = 0; i < cantReg; i++) {
        // Lee un registro del archivo.
        reg = archgen.leerRegistro(i);

        // Compara el nombre del g�nero actual con el g�nero buscado.
        if (strcmp(primgenero, reg.getNombreGenero()) == 0) {
            // Si se encuentra el g�nero, devuelve verdadero.
            return true;
        }
    }

    // Si no se encuentra el g�nero, devuelve falso.
    return false;
}

Genero DevolverGenero(const char *primgenero) {
    // Crea una instancia del archivo de g�neros.
    ArchivoGeneros archgen("generos.dat");

    // Obtiene la cantidad de registros en el archivo.
    int cantReg = archgen.contarRegistros();

    // Declara un objeto Genero para almacenar los registros.
    Genero reg;

    // Recorre todos los registros en busca del g�nero.
    for (int i = 0; i < cantReg; i++) {
        // Lee un registro del archivo.
        reg = archgen.leerRegistro(i);

        // Compara el nombre del g�nero actual con el g�nero buscado.
        if (strcmp(primgenero, reg.getNombreGenero()) == 0) {
            // Si se encuentra el g�nero, lo devuelve.
            return reg;
        }
    }

    // Si no se encuentra el genero, no se devuelve nada.
    //Esto solo corre con la existencia confirmada, por lo que no es un problema.
}

#endif // FUNCION_VERIFICAREXISTENCIA_GENERO_H_INCLUDED
