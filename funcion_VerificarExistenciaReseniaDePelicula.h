#ifndef FUNCION_VERIFICAREXISTENCIARESENIADEPELICULA_H_INCLUDED
#define FUNCION_VERIFICAREXISTENCIARESENIADEPELICULA_H_INCLUDED

#include "clase_Resenia.h"
#include "clase_ArchivoResenias.h"

bool VerificarExistenciaReseniaDePelicula(int idescritor, int idpeli) {
    // Crea una instancia del archivo de rese�as.
    ArchivoResenias archRes("resenias.dat");

    // Declara un objeto Resenia para almacenar los registros.
    Resenia reg;

    // Obtiene la cantidad de registros en el archivo de rese�as.
    int CantReg = archRes.contarRegistros();

    // Recorre todos los registros en busca de una rese�a que coincida con el escritor y la pel�cula.
    for (int i = 0; i < CantReg; i++) {
        // Lee un registro del archivo.
        reg = archRes.leerRegistro(i);

        // Compara si el escritor y la pel�cula coinciden con los buscados.
        if (idescritor == reg.getidAutorResenia() && idpeli == reg.getidPeliculaResenia()&&reg.getEstado()==true) {
            // Si se encuentra una rese�a que coincide, devuelve verdadero.
            return true;
        }
    }

    // Si no se encuentra ninguna rese�a que coincida, devuelve falso.
    return false;
}

#endif // FUNCION_VERIFICAREXISTENCIARESENIADEPELICULA_H_INCLUDED
