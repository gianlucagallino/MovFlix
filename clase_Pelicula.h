#ifndef CLASE_PELICULA_H_INCLUDED
#define CLASE_PELICULA_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

class Pelicula {

//Propiedades
  private:
    int _idPelicula;
    char _nombrePelicula[30];
    char _descripcion[200];
    Director _director;
    Fecha _fechaPublicacion;
    Genero _genero;
    bool _estado;

//Metodos
  public:
    //sets()

    //No corresponde un setId, dado que es autonumerico.

    void setNombrePelicula(const char *input) {
        strcpy(_nombrePelicula,input);
    }

    void setDescripcion(const char *input) {
        strcpy(_descripcion,input);
    }

    void setDirector(Director input) {
        _director = input;
    }

    void setFecha(Fecha input) {
        _fechaPublicacion = input;
    }

    void setGenero(Genero input) {
        _genero = input;
    }

    void setEstado(bool input) {
        _estado = input;
    }

    //gets()

    int getIdPelicula() {
        return _idPelicula;
    }

    const char *getNombrePelicula() {
        return _nombrePelicula;
    }

    const char *getDescripcion() {
        return _descripcion;
    }

    Director getDirector() {
        return _director;
    }

    Fecha getFechaPublicacion() {
        return _fechaPublicacion;
    }

    Genero getGenero() {
        return _genero;
    }

    bool getEstado() {
        return _estado;
    }

    //Otros

    void Cargar() {

        char nombreTemporal[30];
        char descTemporal[200];

        _idPelicula = DeterminarPosicionAutonumerica("Peliculas.dat", sizeof(Pelicula));
        cout<<"NOMBRE: ";
        cargarCadena(nombreTemporal, 30);
        setNombrePelicula(nombreTemporal);
        cout<<"DESCRIPCION: ";
        cargarCadena(descTemporal, 200);
        setNombrePelicula(descTemporal);
        cout<<"DIRECTOR: "<<endl;
        _director.Cargar();
        cout<<"FECHA DE PUBLICACION: "<<endl;
        _fechaPublicacion.Cargar();
        cout<<"GENERO: "<<endl;
        _genero.Cargar();
        setEstado(true);
    }

    void Mostrar() {
        if (getEstado()) {
            cout<<"ID PELICULA: ";
            cout<<_idPelicula<<endl;
            cout<<"NOMBRE: ";
            cout<<_nombrePelicula<<endl;
            cout<<"DESCRIPCION"<<endl;
            cout<<_descripcion<<endl;
            cout<<"DIRECTOR: "<<endl;
            _director.Mostrar();
            cout<<"FECHA PUBLICACION: "<<endl;
            _fechaPublicacion.Mostrar();
            cout<<"GENERO: "<<endl;
            _genero.Mostrar();
            cout<<endl;
        }
    }
};


#endif // CLASE_PELICULA_H_INCLUDED
