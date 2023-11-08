#ifndef MENU_PELICULAS_H_INCLUDED
#define MENU_PELICULAS_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

bool AltaPelicula();
bool BajaPelicula();
bool ModificarPelicula();
bool ListarPelicula();
bool MostrarTodaPelicula();

void MenuPeliculas() {
    int op;
    bool correrMenu = true;
    while(correrMenu) {
        system("cls");
        cout << endl;
        cout << "          MENU PELICULAS         " << endl;
        cout << "---------------------------------" << endl;
        cout << " 1 - ALTA DE UNA PELICULA        " << endl;
        cout << " 2 - BAJA DE UNA PELICULA        " << endl;
        cout << " 3 - MODIFICAR DESCRIPCION       " << endl;
        cout << " 4 - LISTAR PELICULA POR ID      " << endl;
        cout << " 5 - MOSTRAR TODAS LAS PELICULAS " << endl;
        cout << "---------------------------------" << endl;
        cout << " 0 - VOLVER AL MENU PRINCIPAL    " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        system("cls");
        switch (op) {
        case 1:
            AltaPelicula();
            break;
        case 2:
            BajaPelicula();
            break;
        case 3:
            ModificarPelicula();
            break;
        case 4:
            ListarPelicula();
            break;
        case 5:
            MostrarTodaPelicula();
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


// Agrega un nuevo registro de pel�cula al archivo "Peliculas.dat".
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
}

// Realiza la baja de una pel�cula por ID, cambiando su estado a inactivo en el archivo "Peliculas.dat".
bool BajaPelicula() {
    int ID;
    Pelicula temp;
    ArchivoPeliculas archivo("Peliculas.dat");
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

// Modifica la descripci�n de una pel�cula por ID en el archivo "Peliculas.dat".
bool ModificarPelicula() {
    int ID;
    Pelicula temp;
    char descripcionTemp[200];
    ArchivoPeliculas archivo("Peliculas.dat");
    cout << "INGRESAR ID CUYA DESCRIPCION MODIFICAR: ";
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

// Muestra la informaci�n de una pel�cula por ID desde el archivo "Peliculas.dat".
bool ListarPelicula() {
    int ID;
    Pelicula temp;
    ArchivoPeliculas archivo("Peliculas.dat");
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

// Muestra la lista completa de pel�culas desde el archivo "Peliculas.dat".
bool MostrarTodaPelicula() {
    ArchivoPeliculas archivo("Peliculas.dat");
    archivo.listarRegistros();
    system("pause");
    system("cls");
    return true;
}

#endif // MENU_PELICULAS_H_INCLUDED
