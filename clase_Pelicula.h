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
    char _director[30];
    Fecha _fechaPublicacion;
    char _genero[30];
    bool _estado;

//Metodos
  public:
    //sets()

    //No corresponde un setId, dado que es autonumerico.

    void setNombrePelicula(const char *input) {strcpy(_nombrePelicula,input);}

    void setDescripcion(const char *input) {strcpy(_descripcion,input);}

    void setDirector(const char *input) {strcpy(_director,input);}

    void setFecha(Fecha input) {_fechaPublicacion = input;}

    void setGenero(const char *input) {strcpy(_genero,input);}

    void setEstado(bool input) {_estado = input;}

    //gets()

    int getIdPelicula() {return _idPelicula;}

    const char *getNombrePelicula() {return _nombrePelicula;}

    const char *getDescripcion() {return _descripcion;}

    const char *getDirector() {return _director;}

    Fecha getFechaPublicacion() {return _fechaPublicacion;}

    const char *getGenero() {return _genero;}

    bool getEstado() {return _estado;}

    //Otros

    void Cargar() {

        char nombreTemporal[30];
        char descTemporal[200];
        char generoTemporal[30];
        char directorTemporal[30];

        bool flag_repeticion = false;
        bool flag_repeticion1 = false;

        _idPelicula = DeterminarPosicionAutonumerica("Peliculas.dat", sizeof(Pelicula));
        cout<<"NOMBRE: ";
        cargarCadena(nombreTemporal, 30);
        setNombrePelicula(nombreTemporal);
        cout<<"DESCRIPCION: ";
        cargarCadena(descTemporal, 200);
        setDescripcion(descTemporal);
        cout<<"DIRECTOR: "<<endl;
        while (flag_repeticion1 != true){
            cargarCadena(directorTemporal, 30);
            if (VerificarExistenciaDirector(directorTemporal)== true){
                setDirector(directorTemporal);
                flag_repeticion1 = true;
            }else{
                cout << "EL DIRECTOR NO EXISTE." << endl;
            }
        }

        cout<<"FECHA DE PUBLICACION: "<<endl;
        _fechaPublicacion.Cargar();
        cout<<"GENERO: "<<endl;
        while (flag_repeticion != true){
            cargarCadena(generoTemporal, 30);
            if (VerificarExistenciaGenero(generoTemporal)== true){
                setGenero(generoTemporal);
                flag_repeticion = true;
            }else{
                cout << "EL GENERO NO EXISTE." << endl;
            }
        }

        setEstado(true);
    }

    void Mostrar() {
        if (getEstado()) {
            cout<<"ID PELICULA: ";
            cout<<_idPelicula<<endl;
            cout<<"NOMBRE: ";
            cout<<_nombrePelicula<<endl;
            cout<<"DESCRIPCION: ";
            cout<<_descripcion<<endl;
            cout<<"DIRECTOR: ";
            cout<<_director<<endl;
            cout<<"FECHA PUBLICACION: ";
            _fechaPublicacion.Mostrar();
            cout<<"GENERO: ";
            cout<<_genero<<endl;
            cout<<endl;
        }
    }
};




#endif // CLASE_PELICULA_H_INCLUDED
