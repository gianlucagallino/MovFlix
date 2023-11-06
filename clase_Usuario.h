#ifndef CLASE_USUARIO_H_INCLUDED
#define CLASE_USUARIO_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/


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

        _idUsuario = DeterminarPosicionAutonumerica("Usuarios.dat", sizeof(Usuario));
        cout<<"NOMBRE USUARIO: ";
        cargarCadena(nombreTemporal, 30);
        while(nombreTemporal[0]=='\0') cargarCadena(nombreTemporal, 30);;
        setNombreUsuario(nombreTemporal);
        cout<<"EMAIL: ";
        cargarCadena(emailTemporal, 30);
        while(emailTemporal[0]=='\0') cargarCadena(emailTemporal, 30);;
        setEmail(emailTemporal);
        cout<<"GENERO FAVORITO: "<<endl;
        _generoFavorito.Cargar();
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
            cout<<_generoFavorito.getNombreGenero();
            cout<<endl;
            cout<<endl;
        }
    }
};

#endif // CLASE_USUARIO_H_INCLUDED
