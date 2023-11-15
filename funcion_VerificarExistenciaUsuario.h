#ifndef FUNCION_ENCONTRARUSUARIO_H_INCLUDED
#define FUNCION_ENCONTRARUSUARIO_H_INCLUDED

#include "clase_Usuario.h"
#include "clase_ArchivoUsuarios.h"

bool VerificarExistenciaUsuario(int idusuario) {
    // Crea una instancia del archivo de usuarios.
    ArchivoUsuarios archus("usuarios.dat");

    // Obtiene la cantidad de registros en el archivo de usuarios.
    int cantReg = archus.contarRegistros();
    Usuario reg;

    // Recorre todos los registros en busca de un usuario con el id especificado.
    for (int i = 0; i < cantReg; i++) {
        // Lee un registro del archivo.
        reg = archus.leerRegistro(i);

        // Compara si el id del usuario coincide con el id especificado.
        if (idusuario == reg.getIdUsuario()&&reg.getEstado()==true) {
            // Si se encuentra un usuario con el id especificado, devuelve verdadero.
            return true;
        }
    }

    // Si no se encuentra ningún usuario con el nombre especificado, devuelve falso.
    return false;
}
bool VerificarExistenciaNomUsuario(const char *usuario) {
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
        if (strcmp(usuario, reg.getNombreUsuario())==0&&reg.getEstado()==true) {
            // Si se encuentra un usuario con el nombre especificado, devuelve verdadero.
            return true;
        }
    }

    // Si no se encuentra ningún usuario con el nombre especificado, devuelve falso.
    return false;
}

#endif // FUNCION_ENCONTRARUSUARIO_H_INCLUDED
