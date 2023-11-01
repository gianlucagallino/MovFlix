#ifndef CLASE_RESENIA_H_INCLUDED
#define CLASE_RESENIA_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

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

        char opinionTemporal[200];
        int puntuacionTemporal;

        _idResenia  = DeterminarPosicionAutonumerica("Resenias.dat", sizeof(Resenia));
        cout<<"AUTOR RESENIA: "<<endl;
        _autorResenia.Cargar();
        cout<<"PELICULA A RESENIAR: "<<endl;
        _peliculaResenia.Cargar();
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
            cout<<_idResenia;
            cout<<"AUTOR RESENIA: "<<endl;
            _autorResenia.Mostrar();
            cout<<"PELICULA A RESENIAR: "<<endl;
            _peliculaResenia.Mostrar();
            cout<<"OPINION: ";
            cout<<_opinion;
            cout<<"FECHA: ";
            _fechaResenia.Mostrar();
            cout<<"PUNTUACION: ";
            cout<<_puntuacionResenia;
            cout<<endl;
        }
    }
};

#endif // CLASE_RESENIA_H_INCLUDED
