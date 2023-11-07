#ifndef FUNCION_ENCONTRARUSUARIO_H_INCLUDED
#define FUNCION_ENCONTRARUSUARIO_H_INCLUDED

bool VerificarExistenciaUsuario(const char *nom) {
    ArchivoUsuarios archus("usuarios.dat");
    int cantReg = archus.contarRegistros();
    Usuario reg;

    for (int i=0; i<cantReg; i++) {
        reg = archus.leerRegistro(i);
        if (strcmp(nom,reg.getNombreUsuario()) == 0) {
            return true;
        }
    }
    return false;
}

Usuario DevolverUsuario(const char *nom) {
    ArchivoUsuarios archus("usuarios.dat");
    int cantReg = archus.contarRegistros();
    Usuario reg;

    for (int i=0; i<cantReg; i++) {
        reg = archus.leerRegistro(i);
        if (strcmp(nom,reg.getNombreUsuario()) == 0) {
            return reg;
        }
    }
}

#endif // FUNCION_ENCONTRARUSUARIO_H_INCLUDED
