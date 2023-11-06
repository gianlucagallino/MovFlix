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
    int op;
    bool correrMenu = true;
    while(correrMenu) {
        system("cls");
        cout << endl;
        cout << "          MENU DIRECTORES        " << endl;
        cout << "---------------------------------" << endl;
        cout << " 1 - ALTA DE UN DIRECTOR         " << endl;
        cout << " 2 - BAJA DE UN DIRECTOR         " << endl;
        cout << " 3 - MODIFICAR NOMBRE DIRECTOR   " << endl;
        cout << " 4 - MOSTRAR DIRECTOR POR ID     " << endl;
        cout << " 5 - MOSTRAR TODOS LOS DIRECTORES" << endl;
        cout << "---------------------------------" << endl;
        cout << " 0 - VOLVER AL MENU PRINCIPAL    " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        system("cls");
        switch (op) {
        case 1:
            AltaDirector();
            break;
        case 2:
            BajaDirector();
            break;
        case 3:
            ModificarDirector();
            break;
        case 4:
            ListarDirector();
            break;
        case 5:
            MostrarTodoDirector();
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

bool AltaDirector() {
    Director temp;
    ArchivoDirectores archivo("Directores.dat");
    temp.Cargar();
    if(archivo.agregarRegistro(temp)) {
        cout << "REGISTRO AGREGADO" << endl;
        system("pause");
        return true;
    } else {
        cout << "NO SE AGREGO" <<endl;
        system("pause");
        return false;
    }
}
bool BajaDirector() {
    int ID;
    Director temp;
    ArchivoDirectores archivo("Directores.dat");
    cout<<"INGRESAR ID A BORRAR: ";
    cin>>ID;
    system("cls");
    int pos = archivo.buscarRegistro(ID);
    if (pos == -1) {
        cout << "NO EXISTE"<< endl;
        system("pause");
        system("cls");
        return false;
    } else if (pos == -2) {
        return false;
    }
    temp = archivo.leerRegistro(pos);
    temp.setEstado(false);
    bool existe = archivo.modificarRegistro(pos, temp);
    if(existe==false) {
        cout<<"PROBLEMA AL ESCRIBIR"<<endl;
        system("pause");
        return false;
    } else {
        cout<<"Dado de baja."<<endl;
        system("pause");
    }
    return true;
}

bool ModificarDirector() {
    int ID;
    Director temp;
    ArchivoDirectores archivo("Directores.dat");
    char nombreTemp[30];
    cout<<"INGRESAR ID CUYO NOMBRE MODIFICAR: ";
    cin>>ID;
    system("cls");
    int pos = archivo.buscarRegistro(ID);
    if (pos == -1) {
        cout << "NO EXISTE"<< endl;
        system("pause");
        system("cls");
        return false;
    } else if (pos == -2) {
        return false;
    }
    cout << "INGRESE NUEVO NOMBRE"<<endl;
    cargarCadena(nombreTemp, 30);
    while(nombreTemp[0]=='\0') cargarCadena(nombreTemp, 30);;
    temp = archivo.leerRegistro(pos);
    temp.setNombreDirector(nombreTemp);
    bool existe = archivo.modificarRegistro(pos, temp);
    if(existe==false) {
        cout<<"PROBLEMA AL ESCRIBIR"<<endl;
        system("pause");
        return false;
    } else {
        cout<<"MODIFICADO!"<<endl;
        system("pause");
    }
    return true;
}
bool ListarDirector() {
    int ID;
    Director temp;
    ArchivoDirectores archivo("Directores.dat");
    cout<<"INGRESAR ID A BUSCAR ";
    cin>>ID;
    int pos = archivo.buscarRegistro(ID);
    if (pos == -1) {
        cout << "NO EXISTE"<< endl;
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
bool MostrarTodoDirector() {
    ArchivoDirectores archivo("Directores.dat");
    archivo.listarRegistros();
    system("pause");
    system("cls");
    return true;
}


#endif // MENU_DIRECTORES_H_INCLUDED
