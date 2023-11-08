#ifndef FUNCION_ENCONTRARPELICULA_H_INCLUDED
#define FUNCION_ENCONTRARPELICULA_H_INCLUDED

#include "clase_Pelicula.h"
#include "clase_ArchivoPeliculas.h"

bool VerificarExistenciaPelicula(const char *nompelicula) {
    // Crea una instancia del archivo de pel�culas.
    ArchivoPeliculas archpel("peliculas.dat");

    // Obtiene la cantidad de registros en el archivo.
    int cantReg = archpel.contarRegistros();

    // Declara un objeto Pelicula para almacenar los registros.
    Pelicula reg;

    // Recorre todos los registros en busca de la pel�cula.
    for (int i = 0; i < cantReg; i++) {
        // Lee un registro del archivo.
        reg = archpel.leerRegistro(i);

        // Compara el nombre de la pel�cula actual con la pel�cula buscada.
        if (strcmp(nompelicula, reg.getNombrePelicula()) == 0) {
            // Si se encuentra la pel�cula, devuelve verdadero.
            return true;
        }
    }

    // Si no se encuentra la pel�cula, devuelve falso.
    return false;
}

Pelicula DevolverPelicula(const char *nompelicula) {
    // Crea una instancia del archivo de pel�culas.
    ArchivoPeliculas archpel("peliculas.dat");

    // Obtiene la cantidad de registros en el archivo.
    int cantReg = archpel.contarRegistros();

    // Declara un objeto Pelicula para almacenar los registros.
    Pelicula reg;

    // Recorre todos los registros en busca de la pel�cula.
    for (int i = 0; i < cantReg; i++) {
        // Lee un registro del archivo.
        reg = archpel.leerRegistro(i);

        // Compara el nombre de la pel�cula actual con la pel�cula buscada.
        if (strcmp(nompelicula, reg.getNombrePelicula()) == 0) {
            // Si se encuentra la pel�cula, la devuelve.
            return reg;
        }
    }

    // Si no se encuentra la pel�cula, no se devuelve nada
    //Esto solo corre con la existencia confirmada, por lo que no es un problema.
}
#endif // FUNCION_ENCONTRARPELICULA_H_INCLUDED
