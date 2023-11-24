#ifndef MENU_USUARIOS_H_INCLUDED
#define MENU_USUARIOS_H_INCLUDED

//Este archivo contiene el menu de usuarios, y sus funciones de ABML.

bool AltaUsuario();
bool BajaUsuario();
bool ModificarUsuario();
bool ListarUsuario();
bool MostrarTodoUsuario();

void MenuUsuarios() {
    char op;
    bool correrMenu = true;
    while(correrMenu) {
        system("cls");
        cout << endl;
        cout << "           MENU USUARIOS         " << endl;
        cout << "---------------------------------" << endl;
        cout << " A - ALTA DE UN USUARIO          " << endl;
        cout << " B - BAJA DE UN USUARIO          " << endl;
        cout << " C - MODIFICAR NOMBRE USUARIO    " << endl;
        cout << " D - LISTAR USUARIO POR ID        " << endl;
        cout << " E - MOSTRAR TODOS LOS USUARIOS  " << endl;
        cout << "---------------------------------" << endl;
        cout << " X - VOLVER AL MENU PRINCIPAL    " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        op = toupper(op);
        system("cls");
        switch (op) {
        case 'A':
            AltaUsuario();
            break;
        case 'B':
            BajaUsuario();
            break;
        case 'C':
            ModificarUsuario();
            break;
        case 'D':
            ListarUsuario();
            break;
        case 'E':
            MostrarTodoUsuario();
            break;
        case 'X':
            correrMenu = false;
            break;
        default:
            gotoxy(10,10);
            rlutil::anykey("POR FAVOR, INGRESAR UNA OPCION CORRECTA (PRESIONE BOTON PARA CONTINUAR)");
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
    return false;
}

// Realiza la baja de un usuario por ID, cambiando su estado a inactivo en el archivo "Usuarios.dat".
bool BajaUsuario() {
    int ID;
    Usuario temp;
    ArchivoUsuarios archivo("Usuarios.dat");
    cout << "SUS OPCIONES SON: "<<endl;
    archivo.listarRegistros();
    cout << "INGRESAR ID (NUMERO ENTERO) A BORRAR: ";
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
    cout << "SUS OPCIONES SON: "<<endl;
    archivo.listarRegistros();
    cout << "INGRESAR ID USUARIO (NUMERO ENTERO) CUYO NOMBRE MODIFICAR: ";
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
    cout << "INGRESAR ID (NUMERO ENTERO) A BUSCAR: ";
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
