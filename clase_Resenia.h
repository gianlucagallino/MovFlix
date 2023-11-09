#ifndef CLASE_RESENIA_H_INCLUDED
#define CLASE_RESENIA_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

//Los registros son AUTONUMERICOS.

// Declaraci�n de la funci�n para verificar la existencia de una rese�a de una pel�cula
bool VerificarExistenciaReseniaDePelicula(Usuario escritor, Pelicula peli);

// Definici�n de la clase Resenia
class Resenia {
  private:
    int _idResenia;                 // Propiedad para el ID de la rese�a
    Usuario _autorResenia;         // Propiedad para el autor de la rese�a
    Pelicula _peliculaResenia;      // Propiedad para la pel�cula relacionada con la rese�a
    char _opinion[200];             // Propiedad para la opini�n de la rese�a
    Fecha _fechaResenia;            // Propiedad para la fecha de la rese�a
    float _puntuacionResenia;         // Propiedad para la puntuaci�n de la rese�a
    bool _estado;                   // Propiedad que indica el estado de la rese�a

  public:
    // M�todos para establecer las propiedades de la rese�a

    //No corresponde un setId, dado que es autonumerico.

    void setAutorResenia(Usuario input) {
        _autorResenia = input;
    }

    void setPeliculaResenia(Pelicula input) {
        _peliculaResenia = input;
    }

    void setOpinion(const char *input) {
        strcpy(_opinion, input);
    }

    void setFechaResenia(Fecha input) {
        _fechaResenia = input;
    }

    void setPuntuacionResenia(float input) {
        _puntuacionResenia = input;
    }

    void setEstado(bool input) {
        _estado = input;
    }

    // M�todos para obtener las propiedades de la rese�a
    int getIdResenia() {
        return _idResenia;
    }

    Usuario getAutorResenia() {
        return _autorResenia;
    }

    Pelicula getPeliculaResenia() {
        return _peliculaResenia;
    }

    const char *getOpinion() {
        return _opinion;
    }

    Fecha getFechaResenia() {
        return _fechaResenia;
    }

    float getPuntuacionResenia() {
        return _puntuacionResenia;
    }

    bool getEstado() {
        return _estado;
    }

    // M�todo para cargar una rese�a
    void Cargar() {
        char nomtemp[30];
        char pelitemp[30];
        char opinionTemporal[200];
        bool flag_repeticion = false;
        int puntuacionTemporal;

        _idResenia  = DeterminarPosicionAutonumerica("Resenias.dat", sizeof(Resenia));
        cout << "NOMBRE AUTOR DE LA RESE�A: " << endl;
        flag_repeticion = false;

        while (flag_repeticion != true) {
            cargarCadena(nomtemp, 30);

            if (VerificarExistenciaUsuario(nomtemp) == true) {
                cout << "Usuario ENCONTRADO." << endl;
                setAutorResenia(DevolverUsuario(nomtemp));
                flag_repeticion = true;
            } else {
                cout << "EL USUARIO INGRESADO NO EXISTE EN LA BASE DE DATOS." << endl;
            }
        }

        cout << "PEL�CULA A RESE�AR: " << endl;
        flag_repeticion = false;

        while (flag_repeticion != true) {
            cargarCadena(pelitemp, 30);

            if (VerificarExistenciaPelicula(pelitemp) == true) {
                cout << "PEL�CULA ENCONTRADA." << endl;
                setPeliculaResenia(DevolverPelicula(pelitemp));
                flag_repeticion = true;
            } else {
                cout << "LA PEL�CULA INGRESADA NO EXISTE EN LA BASE DE DATOS." << endl;
            }
        }

        if (VerificarExistenciaReseniaDePelicula(_autorResenia, _peliculaResenia)) {
            cout << "ESTE USUARIO YA HA REALIZADO UNA RESE�A PARA ESTA PEL�CULA." << endl;
            system("pause");
            return;
        }

        cout << "OPINI�N: ";
        cargarCadena(opinionTemporal, 200);
        setOpinion(opinionTemporal);

        cout << "FECHA: ";
        _fechaResenia.Cargar();

        cout << "PUNTUACI�N 0 al 10 (SE ACEPTAN FLOATS): ";
        flag_repeticion = false;

        while (flag_repeticion != true) {
            cin >> puntuacionTemporal;
            if (puntuacionTemporal>=0||puntuacionTemporal<=10) {
                setPuntuacionResenia(puntuacionTemporal);
                flag_repeticion = true;
            } else {
                cout << "EL PUNTAJE ES INVALIDO." << endl;
            }
        }
        setEstado(true);
    }

    // M�todo para mostrar una rese�a
    void Mostrar() {
        if (getEstado()) {
            cout << "ID RESE�A: " << _idResenia << endl;
            cout << "AUTOR RESE�A: ";
            char nombretemp[30];
            strcpy(nombretemp, _autorResenia.getNombreUsuario());
            cout << nombretemp;

            cout << "PEL�CULA A RESE�AR: " << endl;
            char pelitemp[30];
            strcpy(pelitemp, _peliculaResenia.getNombrePelicula());
            cout << pelitemp;

            cout << "OPINI�N: " << _opinion << endl;

            cout << "FECHA: ";
            _fechaResenia.Mostrar();

            cout << "PUNTUACI�N: " << _puntuacionResenia << endl;
        }
    }
    //Sobrecarga

    bool operator>(float puntajeTemp){
        if (_puntuacionResenia>puntajeTemp) return true;
        return false;
    }
};

#endif // CLASE_RESENIA_H_INCLUDED
