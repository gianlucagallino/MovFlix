#ifndef MENU_GENEROS_H_INCLUDED
#define MENU_GENEROS_H_INCLUDED

//En este archivo se encuentra el menu, y sus funciones.

bool AltaGenero();
bool BajaGenero();
bool ModificarGenero();
bool ListarGenero();
bool MostrarTodoGenero();

void MenuGeneros() {
    char op;
    bool correrMenu = true;
    while(correrMenu) {
        system("cls");
        cout << endl;
        cout << "           MENU GENEROS          " << endl;
        cout << "---------------------------------" << endl;
        cout << " A - ALTA DE UN GENERO           " << endl;
        cout << " B - BAJA DE UN GENERO           " << endl;
        cout << " C - MODIFICAR NOMBRE GENERO     " << endl;
        cout << " D - LISTAR GENERO POR ID        " << endl;
        cout << " E - MOSTRAR TODOS LOS GENEROS   " << endl;
        cout << "---------------------------------" << endl;
        cout << " X - VOLVER AL MENU PRINCIPAL    " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        op = toupper(op);
        system("cls");
        switch (op) {
        case 'A':
            AltaGenero();
            break;
        case 'B':
            BajaGenero();
            break;
        case 'C':
            ModificarGenero();
            break;
        case 'D':
            ListarGenero();
            break;
        case 'E':
            MostrarTodoGenero();
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

// Agrega un nuevo registro de género al archivo "Generos.dat".
bool AltaGenero() {
    Genero temp;
    ArchivoGeneros archivo("Generos.dat");
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

// Realiza la baja de un género por ID, cambiando su estado a inactivo en el archivo "Generos.dat".
bool BajaGenero() {
    int ID;
    Genero temp;
    ArchivoGeneros archivo("Generos.dat");

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

// Modifica el nombre de un género por ID en el archivo "Generos.dat".
bool ModificarGenero() {
    int ID;
    Genero temp;
    char nombreTemp[30];
    ArchivoGeneros archivo("Generos.dat");

    cout << "SUS OPCIONES SON: "<<endl;
    archivo.listarRegistros();
    cout << "INGRESAR ID GENERO (NUMERO ENTERO) CUYO NOMBRE MODIFICAR: ";
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
    temp = archivo.leerRegistro(pos);
    temp.setNombreGenero(nombreTemp);
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

// Muestra la información de un género por ID desde el archivo "Generos.dat".
bool ListarGenero() {
    int ID;
    Genero temp;
    ArchivoGeneros archivo("Generos.dat");
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

// Muestra la lista completa de géneros desde el archivo "Generos.dat".
bool MostrarTodoGenero() {
    ArchivoGeneros archivo("Generos.dat");
    archivo.listarRegistros();
    system("pause");
    system("cls");
    return true;
}

#endif // MENU_GENEROS_H_INCLUDED
