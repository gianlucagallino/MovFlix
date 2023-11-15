#ifndef CLASE_USUARIO_H_INCLUDED
#define CLASE_USUARIO_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

bool VerificarExistenciaUsuario(int idusuario);
bool VerificarExistenciaNomUsuario(const char *usuario);
void MostraEquivalenciaGeneroPorId(int id);

//Los registros son AUTONUMERICOS.

class Usuario {

//Propiedades
  private:
    int _idUsuario;
    char _nombreUsuario[30];
    char _email[30];
    int _idgeneroFavorito;
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

    void setidGeneroFavorito(int input) {
        _idgeneroFavorito = input;
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

    int getidGeneroFavorito() {
        return _idgeneroFavorito;
    }

    bool getEstado() {
        return _estado;
    }

    //Otros

    void Cargar() {

        char nombreTemporal[30];
        char emailTemporal[30];
        int generoTemporal;
        bool flag_repeticion = false;
        ArchivoGeneros archGen ("Generos.dat");

        _idUsuario = DeterminarPosicionAutonumerica("Usuarios.dat", sizeof(Usuario));
        cout<<"NOMBRE USUARIO: ";
        cargarCadena(nombreTemporal, 30);
        while(nombreTemporal[0]=='\0'||VerificarExistenciaNomUsuario(nombreTemporal)) {
            cout<<"INPUT VACIO O REGISTRO YA EXISTENTE"<<endl;
            system ("pause");
            system ("cls");
            cout<<"NOMBRE USUARIO: ";
            cargarCadena(nombreTemporal, 30);
        }
        setNombreUsuario(nombreTemporal);
        cout<<"EMAIL: ";
        cargarCadena(emailTemporal, 30);
        while(emailTemporal[0]=='\0') cargarCadena(emailTemporal, 30);
        setEmail(emailTemporal);
        cout << "SUS OPCIONES SON: "<<endl<<endl;
        archGen.listarRegistros();
        cout<<"ID GENERO FAVORITO (NUMERO ENTERO SOLAMENTE): "<<endl;
        flag_repeticion = false;
        while (flag_repeticion != true) {
            cin >> generoTemporal;
            if (VerificarExistenciaGenero(generoTemporal) == true) {
                cout << "GENERO ENCONTRADO." << endl;
                setidGeneroFavorito(generoTemporal);
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
            cout<<"ID GENERO FAVORITO: ";
            cout<<_idgeneroFavorito<<endl;
            cout<<"GENERO FAVORITO: ";
            MostraEquivalenciaGeneroPorId(_idgeneroFavorito);
            cout<<endl<<endl;
        }
    }
};

#endif // CLASE_USUARIO_H_INCLUDED
