#ifndef MENU_PELICULAS_H_INCLUDED
#define MENU_PELICULAS_H_INCLUDED

//En este archivo se encuentra el menu, y sus funciones.

bool AltaPelicula();
bool BajaPelicula();
bool ModificarPelicula();
bool ListarPelicula();
bool MostrarTodaPelicula();

void MenuPeliculas() {
    char op;
    bool correrMenu = true;
    while(correrMenu) {
        system("cls");
        cout << endl;
        cout << "          MENU PELICULAS         " << endl;
        cout << "---------------------------------" << endl;
        cout << " A - ALTA DE UNA PELICULA        " << endl;
        cout << " B - BAJA DE UNA PELICULA        " << endl;
        cout << " C - MODIFICAR DESCRIPCION       " << endl;
        cout << " D - LISTAR PELICULA POR ID      " << endl;
        cout << " E - MOSTRAR TODAS LAS PELICULAS " << endl;
        cout << "---------------------------------" << endl;
        cout << " X - VOLVER AL MENU PRINCIPAL    " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        op = toupper(op);
        system("cls");
        switch (op) {
        case 'A':
            AltaPelicula();
            break;
        case 'B':
            BajaPelicula();
            break;
        case 'C':
            ModificarPelicula();
            break;
        case 'D':
            ListarPelicula();
            break;
        case 'E':
            MostrarTodaPelicula();
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


// Agrega un nuevo registro de película al archivo "Peliculas.dat".
bool AltaPelicula() {
    Pelicula temp;
    ArchivoPeliculas archivo("Peliculas.dat");
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

// Realiza la baja de una película por ID, cambiando su estado a inactivo en el archivo "Peliculas.dat".
bool BajaPelicula() {
    int ID;
    Pelicula temp;
    ArchivoPeliculas archivo("Peliculas.dat");

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

// Modifica la descripción de una película por ID en el archivo "Peliculas.dat".
bool ModificarPelicula() {
    int ID;
    Pelicula temp;
    char descripcionTemp[200];
    ArchivoPeliculas archivo("Peliculas.dat");

    cout << "SUS OPCIONES SON: "<<endl;
    archivo.listarRegistros();
    cout << "INGRESAR ID PELICULA (NUMERO ENTERO) CUYA DESCRIPCION MODIFICAR: ";
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
    cout << "INGRESE NUEVA DESCRIPCION" << endl;
    cargarCadena(descripcionTemp, 200);
    while (descripcionTemp[0] == '\0') cargarCadena(descripcionTemp, 200);
    temp = archivo.leerRegistro(pos);
    temp.setDescripcion(descripcionTemp);
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

// Muestra la información de una película por ID desde el archivo "Peliculas.dat".
bool ListarPelicula() {
    int ID;
    Pelicula temp;
    ArchivoPeliculas archivo("Peliculas.dat");
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

// Muestra la lista completa de películas desde el archivo "Peliculas.dat".
bool MostrarTodaPelicula() {
    ArchivoPeliculas archivo("Peliculas.dat");
    archivo.listarRegistros();
    system("pause");
    system("cls");
    return true;
}

#endif // MENU_PELICULAS_H_INCLUDED
