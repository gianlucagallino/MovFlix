#ifndef FUNCION_VERIFICAREXISTENCIARESENIADEPELICULA_H_INCLUDED
#define FUNCION_VERIFICAREXISTENCIARESENIADEPELICULA_H_INCLUDED

#include "clase_Resenia.h"
#include "clase_ArchivoResenias.h"

bool VerificarExistenciaReseniaDePelicula(Usuario escritor, Pelicula peli) {
    ArchivoResenias archRes("resenias.dat");
    Resenia reg;
    char escritorTemp[30];
    char peliTemp[30];
    char escritorBusc[30];
    char peliBusc[30];

    strcpy(escritorBusc, escritor.getNombreUsuario());
    strcpy(peliBusc, peli.getNombrePelicula());

    int CantReg = archRes.contarRegistros();
    for (int i = 0; i<CantReg;i++){
        reg = archRes.leerRegistro(i);
        strcpy(escritorTemp, reg.getAutorResenia().getNombreUsuario());
        strcpy(peliTemp, reg.getPeliculaResenia().getNombrePelicula());
        if (strcmp(escritorTemp, escritorBusc)==0&&strcmp(peliTemp,peliBusc)==0){
            return true;
        }
    }
    return false;
}

#endif // FUNCION_VERIFICAREXISTENCIARESENIADEPELICULA_H_INCLUDED
