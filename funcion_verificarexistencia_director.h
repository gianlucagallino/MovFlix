#ifndef FUNCION_VERIFICAREXISTENCIA_DIRECTOR_H_INCLUDED
#define FUNCION_VERIFICAREXISTENCIA_DIRECTOR_H_INCLUDED

bool VerificarExistenciaDirector(const char *primdirector){
    ArchivoDirectores archdir("directores.dat");
    int cantReg = archdir.contarRegistros();
    Director reg;

    for (int i=0;i<cantReg;i++){
        reg = archdir.leerRegistro(i);
        if (strcmp(primdirector,reg.getNombreDirector()) == 0){  /// COMPARA EL GENERO RECIBIDO CON EL GENERO EN BASE A EL REGISTRO QUE ABRIÓ
            return true;
        }
    }
    return false;
}

#endif // FUNCION_VERIFICAREXISTENCIA_DIRECTOR_H_INCLUDED
