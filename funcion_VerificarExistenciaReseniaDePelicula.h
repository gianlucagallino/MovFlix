#ifndef FUNCION_VERIFICAREXISTENCIARESENIADEPELICULA_H_INCLUDED
#define FUNCION_VERIFICAREXISTENCIARESENIADEPELICULA_H_INCLUDED

#include "clase_Resenia.h"
#include "clase_ArchivoResenias.h"

bool VerificarExistenciaReseniaDePelicula(Usuario escritor, Pelicula peli) {
    // Crea una instancia del archivo de reseñas.
    ArchivoResenias archRes("resenias.dat");

    // Declara un objeto Resenia para almacenar los registros.
    Resenia reg;

    // Almacena los nombres del escritor y la película a buscar.
    char escritorBusc[30];
    char peliBusc[30];
    strcpy(escritorBusc, escritor.getNombreUsuario());
    strcpy(peliBusc, peli.getNombrePelicula());

    // Obtiene la cantidad de registros en el archivo de reseñas.
    int CantReg = archRes.contarRegistros();

    // Recorre todos los registros en busca de una reseña que coincida con el escritor y la película.
    for (int i = 0; i < CantReg; i++) {
        // Lee un registro del archivo.
        reg = archRes.leerRegistro(i);

        // Almacena los nombres del escritor y la película del registro actual.
        char escritorTemp[30];
        char peliTemp[30];
        strcpy(escritorTemp, reg.getAutorResenia().getNombreUsuario());
        strcpy(peliTemp, reg.getPeliculaResenia().getNombrePelicula());

        // Compara si el escritor y la película coinciden con los buscados.
        if (strcmp(escritorTemp, escritorBusc) == 0 && strcmp(peliTemp, peliBusc) == 0) {
            // Si se encuentra una reseña que coincide, devuelve verdadero.
            return true;
        }
    }

    // Si no se encuentra ninguna reseña que coincida, devuelve falso.
    return false;
}

#endif // FUNCION_VERIFICAREXISTENCIARESENIADEPELICULA_H_INCLUDED
