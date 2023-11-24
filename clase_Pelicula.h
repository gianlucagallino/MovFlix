#ifndef CLASE_PELICULA_H_INCLUDED
#define CLASE_PELICULA_H_INCLUDED

//Los registros son AUTONUMERICOS.


// Declaraci�n de la funci�n para verificar la existencia de una pel�cula
bool VerificarExistenciaPelicula(int idpelicula);
bool VerificarExistenciaNomPelicula(const char *pelicula);
void MostraEquivalenciaGeneroPorId(int id);
void MostraEquivalenciaDirectorPorId(int id);


// Definici�n de la clase Pelicula
class Pelicula {
  private:
    int _idPelicula;                 // Propiedad para el ID de la pel�cula
    char _nombrePelicula[30];        // Propiedad para el nombre de la pel�cula
    char _descripcion[200];          // Propiedad para la descripci�n de la pel�cula
    int _iddirector;             // Propiedad para el ID de director de la pel�cula
    Fecha _fechaPublicacion;         // Propiedad para la fecha de publicaci�n de la pel�cula
    int _idgenero;                  // Propiedad para el ID g�nero de la pel�cula
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

    void setidDirector(int input) {

        _iddirector=input;
    }

    void setFecha(Fecha input) {
        _fechaPublicacion = input;
    }

    void setidGenero(int input) {
        _idgenero=input;
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

    int getidDirector() {
        return _iddirector;
    }

    Fecha getFechaPublicacion() {
        return _fechaPublicacion;
    }

    int getidGenero() {
        return _idgenero;
    }

    bool getEstado() {
        return _estado;
    }

    // M�todo para cargar una pel�cula
    void Cargar() {
        char nombreTemporal[30];
        char descTemporal[200];
        int generoTemporal;
        int directorTemporal;
        ArchivoDirectores archDir ("Directores.dat");
        ArchivoGeneros archGen("Generos.dat");

        bool flag_repeticion = false;

        _idPelicula = DeterminarPosicionAutonumerica("Peliculas.dat", sizeof(Pelicula));
        cout << "NOMBRE: ";
        cargarCadena(nombreTemporal, 30);
        while(nombreTemporal[0]=='\0'||VerificarExistenciaNomPelicula(nombreTemporal)) {
            cout<<"INPUT VACIO O REGISTRO YA EXISTENTE"<<endl;
            system ("pause");
            system ("cls");
            cout << "NOMBRE: ";
            cargarCadena(nombreTemporal, 30);
        }
        setNombrePelicula(nombreTemporal);
        cout << "DESCRIPCION: ";
        cargarCadena(descTemporal, 200);
        while(descTemporal[0]=='\0') cargarCadena(descTemporal, 200);;
        setDescripcion(descTemporal);

        cout << "SUS OPCIONES SON: "<<endl<<endl;
        archDir.listarRegistros();
        cout << "ID DIRECTOR (NUMERO ENTERO SOLAMENTE): " << endl;
        flag_repeticion = false;

        while (flag_repeticion != true) {
            cin>>directorTemporal;

            if (VerificarExistenciaDirector(directorTemporal) == true) {
                cout << "DIRECTOR ENCONTRADO." << endl;
                setidDirector(directorTemporal);
                flag_repeticion = true;
            } else {
                cout << "EL DIRECTOR NO EXISTE." << endl;
            }
        }

        cout << "FECHA DE PUBLICACION: " << endl;
        _fechaPublicacion.Cargar();

        cout << "SUS OPCIONES SON: "<<endl<<endl;
        archGen.listarRegistros();
        cout << "ID GENERO (NUMERO ENTERO SOLAMENTE): " << endl;
        flag_repeticion = false;

        while (flag_repeticion != true) {
            cin>>generoTemporal;

            if (VerificarExistenciaGenero(generoTemporal) == true) {
                cout << "GENERO ENCONTRADO." << endl;
                setidGenero(generoTemporal);
                flag_repeticion = true;
            } else {
                cout << "EL GENERO NO EXISTE." << endl;
            }
        }

        setEstado(true);
    }

    // M�todo para mostrar una pel�cula
    void Mostrar() {
        if (getEstado()) {
            cout << "ID PELICULA: " << _idPelicula << endl;
            cout << "NOMBRE: " << _nombrePelicula << endl;
            cout << "DESCRIPCION: " << _descripcion << endl;
            cout << "ID DIRECTOR: " << _iddirector<<endl;
            cout << "NOMBRE DIRECTOR: ";
            MostraEquivalenciaDirectorPorId(_iddirector);
            cout << "FECHA PUBLICACION: ";
            _fechaPublicacion.Mostrar();
            cout<<"ID GENERO: "<<_idgenero<<endl;
            cout << "NOMBRE GENERO: ";
            MostraEquivalenciaGeneroPorId(_idgenero);
            cout<<endl<<endl;
        }
    }
};


#endif // CLASE_PELICULA_H_INCLUDED
