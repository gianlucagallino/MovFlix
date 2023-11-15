#ifndef MENU_DIRECTORES_H_INCLUDED
#define MENU_DIRECTORES_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

bool AltaDirector();
bool BajaDirector();
bool ModificarDirector();
bool ListarDirector();
bool MostrarTodoDirector();

void MenuDirectores() {
    char op;
    bool correrMenu = true;
    while(correrMenu) {
        system("cls");
        cout << endl;
        cout << "          MENU DIRECTORES        " << endl;
        cout << "---------------------------------" << endl;
        cout << " A - ALTA DE UN DIRECTOR         " << endl;
        cout << " B - BAJA DE UN DIRECTOR         " << endl;
        cout << " C - MODIFICAR NOMBRE DIRECTOR   " << endl;
        cout << " D - MOSTRAR DIRECTOR POR ID     " << endl;
        cout << " E - MOSTRAR TODOS LOS DIRECTORES" << endl;
        cout << "---------------------------------" << endl;
        cout << " X - VOLVER AL MENU PRINCIPAL    " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        op=toupper(op); //Funcion de cstdlib, que transforma un input minuscula en mayuscula. Es incluido por conveniencia.
        system("cls");
        switch (op) {
        case 'A':
            AltaDirector();
            break;
        case 'B':
            BajaDirector();
            break;
        case 'C':
            ModificarDirector();
            break;
        case 'D':
            ListarDirector();
            break;
        case 'E':
            MostrarTodoDirector();
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
// Agrega un nuevo registro de director al archivo "Directores.dat".
bool AltaDirector() {
    Director temp;
    ArchivoDirectores archivo("Directores.dat");
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

// Realiza la baja de un director por ID, cambiando su estado a inactivo en el archivo "Directores.dat".
bool BajaDirector() {
    int ID;
    Director temp;
    ArchivoDirectores archivo("Directores.dat");

    cout << "SUS OPCIONES SON: "<<endl;
    archivo.listarRegistros();
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

// Modifica el nombre de un director por ID en el archivo "Directores.dat".
bool ModificarDirector() {
    int ID;
    Director temp;
    ArchivoDirectores archivo("Directores.dat");
    char nombreTemp[30];

    cout << "SUS OPCIONES SON: "<<endl;
    archivo.listarRegistros();
    cout << "INGRESAR ID DIRECTOR CUYO NOMBRE MODIFICAR: ";
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
    temp.setNombreDirector(nombreTemp);
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

// Muestra la información de un director por ID desde el archivo "Directores.dat".
bool ListarDirector() {
    int ID;
    Director temp;
    ArchivoDirectores archivo("Directores.dat");
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

// Muestra la lista completa de directores desde el archivo "Directores.dat".
bool MostrarTodoDirector() {
    ArchivoDirectores archivo("Directores.dat");
    archivo.listarRegistros();
    system("pause");
    system("cls");
    return true;
}


#endif // MENU_DIRECTORES_H_INCLUDED
