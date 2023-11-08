#ifndef CLASE_PELICULA_H_INCLUDED
#define CLASE_PELICULA_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

bool VerificarExistenciaPelicula(const char *nompelicula);

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
        _director=input;
    }

    void setFecha(Fecha input) {
        _fechaPublicacion = input;
    }

    void setGenero(Genero input) {
        _genero=input;
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
        char generoTemporal[30];
        char directorTemporal[30];

        bool flag_repeticion = false;

        _idPelicula = DeterminarPosicionAutonumerica("Peliculas.dat", sizeof(Pelicula));
        cout<<"NOMBRE: ";
        flag_repeticion = false;
        while (flag_repeticion != true) {
            cargarCadena(nombreTemporal, 30);
            if (VerificarExistenciaDirector(nombreTemporal) == true) {
                cout << "LA PELICULA YA EXISTE." << endl;
            } else {
                cout << "REGISTRADO." << endl;
                flag_repeticion = true;
            }
        }
        setNombrePelicula(nombreTemporal);
        cout<<"DESCRIPCION: ";
        cargarCadena(descTemporal, 200);
        setDescripcion(descTemporal);
        cout<<"DIRECTOR: "<<endl;
        flag_repeticion = false;
        while (flag_repeticion != true) {
            cargarCadena(directorTemporal, 30);
            if (VerificarExistenciaDirector(directorTemporal)== true) {
                cout << "DIRECTOR ENCONTRADO." << endl;
                setDirector(DevolverDirector(directorTemporal));
                flag_repeticion = true;
            } else {
                cout << "EL DIRECTOR NO EXISTE." << endl;
            }
        }

        cout<<"FECHA DE PUBLICACION: "<<endl;
        _fechaPublicacion.Cargar();
        cout<<"GENERO: "<<endl;
        flag_repeticion = false;
        while (flag_repeticion != true) {
            cargarCadena(generoTemporal, 30);
            if (VerificarExistenciaGenero(generoTemporal)== true ) {
                cout << "GENERO ENCONTRADO." << endl;
                setGenero(DevolverGenero(generoTemporal));
                flag_repeticion = true;
            } else {
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
            char dirtemp[30];
            strcpy(dirtemp,_director.getNombreDirector());
            cout<<dirtemp;
            cout<<"FECHA PUBLICACION: ";
            _fechaPublicacion.Mostrar();
            cout<<"GENERO: ";
            char generotemp[30];
            strcpy(generotemp,_genero.getNombreGenero());
            cout<<generotemp;
            cout<<endl;
        }
    }
};




#endif // CLASE_PELICULA_H_INCLUDED
