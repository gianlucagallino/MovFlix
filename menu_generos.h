#ifndef MENU_GENEROS_H_INCLUDED
#define MENU_GENEROS_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

bool AltaGenero();
bool BajaGenero();
bool ModificarGenero();
bool ListarGenero();
bool MostrarTodoGenero();

void MenuGeneros() {
    int op;
    bool correrMenu = true;
    while(correrMenu) {
        system("cls");
        cout << endl;
        cout << "           MENU GENEROS          " << endl;
        cout << "---------------------------------" << endl;
        cout << " 1 - ALTA DE UN GENERO           " << endl;
        cout << " 2 - BAJA DE UN GENERO           " << endl;
        cout << " 3 - MODIFICAR NOMBRE GENERO     " << endl;
        cout << " 4 - LISTAR GENERO POR ID        " << endl;
        cout << " 5 - MOSTRAR TODOS LOS GENEROS   " << endl;
        cout << "---------------------------------" << endl;
        cout << " 0 - VOLVER AL MENU PRINCIPAL    " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        system("cls");
        switch (op) {
        case 1:
            AltaGenero();
            break;
        case 2:
            BajaGenero();
            break;
        case 3:
            ModificarGenero();
            break;
        case 4:
            ListarGenero();
            break;
        case 5:
            MostrarTodoGenero();
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

bool AltaGenero() {
    Genero temp;
    ArchivoGeneros archivo("Generos.dat");
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
bool BajaGenero() {
    int ID;
    Genero temp;
    ArchivoGeneros archivo("Generos.dat");
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

bool ModificarGenero() {
    int ID;
    Genero temp;
    char nombreTemp[30];
    ArchivoGeneros archivo("Generos.dat");
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
    temp = archivo.leerRegistro(pos);
    temp.setNombreGenero(nombreTemp);
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
bool ListarGenero() {
    int ID;
    Genero temp;
    ArchivoGeneros archivo("Generos.dat");
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
bool MostrarTodoGenero() {
    ArchivoGeneros archivo("Generos.dat");
    archivo.listarRegistros();
    system("pause");
    system("cls");
    return true;
}


#endif // MENU_GENEROS_H_INCLUDED
