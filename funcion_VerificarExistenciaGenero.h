#ifndef FUNCION_VERIFICAREXISTENCIA_GENERO_H_INCLUDED
#define FUNCION_VERIFICAREXISTENCIA_GENERO_H_INCLUDED

#include "clase_Genero.h"
#include "clase_ArchivoGeneros.h"

bool VerificarExistenciaGenero(int primgenero) {
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

        // Compara el id del g�nero actual con el id buscado.
        if (primgenero== reg.getIdGenero()&&reg.getEstado()==true) {
            // Si se encuentra el id, devuelve verdadero.
            return true;
        }
    }

    // Si no se encuentra el id, devuelve falso.
    return false;
}

bool VerificarExistenciaNomGenero(const char *primgenero) {
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
        if (strcmp(primgenero,reg.getNombreGenero())==0&&reg.getEstado()==true) {
            // Si se encuentra el g�nero, devuelve verdadero.
            return true;
        }
    }

    // Si no se encuentra el g�nero, devuelve falso.
    return false;
}
#endif // FUNCION_VERIFICAREXISTENCIA_GENERO_H_INCLUDED
