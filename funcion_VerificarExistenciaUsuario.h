#ifndef FUNCION_ENCONTRARUSUARIO_H_INCLUDED
#define FUNCION_ENCONTRARUSUARIO_H_INCLUDED

#include "clase_Usuario.h"
#include "clase_ArchivoUsuarios.h"

bool VerificarExistenciaUsuario(const char *nom) {
    // Crea una instancia del archivo de usuarios.
    ArchivoUsuarios archus("usuarios.dat");

    // Obtiene la cantidad de registros en el archivo de usuarios.
    int cantReg = archus.contarRegistros();
    Usuario reg;

    // Recorre todos los registros en busca de un usuario con el nombre especificado.
    for (int i = 0; i < cantReg; i++) {
        // Lee un registro del archivo.
        reg = archus.leerRegistro(i);

        // Compara si el nombre del usuario coincide con el nombre especificado.
        if (strcmp(nom, reg.getNombreUsuario()) == 0) {
            // Si se encuentra un usuario con el nombre especificado, devuelve verdadero.
            return true;
        }
    }

    // Si no se encuentra ningún usuario con el nombre especificado, devuelve falso.
    return false;
}

Usuario DevolverUsuario(const char *nom) {
    // Crea una instancia del archivo de usuarios.
    ArchivoUsuarios archus("usuarios.dat");

    // Obtiene la cantidad de registros en el archivo de usuarios.
    int cantReg = archus.contarRegistros();
    Usuario reg;

    // Recorre todos los registros en busca de un usuario con el nombre especificado.
    for (int i = 0; i < cantReg; i++) {
        // Lee un registro del archivo.
        reg = archus.leerRegistro(i);

        // Compara si el nombre del usuario coincide con el nombre especificado.
        if (strcmp(nom, reg.getNombreUsuario()) == 0) {
            // Si se encuentra un usuario con el nombre especificado, devuelve ese usuario.
            return reg;
        }
    }

    // Si no se encuentra el usuario, no se devuelve nada
    //Esto solo corre con la existencia confirmada, por lo que no es un problema.
}

#endif // FUNCION_ENCONTRARUSUARIO_H_INCLUDED
