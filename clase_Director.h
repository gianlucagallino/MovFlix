#ifndef CLASE_DIRECTOR_H_INCLUDED
#define CLASE_DIRECTOR_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

//Los registros son AUTONUMERICOS.

// Declaraci�n de la funci�n para verificar la existencia de un director por nombre
bool VerificarExistenciaNDirector(int primdirector);
bool VerificarExistenciaNomDirector(const char *primdirector);

// Definici�n de la clase Director
class Director {
    // Propiedades
  private:
    int _idDirector;           // Identificador �nico del director (autonum�rico)
    char _nombreDirector[30];  // Nombre del director
    bool _estado;              // Estado del director (activo/inactivo)

    // M�todos p�blicos
  public:

    //No corresponde un setId, dado que es autonumerico.

    // Establece el nombre del director
    void setNombreDirector(const char *input) {
        strcpy(_nombreDirector, input);
    }

    // Establece el estado del director (activo/inactivo)
    void setEstado(bool input) {
        _estado = input;
    }

    // Obtiene el ID del director
    int getIdDirector() {
        return _idDirector;
    }

    // Obtiene el nombre del director
    const char *getNombreDirector() {
        return _nombreDirector;
    }

    // Obtiene el estado del director (activo/inactivo)
    bool getEstado() {
        return _estado;
    }

    // M�todo para cargar un nuevo director
    void Cargar() {
        char nombreTemporal[30];

        // Determina la posici�n autonum�rica
        _idDirector = DeterminarPosicionAutonumerica("Directores.dat", sizeof(Director));

        cout << "NOMBRE: ";
        cargarCadena(nombreTemporal, 30);
        while(nombreTemporal[0]=='\0'||VerificarExistenciaNomDirector(nombreTemporal)) {
            cout<<"INPUT VACIO O REGISTRO YA EXISTENTE"<<endl;
            system ("pause");
            system ("cls");
            cout << "NOMBRE: ";
            cargarCadena(nombreTemporal, 30);
        }
        setNombreDirector(nombreTemporal);
        setEstado(true);
    }

    // M�todo para mostrar informaci�n del director
    void Mostrar() {
        if (getEstado()) {
            cout << "ID DIRECTOR: " << _idDirector << endl;
            cout << "NOMBRE: " << _nombreDirector << endl;
        }
    }
};


#endif // CLASE_DIRECTOR_H_INCLUDED
