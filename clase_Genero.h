#ifndef CLASE_GENERO_H_INCLUDED
#define CLASE_GENERO_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/
bool VerificarExistenciaGenero(const char *primgenero);

//Los registros de Genero son AUTONUMERICOS.

class Genero {

//Propiedades
  private:
    int _idGenero;
    char _nombreGenero[30];
    bool _estado;


//Metodos
  public:
    //sets()

    //No corresponde un setId, dado que es autonumerico.

    void setNombreGenero(const char *input) {
        strcpy(_nombreGenero,input);
    }

    void setEstado(bool input) {
        _estado=input;
    }

    //gets()

    int getIdGenero() {
        return _idGenero;
    }

    const char *getNombreGenero() {
        return _nombreGenero;
    }

    bool getEstado() {
        return _estado;
    }

    //Otros

    void Cargar() {
        char nombreTemporal[30];

        _idGenero = DeterminarPosicionAutonumerica("Generos.dat", sizeof(Genero));

        cout<<"NOMBRE: ";
        bool flag_repeticion = false;
        while (flag_repeticion != true) {
            cargarCadena(nombreTemporal, 30);
            if (VerificarExistenciaGenero(nombreTemporal) == true) {
                cout << "EL GENERO YA EXISTE." << endl;
            } else {
                cout << "REGISTRADO." << endl;
                flag_repeticion = true;
            }
        }
        setNombreGenero(nombreTemporal);
        setEstado(true);
    }

    //while(nombreTemporal[0]=='\0') PODRIA SER UNA FORMA DE VERIFICAR:


    void Mostrar() {
        if (getEstado()) {
            cout<<"ID GENERO: ";
            cout<<_idGenero<<endl;
            cout<<"NOMBRE: ";
            cout<<_nombreGenero<<endl;
        }
    }

};


#endif // CLASE_GENERO_H_INCLUDED
