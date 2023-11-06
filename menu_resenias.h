#ifndef MENU_RESENIAS_H_INCLUDED
#define MENU_RESENIAS_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

bool AltaResenia();
bool BajaResenia();
bool ModificarResenia();
bool ListarResenia();
bool MostrarTodaResenia();


void MenuResenias() {
    int op;
    bool correrMenu = true;
    while(correrMenu) {
        system("cls");
        cout << endl;
        cout << "           MENU RESENIAS         " << endl;
        cout << "---------------------------------" << endl;
        cout << " 1 - ALTA DE UNA RESENIA         " << endl;
        cout << " 2 - BAJA DE UNA RESENIA         " << endl;
        cout << " 3 - MODIFICAR TEXTO RESENIA     " << endl;
        cout << " 4 - MOSTRAR RESENIA POR ID      " << endl;
        cout << " 5 - MOSTRAR TODOS LAS RESENIAS  " << endl;
        cout << "---------------------------------" << endl;
        cout << " 0 - VOLVER AL MENU PRINCIPAL    " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        system("cls");
        switch (op) {
        case 1:
            AltaResenia();
            break;
        case 2:
            BajaResenia();
            break;
        case 3:
            ModificarResenia();
            break;
        case 4:
            ListarResenia();
            break;
        case 5:
            MostrarTodaResenia();
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

bool AltaResenia() {
    Resenia temp;
    ArchivoResenias archivo("Resenias.dat");
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
bool BajaResenia() {
    int ID;
    Resenia temp;
    ArchivoResenias archivo("Resenias.dat");
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

bool ModificarResenia() {
    int ID;
    Resenia temp;
    ArchivoResenias archivo("Resenias.dat");
    char textoTemp[200];
    cout<<"INGRESAR ID CUYO TEXTO MODIFICAR: ";
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
    cout << "INGRESE NUEVO TEXTO"<<endl;
    cargarCadena(textoTemp, 200);
    while(textoTemp[0]=='\0') cargarCadena(textoTemp, 200);;
    temp = archivo.leerRegistro(pos);
    temp.setOpinion(textoTemp);
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
bool ListarResenia() {
    int ID;
    Resenia temp;
    ArchivoResenias archivo("Resenias.dat");
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
bool MostrarTodaResenia() {
    ArchivoResenias archivo("Resenias.dat");
    archivo.listarRegistros();
    system("pause");
    system("cls");
    return true;
}

#endif // MENU_RESENIAS_H_INCLUDED
