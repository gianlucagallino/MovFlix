#ifndef CLASE_GENERO_H_INCLUDED
#define CLASE_GENERO_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

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

        _idGenero = DeterminarPosicionAutonumerica("Generos.dat", sizeof(genero));

        cout<<"NOMBRE: ";
        cargarCadena(nombreTemporal, 30);
        setNombreGenero(nombreTemporal);
        setestado(true);
    }

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
