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
    char pelicula_a_buscar[30];
    int idusuario;
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

        int idTemporal_Usuario;
        char opinionTemporal[200];
        bool flag_repeticion = false;
        bool flag_repeticion1 = false;
        int puntuacionTemporal;

        _idResenia  = DeterminarPosicionAutonumerica("Resenias.dat", sizeof(Resenia));
        cout<<"ID DEL AUTOR DE LA RESENIA: "<<endl;
        /// REALIZAR FUNCION CON SOBRECARGA DE OPERADORES QUE COMPARE CON EL == EL ID DE AUTOR QUE SE RECIBA CON LOS ID YA GUARDADOS
        while (flag_repeticion1 != true){
            cin >> idTemporal_Usuario;
            idusuario = idTemporal_Usuario;
            if (EncontrarUsuario(idusuario) == true){
                cout << "Usuario ENCONTRADA." << endl;
                flag_repeticion1 = true;
            }else{
                cout << "EL USUARIO INGRESADA NO EXISTE EN LA BASE DE DATOS." << endl;
            }
        }
        cout<<"PELICULA A RESENIAR: "<<endl;
        while (flag_repeticion != true){
            cargarCadena(pelicula_a_buscar,30);
            if (EncontrarPelicula(pelicula_a_buscar) == true){
                cout << "PELICULA ENCONTRADA." << endl;
                flag_repeticion = true;
            }else{
                cout << "LA PELICULA INGRESADA NO EXISTE EN LA BASE DE DATOS." << endl;
            }
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
            MostrarUsuario(idusuario);
            cout<<"PELICULA A RESENIAR: "<<endl;
            MostrarPelicula(pelicula_a_buscar);
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
