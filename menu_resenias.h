#ifndef MENU_RESENIAS_H_INCLUDED
#define MENU_RESENIAS_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

void MenuResenias() {
    int op;
    bool correrMenu = true;
    system("cls");
    while(correrMenu) {
        cout << endl;
        cout << "           MENU RESENIAS         " << endl;
        cout << "---------------------------------" << endl;
        cout << " 1 - ALTA DE UNA RESENIA         " << endl;
        cout << " 2 - BAJA DE UNA RESENIA         " << endl;
        cout << " 3 - MODIFICAR RESENIA           " << endl;
        cout << " 4 - BUSCAR UNA RESENIA          " << endl;
        cout << " 5 - MOSTRAR TODOS LAS RESENIAS  " << endl;
        cout << "---------------------------------" << endl;
        cout << " 0 - VOLVER AL MENU PRINCIPAL    " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        system("cls");
        switch (op) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

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

#endif // MENU_RESENIAS_H_INCLUDED
