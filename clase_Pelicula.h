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

    void setNombrePelicula(const char *input) {strcpy(_nombrePelicula,input);}

    void setDescripcion(const char *input) {strcpy(_descripcion,input);}

    void setDirector(Director input) {_director = input;}

    void setFecha(Fecha input) {_fechaPublicacion = input;}

    void setGenero(Genero input) {_genero = input;}

    void setEstado(bool input) {_estado = input;}

    //gets()

    int getIdPelicula() {return _idPelicula;}

    const char *getNombrePelicula() {return _nombrePelicula;}

    const char *getDescripcion() {return _descripcion;}

    Director getDirector() {return _director;}

    Fecha getFechaPublicacion() {return _fechaPublicacion;}

    Genero getGenero() {return _genero;}

    bool getEstado() {return _estado;}

    //Otros

    void Cargar() {

        char nombreTemporal[30];
        char descTemporal[200];
        char generoTemporal[30];

        _idPelicula = DeterminarPosicionAutonumerica("Peliculas.dat", sizeof(Pelicula));
        cout<<"NOMBRE: ";
        cargarCadena(nombreTemporal, 30);
        setNombrePelicula(nombreTemporal);
        cout<<"DESCRIPCION: ";
        cargarCadena(descTemporal, 200);
        setDescripcion(descTemporal);
        cout<<"DIRECTOR: "<<endl;
        _director.Cargar();
        cout<<"FECHA DE PUBLICACION: "<<endl;
        _fechaPublicacion.Cargar();
        cout<<"GENERO: "<<endl;
        cargarCadena(generoTemporal, 30);
        Pelicula pel;
        pel.VerificarExistencia(generoTemporal);
        //_genero.Cargar();
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
            cout<<"FECHA PUBLICACION: ";
            _fechaPublicacion.Mostrar();
            cout<<"GENERO: "<<endl;
            //_genero.Mostrar();
            cout<<endl;
        }
    }
    bool VerificarExistencia (const char *primgenero){
        int flag = false;
        while (flag != false){
        ArchivoGeneros archgen;

        int cantReg = archgen.contarregistro();

        for (int i=0;i<cantReg;i++){
            _genero = archgen.leerregistro(i);
           if (_genero.getIdGenero() == primgenero){
            flag = true;
                }
            }
        }
    }

};




#endif // CLASE_PELICULA_H_INCLUDED
