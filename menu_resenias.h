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
    char op;
    bool correrMenu = true;
    while(correrMenu) {
        system("cls");
        cout << endl;
        cout << "           MENU RESENIAS         " << endl;
        cout << "---------------------------------" << endl;
        cout << " A - ALTA DE UNA RESENIA         " << endl;
        cout << " B - BAJA DE UNA RESENIA         " << endl;
        cout << " C - MODIFICAR TEXTO RESENIA     " << endl;
        cout << " D - MOSTRAR RESENIA POR ID      " << endl;
        cout << " E - MOSTRAR TODOS LAS RESENIAS  " << endl;
        cout << "---------------------------------" << endl;
        cout << " X - VOLVER AL MENU PRINCIPAL    " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        op=toupper(op); //Funcion de cstdlib, que transforma un input minuscula en mayuscula. Es incluido por conveniencia.
        system("cls");
        switch (op) {
        case 'A':
            AltaResenia();
            break;
        case 'B':
            BajaResenia();
            break;
        case 'C':
            ModificarResenia();
            break;
        case 'D':
            ListarResenia();
            break;
        case 'E':
            MostrarTodaResenia();
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

// Agrega un nuevo registro de reseña al archivo "Resenias.dat".
bool AltaResenia() {
    Resenia temp;
    ArchivoResenias archivo("Resenias.dat");
    if(temp.Cargar()) {
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
    return false;
}

// Realiza la baja de una reseña por ID, cambiando su estado a inactivo en el archivo "Resenias.dat".
bool BajaResenia() {
    int ID;
    Resenia temp;
    ArchivoResenias archivo("Resenias.dat");

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

// Modifica el texto de una reseña por ID en el archivo "Resenias.dat".
bool ModificarResenia() {
    int ID;
    Resenia temp;
    ArchivoResenias archivo("Resenias.dat");
    char textoTemp[200];

    cout << "SUS OPCIONES SON: "<<endl;
    archivo.listarRegistros();
    cout << "INGRESAR ID RESENIA CUYO TEXTO MODIFICAR: ";
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
    cout << "INGRESE NUEVO TEXTO" << endl;
    cargarCadena(textoTemp, 200);
    while (textoTemp[0] == '\0') cargarCadena(textoTemp, 200);
    temp = archivo.leerRegistro(pos);
    temp.setOpinion(textoTemp);
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

// Muestra la información de una reseña por ID desde el archivo "Resenias.dat".
bool ListarResenia() {
    int ID;
    Resenia temp;
    ArchivoResenias archivo("Resenias.dat");
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

// Muestra la lista completa de reseñas desde el archivo "Resenias.dat".
bool MostrarTodaResenia() {
    ArchivoResenias archivo("Resenias.dat");
    archivo.listarRegistros();
    system("pause");
    system("cls");
    return true;
}

#endif // MENU_RESENIAS_H_INCLUDED
