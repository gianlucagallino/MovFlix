#ifndef FUNCION_MOSTRAREQUIVALENCIAS_H_INCLUDED
#define FUNCION_MOSTRAREQUIVALENCIAS_H_INCLUDED

//Al llamarse estas funciones, la existencia de sus valores ya fueron verificadas.
//Su proposito es el mismo; al pasar un id, buscan el registro correspondiente, y lo muestran.
//Esto se utiliza para solo guardar los id en las clases, y hacer la transformacion al momento de mostrar, solamente.

void MostraEquivalenciaGeneroPorId(int id) {
    ArchivoGeneros arch ("Generos.dat");
    Genero reg;
    char nombreTemp[30];

    int posicion = arch.buscarRegistro(id);
    reg = arch.leerRegistro(posicion);
    strcpy(nombreTemp, reg.getNombreGenero());
    cout<<nombreTemp<<endl;
    return;
}

void MostraEquivalenciaPeliculaPorId(int id) {
    ArchivoPeliculas arch ("Peliculas.dat");
    Pelicula reg;
    char nombreTemp[30];

    int posicion = arch.buscarRegistro(id);
    reg = arch.leerRegistro(posicion);
    strcpy(nombreTemp, reg.getNombrePelicula());
    cout<<nombreTemp<<endl;
    return;
}

void MostraEquivalenciaDirectorPorId(int id) {
    ArchivoDirectores arch ("Directores.dat");
    Director reg;
    char nombreTemp[30];

    int posicion = arch.buscarRegistro(id);
    reg = arch.leerRegistro(posicion);
    strcpy(nombreTemp, reg.getNombreDirector());
    cout<<nombreTemp<<endl;
    return;
}

void MostraEquivalenciaUsuarioPorId(int id) {
    ArchivoUsuarios arch ("Usuarios.dat");
    Usuario reg;
    char nombreTemp[30];

    int posicion = arch.buscarRegistro(id);
    reg = arch.leerRegistro(posicion);
    strcpy(nombreTemp, reg.getNombreUsuario());
    cout<<nombreTemp<<endl;
    return;
}

#endif // FUNCION_MOSTRAREQUIVALENCIAS_H_INCLUDED
