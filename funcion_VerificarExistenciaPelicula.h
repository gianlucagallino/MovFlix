#ifndef FUNCION_ENCONTRARPELICULA_H_INCLUDED
#define FUNCION_ENCONTRARPELICULA_H_INCLUDED

#include "clase_Pelicula.h"
#include "clase_ArchivoPeliculas.h"

bool VerificarExistenciaPelicula(const char *nompelicula) {
    ArchivoPeliculas archpel("peliculas.dat");
    int cantReg = archpel.contarRegistros();
    Pelicula reg;

    for (int i=0; i<cantReg; i++) {
        reg = archpel.leerRegistro(i);
        if (strcmp(nompelicula,reg.getNombrePelicula()) == 0) { /// COMPARA EL GENERO RECIBIDO CON EL GENERO EN BASE A EL REGISTRO QUE ABRIÓ
            return true;
        }
    }
    return false;
}

Pelicula DevolverPelicula(const char *nompelicula) {
    ArchivoPeliculas archpel("peliculas.dat");
    int cantReg = archpel.contarRegistros();
    Pelicula reg;

    for (int i=0; i<cantReg; i++) {
        reg = archpel.leerRegistro(i);
        if (strcmp(nompelicula,reg.getNombrePelicula()) == 0) { /// COMPARA EL GENERO RECIBIDO CON EL GENERO EN BASE A EL REGISTRO QUE ABRIÓ
            return reg;
        }
    }
}
#endif // FUNCION_ENCONTRARPELICULA_H_INCLUDED
