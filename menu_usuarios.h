#ifndef MENU_USUARIOS_H_INCLUDED
#define MENU_USUARIOS_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

//Este archivo contiene el menu de usuarios, y sus funciones de ABML.

bool AltaUsuario();
bool BajaUsuario();
bool ModificarUsuario();
bool ListarUsuario();
bool MostrarTodoUsuario();

void MenuUsuarios() {
    int op;
    bool correrMenu = true;
    while(correrMenu) {
        system("cls");
        cout << endl;
        cout << "           MENU USUARIOS         " << endl;
        cout << "---------------------------------" << endl;
        cout << " 1 - ALTA DE UN USUARIO          " << endl;
        cout << " 2 - BAJA DE UN USUARIO          " << endl;
        cout << " 3 - MODIFICAR NOMBRE USUARIO    " << endl;
        cout << " 4 - LISAR USUARIO POR ID        " << endl;
        cout << " 5 - MOSTRAR TODOS LOS USUARIOS  " << endl;
        cout << "---------------------------------" << endl;
        cout << " 0 - VOLVER AL MENU PRINCIPAL    " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        system("cls");
        switch (op) {
        case 1:
            AltaUsuario();
            break;
        case 2:
            BajaUsuario();
            break;
        case 3:
            ModificarUsuario();
            break;
        case 4:
            ListarUsuario();
            break;
        case 5:
            MostrarTodoUsuario();
            break;
        case 0:
            correrMenu = false;
            break;
        default:
            cout << "POR FAVOR, INGRESAR UNA OPCION CORRECTA" << endl;
            rlutil::msleep(2000);
            system("cls");
            break;
        }

    }
    return;
}
// Agrega un nuevo registro de usuario al archivo "Usuarios.dat".
bool AltaUsuario() {
    Usuario temp;
    ArchivoUsuarios archivo("Usuarios.dat");
    temp.Cargar();
    if (archivo.agregarRegistro(temp)) {
        cout << "REGISTRO AGREGADO" << endl;
        system("pause");
        return true;
    } else {
        cout << "NO SE AGREGO" << endl;
        system("pause");
        return false;
    }
}

// Realiza la baja de un usuario por ID, cambiando su estado a inactivo en el archivo "Usuarios.dat".
bool BajaUsuario() {
    int ID;
    Usuario temp;
    ArchivoUsuarios archivo("Usuarios.dat");
    cout << "INGRESAR ID A BORRAR: ";
    cin >> ID;
    system("cls");
    int pos = archivo.buscarRegistro(ID);
    if (pos == -1) {
        cout << "NO EXISTE" << endl;
        system("pause");
        system("cls");
        return false;
    } else if (pos == -2) {
        return false;
    }
    temp = archivo.leerRegistro(pos);
    temp.setEstado(false);
    bool existe = archivo.modificarRegistro(pos, temp);
    if (existe == false) {
        cout << "PROBLEMA AL ESCRIBIR" << endl;
        system("pause");
        return false;
    } else {
        cout << "Dado de baja." << endl;
        system("pause");
    }
    return true;
}

// Modifica el nombre de un usuario por ID en el archivo "Usuarios.dat".
bool ModificarUsuario() {
    int ID;
    Usuario temp;
    char nombreTemp[30];
    ArchivoUsuarios archivo("Usuarios.dat");
    cout << "INGRESAR ID CUYO NOMBRE MODIFICAR: ";
    cin >> ID;
    system("cls");
    int pos = archivo.buscarRegistro(ID);
    if (pos == -1) {
        cout << "NO EXISTE" << endl;
        system("pause");
        system("cls");
        return false;
    } else if (pos == -2) {
        return false;
    }
    cout << "INGRESE NUEVO NOMBRE" << endl;
    cargarCadena(nombreTemp, 30);
    while (nombreTemp[0] == '\0') cargarCadena(nombreTemp, 30);
    temp = archivo.leerRegistro(pos);
    temp.setNombreUsuario(nombreTemp);
    bool existe = archivo.modificarRegistro(pos, temp);
    if (existe == false) {
        cout << "PROBLEMA AL ESCRIBIR" << endl;
        system("pause");
        return false;
    } else {
        cout << "MODIFICADO!" << endl;
        system("pause");
    }
    return true;
}

// Muestra la información de un usuario por ID desde el archivo "Usuarios.dat".
bool ListarUsuario() {
    int ID;
    Usuario temp;
    ArchivoUsuarios archivo("Usuarios.dat");
    cout << "INGRESAR ID A BUSCAR: ";
    cin >> ID;
    int pos = archivo.buscarRegistro(ID);
    if (pos == -1) {
        cout << "NO EXISTE" << endl;
        system("pause");
        system("cls");
        return false;
    } else if (pos == -2) {
        return false;
    }
    temp = archivo.leerRegistro(pos);
    temp.Mostrar();
    system("pause");
    system("cls");
    return true;
}

// Muestra la lista completa de usuarios desde el archivo "Usuarios.dat".
bool MostrarTodoUsuario() {
    ArchivoUsuarios archivo("Usuarios.dat");
    archivo.listarRegistros();
    system("pause");
    system("cls");
    return true;
}

#endif // MENU_USUARIOS_H_INCLUDED
