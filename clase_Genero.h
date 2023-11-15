#ifndef CLASE_GENERO_H_INCLUDED
#define CLASE_GENERO_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

//Los registros son AUTONUMERICOS.

// Declaraci�n de la funci�n para verificar la existencia de un g�nero
bool VerificarExistenciaGenero(int primgenero);
bool VerificarExistenciaNomGenero(const char *primgenero);

// Definici�n de la clase Genero
class Genero {
  private:
    int _idGenero;               // Propiedad para el ID del g�nero
    char _nombreGenero[30];      // Propiedad para el nombre del g�nero
    bool _estado;                // Propiedad que indica el estado del g�nero

  public:

    //No corresponde un setId, dado que es autonumerico.

    // M�todo para establecer el nombre del g�nero
    void setNombreGenero(const char *input) {
        strcpy(_nombreGenero, input);
    }

    // M�todo para establecer el estado del g�nero
    void setEstado(bool input) {
        _estado = input;
    }

    // M�todo para obtener el ID del g�nero
    int getIdGenero() {
        return _idGenero;
    }

    // M�todo para obtener el nombre del g�nero
    const char *getNombreGenero() {
        return _nombreGenero;
    }

    // M�todo para obtener el estado del g�nero
    bool getEstado() {
        return _estado;
    }

    // M�todo para cargar un g�nero
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

    // M�todo para mostrar un g�nero
    void Mostrar() {
        if (getEstado()) {
            cout << "ID GENERO: " << _idGenero << endl;
            cout << "NOMBRE: " << _nombreGenero << endl;
        }
    }
};

#endif // CLASE_GENERO_H_INCLUDED
