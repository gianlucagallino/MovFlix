#ifndef FUNCION_ENCONTRARPELICULA_H_INCLUDED
#define FUNCION_ENCONTRARPELICULA_H_INCLUDED

#include "clase_Pelicula.h"
#include "clase_ArchivoPeliculas.h"

bool VerificarExistenciaPelicula(int idpelicula) {
    // Crea una instancia del archivo de películas.
    ArchivoPeliculas archpel("peliculas.dat");

    // Obtiene la cantidad de registros en el archivo.
    int cantReg = archpel.contarRegistros();

    // Declara un objeto Pelicula para almacenar los registros.
    Pelicula reg;

    // Recorre todos los registros en busca de la película.
    for (int i = 0; i < cantReg; i++) {
        // Lee un registro del archivo.
        reg = archpel.leerRegistro(i);

        // Compara el id de la película actual con la película buscada.
        if (idpelicula == reg.getIdPelicula()&&reg.getEstado()==true) {
            // Si se encuentra la película, devuelve verdadero.
            return true;
        }
    }

    // Si no se encuentra la película, devuelve falso.
    return false;
}

bool VerificarExistenciaNomPelicula(const char *pelicula) {
    // Crea una instancia del archivo de películas.
    ArchivoPeliculas archpel("peliculas.dat");

    // Obtiene la cantidad de registros en el archivo.
    int cantReg = archpel.contarRegistros();

    // Declara un objeto Pelicula para almacenar los registros.
    Pelicula reg;

    // Recorre todos los registros en busca de la película.
    for (int i = 0; i < cantReg; i++) {
        // Lee un registro del archivo.
        reg = archpel.leerRegistro(i);

        // Compara el nombre de la película actual con la película buscada.
        if (strcmp(pelicula,reg.getNombrePelicula())==0&&reg.getEstado()==true) {
            // Si se encuentra la película, devuelve verdadero.
            return true;
        }
    }

    // Si no se encuentra la película, devuelve falso.
    return false;
}
#endif // FUNCION_ENCONTRARPELICULA_H_INCLUDED
