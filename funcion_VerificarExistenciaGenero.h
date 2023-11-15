#ifndef FUNCION_VERIFICAREXISTENCIA_GENERO_H_INCLUDED
#define FUNCION_VERIFICAREXISTENCIA_GENERO_H_INCLUDED

#include "clase_Genero.h"
#include "clase_ArchivoGeneros.h"

bool VerificarExistenciaGenero(int primgenero) {
    // Crea una instancia del archivo de géneros.
    ArchivoGeneros archgen("generos.dat");

    // Obtiene la cantidad de registros en el archivo.
    int cantReg = archgen.contarRegistros();

    // Declara un objeto Genero para almacenar los registros.
    Genero reg;

    // Recorre todos los registros en busca del género.
    for (int i = 0; i < cantReg; i++) {
        // Lee un registro del archivo.
        reg = archgen.leerRegistro(i);

        // Compara el id del género actual con el id buscado.
        if (primgenero== reg.getIdGenero()&&reg.getEstado()==true) {
            // Si se encuentra el id, devuelve verdadero.
            return true;
        }
    }

    // Si no se encuentra el id, devuelve falso.
    return false;
}

bool VerificarExistenciaNomGenero(const char *primgenero) {
    // Crea una instancia del archivo de géneros.
    ArchivoGeneros archgen("generos.dat");

    // Obtiene la cantidad de registros en el archivo.
    int cantReg = archgen.contarRegistros();

    // Declara un objeto Genero para almacenar los registros.
    Genero reg;

    // Recorre todos los registros en busca del género.
    for (int i = 0; i < cantReg; i++) {
        // Lee un registro del archivo.
        reg = archgen.leerRegistro(i);

        // Compara el nombre del género actual con el género buscado.
        if (strcmp(primgenero,reg.getNombreGenero())==0&&reg.getEstado()==true) {
            // Si se encuentra el género, devuelve verdadero.
            return true;
        }
    }

    // Si no se encuentra el género, devuelve falso.
    return false;
}
#endif // FUNCION_VERIFICAREXISTENCIA_GENERO_H_INCLUDED
