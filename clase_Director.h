#ifndef CLASE_DIRECTOR_H_INCLUDED
#define CLASE_DIRECTOR_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

bool VerificarExistenciaDirector(const char *primdirector);

//Los registros de Director son AUTONUMERICOS.

class Director {

//Propiedades
  private:
    int _idDirector;
    char _nombreDirector[30];
    bool _estado;

//Metodos
  public:
    //sets()

    //No corresponde un setId, dado que es autonumerico.

    void setNombreDirector(const char *input) {
        strcpy(_nombreDirector,input);
    }

    void setEstado(bool input) {
        _estado = input;
    }

    //gets()

    int getIdDirector() {
        return _idDirector;
    }

    const char *getNombreDirector() {
        return _nombreDirector;
    }

    bool getEstado() {
        return _estado;
    }

    //Otros

    void Cargar() {

        char nombreTemporal[30];

        _idDirector = DeterminarPosicionAutonumerica("Directores.dat", sizeof(Director));
        cout<<"NOMBRE: ";

        bool flag_repeticion = false;
        while (flag_repeticion != true) {
            cargarCadena(nombreTemporal, 30);
            if (VerificarExistenciaUsuario(nombreTemporal) == true) {
                cout << "EL DIRECTOR YA EXISTE." << endl;
            } else {
                cout << "REGISTRADO." << endl;
                flag_repeticion = true;
            }
        }
        setNombreDirector(nombreTemporal);
        setEstado(true);
    }

    void Mostrar() {
        if (getEstado()) {
            cout<<"ID DIRECTOR: ";
            cout<<_idDirector<<endl;
            cout<<"NOMBRE: ";
            cout<<_nombreDirector<<endl;
        }
    }
};


#endif // CLASE_DIRECTOR_H_INCLUDED
