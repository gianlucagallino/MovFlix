#ifndef CLASE_GENERO_H_INCLUDED
#define CLASE_GENERO_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

//Los registros son AUTONUMERICOS.

// Declaración de la función para verificar la existencia de un género
bool VerificarExistenciaGenero(int primgenero);
bool VerificarExistenciaNomGenero(const char *primgenero);

// Definición de la clase Genero
class Genero {
  private:
    int _idGenero;               // Propiedad para el ID del género
    char _nombreGenero[30];      // Propiedad para el nombre del género
    bool _estado;                // Propiedad que indica el estado del género

  public:

    //No corresponde un setId, dado que es autonumerico.

    // Método para establecer el nombre del género
    void setNombreGenero(const char *input) {
        strcpy(_nombreGenero, input);
    }

    // Método para establecer el estado del género
    void setEstado(bool input) {
        _estado = input;
    }

    // Método para obtener el ID del género
    int getIdGenero() {
        return _idGenero;
    }

    // Método para obtener el nombre del género
    const char *getNombreGenero() {
        return _nombreGenero;
    }

    // Método para obtener el estado del género
    bool getEstado() {
        return _estado;
    }

    // Método para cargar un género
    void Cargar() {
        char nombreTemporal[30];

        _idGenero=DeterminarPosicionAutonumerica("Generos.dat", sizeof(Genero));

        cout << "NOMBRE: ";
        cargarCadena(nombreTemporal, 30);
        while(nombreTemporal[0]=='\0'||VerificarExistenciaNomGenero(nombreTemporal)) {
            cout<<"INPUT VACIO O REGISTRO YA EXISTENTE"<<endl;
            system ("pause");
            system ("cls");
            cout << "NOMBRE: ";
            cargarCadena(nombreTemporal, 30);
        }
        setNombreGenero(nombreTemporal);
        setEstado(true);
    }

    // Método para mostrar un género
    void Mostrar() {
        if (getEstado()) {
            cout << "ID GENERO: " << _idGenero << endl;
            cout << "NOMBRE: " << _nombreGenero << endl;
        }
    }
};

#endif // CLASE_GENERO_H_INCLUDED
