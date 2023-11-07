#ifndef FUNCION_ENCONTRARUSUARIO_H_INCLUDED
#define FUNCION_ENCONTRARUSUARIO_H_INCLUDED

bool EncontrarUsuario(int idusuario){
    ArchivoUsuarios archus("usuarios.dat");
    int cantReg = archus.contarRegistros();
    Usuario reg;

    for (int i=0;i<cantReg;i++){
        reg = archus.leerRegistro(i);
        if (idusuario == reg.getIdUsuario()){  /// COMPARA EL GENERO RECIBIDO CON EL GENERO EN BASE A EL REGISTRO QUE ABRIÓ
            return true;
        }
    }
    return false;
}

bool MostrarUsuario (int idusuario){
    ArchivoUsuarios archus("usuarios.dat");
    int cantReg = archus.contarRegistros();

    Usuario reg;

    for (int i=0;i<cantReg;i++){
        reg = archus.leerRegistro(i);
        if(idusuario == reg.getIdUsuario()){
            reg.Mostrar();
            return true;
        }
    }
    return false;
}

#endif // FUNCION_ENCONTRARUSUARIO_H_INCLUDED
