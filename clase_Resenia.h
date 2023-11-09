#ifndef CLASE_RESENIA_H_INCLUDED
#define CLASE_RESENIA_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

//Los registros son AUTONUMERICOS.

// Declaración de la función para verificar la existencia de una reseña de una película
bool VerificarExistenciaReseniaDePelicula(Usuario escritor, Pelicula peli);

// Definición de la clase Resenia
class Resenia {
  private:
    int _idResenia;                 // Propiedad para el ID de la reseña
    Usuario _autorResenia;         // Propiedad para el autor de la reseña
    Pelicula _peliculaResenia;      // Propiedad para la película relacionada con la reseña
    char _opinion[200];             // Propiedad para la opinión de la reseña
    Fecha _fechaResenia;            // Propiedad para la fecha de la reseña
    float _puntuacionResenia;         // Propiedad para la puntuación de la reseña
    bool _estado;                   // Propiedad que indica el estado de la reseña

  public:
    // Métodos para establecer las propiedades de la reseña

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

    // Métodos para obtener las propiedades de la reseña
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

    // Método para cargar una reseña
    void Cargar() {
        char nomtemp[30];
        char pelitemp[30];
        char opinionTemporal[200];
        bool flag_repeticion = false;
        int puntuacionTemporal;

        _idResenia  = DeterminarPosicionAutonumerica("Resenias.dat", sizeof(Resenia));
        cout << "NOMBRE AUTOR DE LA RESEÑA: " << endl;
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

        cout << "PELÍCULA A RESEÑAR: " << endl;
        flag_repeticion = false;

        while (flag_repeticion != true) {
            cargarCadena(pelitemp, 30);

            if (VerificarExistenciaPelicula(pelitemp) == true) {
                cout << "PELÍCULA ENCONTRADA." << endl;
                setPeliculaResenia(DevolverPelicula(pelitemp));
                flag_repeticion = true;
            } else {
                cout << "LA PELÍCULA INGRESADA NO EXISTE EN LA BASE DE DATOS." << endl;
            }
        }

        if (VerificarExistenciaReseniaDePelicula(_autorResenia, _peliculaResenia)) {
            cout << "ESTE USUARIO YA HA REALIZADO UNA RESEÑA PARA ESTA PELÍCULA." << endl;
            system("pause");
            return;
        }

        cout << "OPINIÓN: ";
        cargarCadena(opinionTemporal, 200);
        setOpinion(opinionTemporal);

        cout << "FECHA: ";
        _fechaResenia.Cargar();

        cout << "PUNTUACIÓN 0 al 10 (SE ACEPTAN FLOATS): ";
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

    // Método para mostrar una reseña
    void Mostrar() {
        if (getEstado()) {
            cout << "ID RESEÑA: " << _idResenia << endl;
            cout << "AUTOR RESEÑA: ";
            char nombretemp[30];
            strcpy(nombretemp, _autorResenia.getNombreUsuario());
            cout << nombretemp;

            cout << "PELÍCULA A RESEÑAR: " << endl;
            char pelitemp[30];
            strcpy(pelitemp, _peliculaResenia.getNombrePelicula());
            cout << pelitemp;

            cout << "OPINIÓN: " << _opinion << endl;

            cout << "FECHA: ";
            _fechaResenia.Mostrar();

            cout << "PUNTUACIÓN: " << _puntuacionResenia << endl;
        }
    }
    //Sobrecarga

    bool operator>(float puntajeTemp){
        if (_puntuacionResenia>puntajeTemp) return true;
        return false;
    }
};

#endif // CLASE_RESENIA_H_INCLUDED
