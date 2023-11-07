#ifndef FUNCION_VERIFICAREXISTENCIA_GENERO_H_INCLUDED
#define FUNCION_VERIFICAREXISTENCIA_GENERO_H_INCLUDED


bool VerificarExistenciaGenero(const char *primgenero){
    ArchivoGeneros archgen("generos.dat");
    int cantReg = archgen.contarRegistros();
    Genero reg;

    for (int i=0;i<cantReg;i++){
        reg = archgen.leerRegistro(i);
        if (strcmp(primgenero,reg.getNombreGenero()) == 0){  /// COMPARA EL GENERO RECIBIDO CON EL GENERO EN BASE A EL REGISTRO QUE ABRIÓ
            return true;
        }
    }
    return false;
}

#endif // FUNCION_VERIFICAREXISTENCIA_GENERO_H_INCLUDED
