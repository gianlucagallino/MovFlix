#ifndef FUNCION_ENCONTRARPELICULA_H_INCLUDED
#define FUNCION_ENCONTRARPELICULA_H_INCLUDED

bool EncontrarPelicula(const char *nompelicula){
    ArchivoPeliculas archpel("peliculas.dat");
    int cantReg = archpel.contarRegistros();
    Pelicula reg;

    for (int i=0;i<cantReg;i++){
        reg = archpel.leerRegistro(i);
        if (strcmp(nompelicula,reg.getNombrePelicula()) == 0){  /// COMPARA EL GENERO RECIBIDO CON EL GENERO EN BASE A EL REGISTRO QUE ABRIÓ
            return true;
        }
    }
    return false;
}

bool MostrarPelicula (const char *nompelicula){
    ArchivoPeliculas archpeli("peliculas.dat");
    int cantReg = archpeli.contarRegistros();

    Pelicula reg;

    for (int i=0;i<cantReg;i++){
        reg = archpeli.leerRegistro(i);
        if(strcmp(nompelicula,reg.getNombrePelicula()) == 0){
            reg.Mostrar();
            return true;
        }
    }
    return false;
}

#endif // FUNCION_ENCONTRARPELICULA_H_INCLUDED
