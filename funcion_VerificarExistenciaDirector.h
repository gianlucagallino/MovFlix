#ifndef FUNCION_VERIFICAREXISTENCIA_DIRECTOR_H_INCLUDED
#define FUNCION_VERIFICAREXISTENCIA_DIRECTOR_H_INCLUDED

#include "clase_Director.h"
#include "clase_ArchivoDirectores.h"

bool VerificarExistenciaDirector(const char *primdirector) {
    ArchivoDirectores archdir("directores.dat");
    int cantReg = archdir.contarRegistros();
    Director reg;

    for (int i=0; i<cantReg; i++) {
        reg = archdir.leerRegistro(i);
        if (strcmp(primdirector,reg.getNombreDirector()) == 0) { /// COMPARA EL GENERO RECIBIDO CON EL GENERO EN BASE A EL REGISTRO QUE ABRIÓ
            return true;
        }
    }
    return false;
}

Director DevolverDirector(const char *primdirector) {
    ArchivoDirectores archdir("directores.dat");
    int cantReg = archdir.contarRegistros();
    Director reg;

    for (int i=0; i<cantReg; i++) {
        reg = archdir.leerRegistro(i);
        if (strcmp(primdirector,reg.getNombreDirector()) == 0) { /// COMPARA EL GENERO RECIBIDO CON EL GENERO EN BASE A EL REGISTRO QUE ABRIÓ
            return reg;
        }
    }
}

#endif // FUNCION_VERIFICAREXISTENCIA_DIRECTOR_H_INCLUDED
