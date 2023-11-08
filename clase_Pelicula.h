#ifndef CLASE_PELICULA_H_INCLUDED
#define CLASE_PELICULA_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

//Los registros son AUTONUMERICOS.


// Declaraci�n de la funci�n para verificar la existencia de una pel�cula
bool VerificarExistenciaPelicula(const char *nompelicula);

// Definici�n de la clase Pelicula
class Pelicula {
  private:
    int _idPelicula;                 // Propiedad para el ID de la pel�cula
    char _nombrePelicula[30];        // Propiedad para el nombre de la pel�cula
    char _descripcion[200];          // Propiedad para la descripci�n de la pel�cula
    Director _director;             // Propiedad para el director de la pel�cula
    Fecha _fechaPublicacion;         // Propiedad para la fecha de publicaci�n de la pel�cula
    Genero _genero;                  // Propiedad para el g�nero de la pel�cula
    bool _estado;                    // Propiedad que indica el estado de la pel�cula

  public:
    // M�todos para establecer las propiedades de la pel�cula

    //No corresponde un setId, dado que es autonumerico.

    void setNombrePelicula(const char *input) {
        strcpy(_nombrePelicula, input);
    }

    void setDescripcion(const char *input) {
        strcpy(_descripcion, input);
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

    // M�todos para obtener las propiedades de la pel�cula
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

    // M�todo para cargar una pel�cula
    void Cargar() {
        char nombreTemporal[30];
        char descTemporal[200];
        char generoTemporal[30];
        char directorTemporal[30];

        bool flag_repeticion = false;

        _idPelicula = DeterminarPosicionAutonumerica("Peliculas.dat", sizeof(Pelicula));
        cout << "NOMBRE: ";
        flag_repeticion = false;

        while (flag_repeticion != true) {
            cargarCadena(nombreTemporal, 30);

            if (VerificarExistenciaPelicula(nombreTemporal)) {
                cout << "LA PEL�CULA YA EXISTE." << endl;
            } else {
                cout << "REGISTRADA." << endl;
                flag_repeticion = true;
            }
        }
        setNombrePelicula(nombreTemporal);
        cout << "DESCRIPCION: ";
        cargarCadena(descTemporal, 200);
        setDescripcion(descTemporal);
        cout << "DIRECTOR: " << endl;
        flag_repeticion = false;

        while (flag_repeticion != true) {
            cargarCadena(directorTemporal, 30);

            if (VerificarExistenciaDirector(directorTemporal) == true) {
                cout << "DIRECTOR ENCONTRADO." << endl;
                setDirector(DevolverDirector(directorTemporal));
                flag_repeticion = true;
            } else {
                cout << "EL DIRECTOR NO EXISTE." << endl;
            }
        }

        cout << "FECHA DE PUBLICACI�N: " << endl;
        _fechaPublicacion.Cargar();
        cout << "G�NERO: " << endl;
        flag_repeticion = false;

        while (flag_repeticion != true) {
            cargarCadena(generoTemporal, 30);

            if (VerificarExistenciaGenero(generoTemporal) == true) {
                cout << "G�NERO ENCONTRADO." << endl;
                setGenero(DevolverGenero(generoTemporal));
                flag_repeticion = true;
            } else {
                cout << "EL G�NERO NO EXISTE." << endl;
            }
        }

        setEstado(true);
    }

    // M�todo para mostrar una pel�cula
    void Mostrar() {
        if (getEstado()) {
            cout << "ID PEL�CULA: " << _idPelicula << endl;
            cout << "NOMBRE: " << _nombrePelicula << endl;
            cout << "DESCRIPCION: " << _descripcion << endl;
            cout << "DIRECTOR: ";
            char dirtemp[30];
            strcpy(dirtemp, _director.getNombreDirector());
            cout << dirtemp;
            cout << "FECHA PUBLICACI�N: ";
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
