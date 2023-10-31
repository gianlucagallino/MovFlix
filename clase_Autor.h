#ifndef CLASE_AUTOR_H_INCLUDED
#define CLASE_AUTOR_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/


//Los registros de Autor son AUTONUMERICOS.

class Autor {

//Propiedades
  private:
    int _idAutor;
    char _nombreAutor[30];
    bool _estado;

//Metodos
  public:
    //sets()

    //No corresponde un setId, dado que es autonumerico.

    void setNombreAutor(const char *input) {
        strcpy(_nombreAutor,input);
    }

    void setEstado(bool input) {
        _estado = input;
    }

    //gets()

    int getIdAutor() {
        return _idAutor;
    }

    const char *getNombreAutor() {
        return _nombreAutor;
    }

    bool getEstado() {
        return _estado;
    }

    //Otros

    void Cargar() {

        char nombreTemporal[30];

        _idAutor = DeterminarPosicionAutonumerica("Autores.dat", sizeof(Autor));
        cout<<"NOMBRE: ";
        cargarCadena(nombreTemporal, 30);
        setNombreAutor(nombreTemporal);
        setEstado(true);
    }

    void Mostrar() {
        if (getEstado()) {
            cout<<"ID AUTOR: ";
            cout<<_idAutor<<endl;
            cout<<"NOMBRE: ";
            cout<<_nombreAutor<<endl;
        }
    }
};


#endif // CLASE_AUTOR_H_INCLUDED
