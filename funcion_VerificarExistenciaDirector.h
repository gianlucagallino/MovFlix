#ifndef FUNCION_VERIFICAREXISTENCIA_DIRECTOR_H_INCLUDED
#define FUNCION_VERIFICAREXISTENCIA_DIRECTOR_H_INCLUDED

#include "clase_Director.h"
#include "clase_ArchivoDirectores.h"

bool VerificarExistenciaDirector(const char *primdirector) {
    // Crea una instancia del archivo de directores.
    ArchivoDirectores archdir("directores.dat");

    // Obtiene la cantidad de registros en el archivo.
    int cantReg = archdir.contarRegistros();

    // Declara un objeto Director para almacenar los registros.
    Director reg;

    // Recorre todos los registros en busca del director.
    for (int i = 0; i < cantReg; i++) {
        // Lee un registro del archivo.
        reg = archdir.leerRegistro(i);

        // Compara el nombre del director actual con el director buscado.
        if (strcmp(primdirector, reg.getNombreDirector()) == 0) {
            // Si se encuentra el director, devuelve verdadero.
            return true;
        }
    }

    // Si no se encuentra el director, devuelve falso.
    return false;
}

Director DevolverDirector(const char *primdirector) {
    // Crea una instancia del archivo de directores.
    ArchivoDirectores archdir("directores.dat");

    // Obtiene la cantidad de registros en el archivo.
    int cantReg = archdir.contarRegistros();

    // Declara un objeto Director para almacenar los registros.
    Director reg;

    // Recorre todos los registros en busca del director.
    for (int i = 0; i < cantReg; i++) {
        // Lee un registro del archivo.
        reg = archdir.leerRegistro(i);

        // Compara el nombre del director actual con el director buscado.
        if (strcmp(primdirector, reg.getNombreDirector()) == 0) {
            // Si se encuentra el director, lo devuelve.
            return reg;
        }
    }

    // Si no se encuentra el director, no se devuelve nada.
    //Esto solo corre con la existencia confirmada, por lo que no es un problema.
}

#endif // FUNCION_VERIFICAREXISTENCIA_DIRECTOR_H_INCLUDED
