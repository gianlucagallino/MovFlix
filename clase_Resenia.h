#ifndef CLASE_RESENIA_H_INCLUDED
#define CLASE_RESENIA_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

bool VerificarExistenciaReseniaDePelicula(Usuario escritor, Pelicula peli);

class Resenia {

//Propiedades
  private:
    int _idResenia;
    Usuario _autorResenia;
    Pelicula _peliculaResenia;
    char _opinion[200];
    Fecha _fechaResenia;
    int _puntuacionResenia;
    bool _estado;

//Metodos
  public:
    //sets()

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

    void setPuntuacionResenia(int input) {
        _puntuacionResenia = input;
    }

    void setEstado(bool input) {
        _estado = input;
    }

    //gets()

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

    int getPuntuacionResenia() {
        return _puntuacionResenia;
    }

    bool getEstado() {
        return _estado;
    }

    //Otros

    void Cargar() {

        char nomtemp[30];
        char pelitemp[30];
        char opinionTemporal[200];
        bool flag_repeticion = false;
        int puntuacionTemporal;

        _idResenia  = DeterminarPosicionAutonumerica("Resenias.dat", sizeof(Resenia));
        cout<<"NOMBRE AUTOR DE LA RESENIA: "<<endl;
       flag_repeticion = false;
        while (flag_repeticion != true) {
            cargarCadena(nomtemp,30);
            if (VerificarExistenciaUsuario(nomtemp) == true) {
                cout << "Usuario ENCONTRADA." << endl;
                setAutorResenia(DevolverUsuario(nomtemp));
                flag_repeticion = true;
            } else {
                cout << "EL USUARIO INGRESADA NO EXISTE EN LA BASE DE DATOS." << endl;
            }
        }
        cout<<"PELICULA A RESENIAR: "<<endl;
        flag_repeticion = false;
        while (flag_repeticion != true) {
            cargarCadena(pelitemp,30);
            if (VerificarExistenciaPelicula(pelitemp) == true) {
                cout << "PELICULA ENCONTRADA." << endl;
                setPeliculaResenia(DevolverPelicula(pelitemp));
                flag_repeticion = true;
            } else {
                cout << "LA PELICULA INGRESADA NO EXISTE EN LA BASE DE DATOS." << endl;
            }
        }
        if (VerificarExistenciaReseniaDePelicula(_autorResenia, _peliculaResenia)){
            cout<<"ESTE USUARIO YA RESENIO ESTA PELICULA. "<<endl;
            system("pause");
            return;
        }
        cout<<"OPINION: ";
        cargarCadena(opinionTemporal, 200);
        setOpinion(opinionTemporal);
        cout<<"FECHA: ";
        _fechaResenia.Cargar();
        cout<<"PUNTUACION: ";
        cin >> puntuacionTemporal;
        setPuntuacionResenia(puntuacionTemporal);
        setEstado(true);
    }

    void Mostrar() {
        if (getEstado()) {
            cout<<"ID RESENIA: ";
            cout<<_idResenia<<endl;
            cout<<"AUTOR RESENIA: ";
            char nombretemp[30];
            strcpy(nombretemp,_autorResenia.getNombreUsuario());
            cout<<nombretemp;
            cout<<"PELICULA A RESENIAR: "<<endl;
            char pelitemp[30];
            strcpy(pelitemp,_peliculaResenia.getNombrePelicula());
            cout<<pelitemp;
            cout<<"OPINION: ";
            cout<<_opinion << endl;
            cout<<"FECHA: ";
            _fechaResenia.Mostrar();
            cout<<"PUNTUACION: ";
            cout<<_puntuacionResenia;
            cout<<endl;
        }
    }
};

#endif // CLASE_RESENIA_H_INCLUDED
