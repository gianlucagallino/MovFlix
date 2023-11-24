#ifndef CLASE_RESENIA_H_INCLUDED
#define CLASE_RESENIA_H_INCLUDED

//Los registros son AUTONUMERICOS.

// Declaración de la función para verificar la existencia de una reseña de una película
bool VerificarExistenciaReseniaDePelicula(int idescritor, int idpeli);
void MostraEquivalenciaPeliculaPorId(int id);
void MostraEquivalenciaUsuarioPorId(int id);

// Definición de la clase Resenia
class Resenia {
  private:
    int _idResenia;                 // Propiedad para el ID de la reseña
    int _idautorResenia;         // Propiedad para el ID de autor de la reseña
    int _idpeliculaResenia;      // Propiedad para la ID de película relacionada con la reseña
    char _opinion[200];             // Propiedad para la opinión de la reseña
    Fecha _fechaResenia;            // Propiedad para la fecha de la reseña
    float _puntuacionResenia;         // Propiedad para la puntuación de la reseña
    bool _estado;                   // Propiedad que indica el estado de la reseña

  public:
    // Métodos para establecer las propiedades de la reseña

    //No corresponde un setId, dado que es autonumerico.

    void setidAutorResenia(int input) {
        _idautorResenia = input;
    }

    void setidPeliculaResenia(int input) {
        _idpeliculaResenia = input;
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

    int getidAutorResenia() {
        return _idautorResenia;
    }

    int getidPeliculaResenia() {
        return _idpeliculaResenia;
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
    bool Cargar() {
        int idusuariotemp;
        int idpelitemp;
        char opinionTemporal[200];
        bool flag_repeticion = false;
        float puntuacionTemporal;
        ArchivoUsuarios archUs ("Usuarios.dat");
        ArchivoPeliculas archPel("Peliculas.dat");

        _idResenia  = DeterminarPosicionAutonumerica("Resenias.dat", sizeof(Resenia));

        cout << "SUS OPCIONES SON: "<<endl<<endl;
        archUs.listarRegistros();
        cout << "ID USUARIO AUTOR DE LA RESENIA (NUMERO ENTERO SOLAMENTE): " << endl;

        flag_repeticion = false;

        while (flag_repeticion != true) {
            cin>>idusuariotemp;

            if (VerificarExistenciaUsuario(idusuariotemp) == true) {
                cout << "USUARIO ENCONTRADO." << endl;
                setidAutorResenia(idusuariotemp);
                flag_repeticion = true;
            } else {
                cout << "EL USUARIO INGRESADO NO EXISTE EN LA BASE DE DATOS." << endl;
            }
        }


        cout << "SUS OPCIONES SON: "<<endl<<endl;
        archPel.listarRegistros();
        cout << "ID PELICULA A RESENIAR (NUMERO ENTERO SOLAMENTE): " << endl;
        flag_repeticion = false;

        while (flag_repeticion != true) {
            cin>>idpelitemp;

            if (VerificarExistenciaPelicula(idpelitemp) == true) {
                cout << "PELICULA ENCONTRADA." << endl;
                setidPeliculaResenia(idpelitemp);
                flag_repeticion = true;
            } else {
                cout << "LA PELICULA INGRESADA NO EXISTE EN LA BASE DE DATOS." << endl;
            }
        }

        if (VerificarExistenciaReseniaDePelicula(_idautorResenia, _idpeliculaResenia)) {
            cout << "ESTE USUARIO YA HA REALIZADO UNA RESENIA PARA ESTA PELICULA." << endl;
            system("pause");
            return false;
        }

        cout << "OPINION: ";
        cargarCadena(opinionTemporal, 200);
        setOpinion(opinionTemporal);

        cout << "FECHA: ";
        _fechaResenia.Cargar();

        cout << "PUNTUACION 0 A 10, CON DECIMALES SEPARADOS POR PUNTO SI ES NECESARIO: ";
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
        return true;
    }

    // Método para mostrar una reseña
    void Mostrar() {
        if (getEstado()) {
            cout << "ID RESENIA: " << _idResenia << endl;
            cout << "ID AUTOR RESENIA: ";

            cout << _idautorResenia<<endl;

            cout << "NOMBRE USUARIO AUTOR DE RESENIA: ";

            MostraEquivalenciaUsuarioPorId(_idautorResenia);

            cout << "ID PELICULA A RESENIAR: ";

            cout << _idpeliculaResenia<<endl;

            cout << "NOMBRE PELICULA: ";
            MostraEquivalenciaPeliculaPorId(_idpeliculaResenia);

            cout << "OPINION: " << _opinion << endl;

            cout << "FECHA: ";
            _fechaResenia.Mostrar();

            cout << "PUNTUACION: " << _puntuacionResenia << endl << endl;
        }
    }
    //Sobrecarga

    bool operator>(float puntajeTemp) {
        if (_puntuacionResenia>puntajeTemp) return true;
        return false;
    }
};

#endif // CLASE_RESENIA_H_INCLUDED
