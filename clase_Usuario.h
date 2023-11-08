#ifndef CLASE_USUARIO_H_INCLUDED
#define CLASE_USUARIO_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

bool VerificarExistenciaUsuario(const char *nom);

//Los registros son AUTONUMERICOS.

class Usuario {

//Propiedades
  private:
    int _idUsuario;
    char _nombreUsuario[30];
    char _email[30];
    Genero _generoFavorito;
    bool _estado;

//Metodos
  public:
    //sets()

    //No corresponde un setId, dado que es autonumerico.

    void setNombreUsuario(const char *input) {
        strcpy(_nombreUsuario,input);
    }

    void setEmail(const char *input) {
        strcpy(_email,input);
    }

    void setGeneroFavorito(Genero input) {
        _generoFavorito = input;
    }

    void setEstado(bool input) {
        _estado = input;
    }

    //gets()

    int getIdUsuario() {
        return _idUsuario;
    }

    const char *getNombreUsuario() {
        return _nombreUsuario;
    }

    const char *getEmail() {
        return _email;
    }

    Genero getGeneroFavorito() {
        return _generoFavorito;
    }

    bool getEstado() {
        return _estado;
    }

    //Otros

    void Cargar() {

        char nombreTemporal[30];
        char emailTemporal[30];
        char generoTemporal[30];
        bool flag_repeticion = false;

        _idUsuario = DeterminarPosicionAutonumerica("Usuarios.dat", sizeof(Usuario));
        cout<<"NOMBRE USUARIO: ";
        flag_repeticion = false;
        while (flag_repeticion != true) {
            cargarCadena(nombreTemporal, 30);
            if (VerificarExistenciaUsuario(nombreTemporal) == true) {
                cout << "EL USUARIO YA EXISTE." << endl;
            } else {
                cout << "REGISTRADO." << endl;
                flag_repeticion = true;
            }
        }
        setNombreUsuario(nombreTemporal);
        while(nombreTemporal[0]=='\0') cargarCadena(nombreTemporal, 30);;
        setNombreUsuario(nombreTemporal);
        cout<<"EMAIL: ";
        cargarCadena(emailTemporal, 30);
        while(emailTemporal[0]=='\0') cargarCadena(emailTemporal, 30);;
        setEmail(emailTemporal);
        cout<<"GENERO FAVORITO: "<<endl;
        flag_repeticion = false;
        while (flag_repeticion != true) {
            cargarCadena(generoTemporal, 30);
            if (VerificarExistenciaGenero(generoTemporal) == true) {
                cout << "GENERO ENCONTRADO." << endl;
                setGeneroFavorito(DevolverGenero(generoTemporal));
                flag_repeticion = true;
            } else {
                cout << "EL GENERO NO EXISTE." << endl;
            }
        }
        setEstado(true);
    }

    void Mostrar() {
        if (getEstado()) {
            cout<<"ID USUARIO: ";
            cout<<_idUsuario<<endl;
            cout<<"NOMBRE USUARIO: ";
            cout<<_nombreUsuario<<endl;
            cout<<"EMAIL: ";
            cout<<_email<<endl;
            cout<<"GENERO FAVORITO: ";
            char generotemp[30];
            strcpy(generotemp,_generoFavorito.getNombreGenero());
            cout<<generotemp;
            cout<<endl;
            cout<<endl;
        }
    }
};

#endif // CLASE_USUARIO_H_INCLUDED
