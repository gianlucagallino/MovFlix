#ifndef MENU_ADMINISTRACION_H_INCLUDED
#define MENU_ADMINISTRACION_H_INCLUDED

void MenuAdministracion() {
    int op;
    bool correrMenu = true;
    system("cls");
    while(correrMenu) {
        cout << endl;
        cout << "       MENU ADMINISTRACION       " << endl;
        cout << "---------------------------------" << endl;
        cout << " 1 -                             " << endl;
        cout << " 2 -                             " << endl;
        cout << " 3 -                             " << endl;
        cout << " 4 -                             " << endl;
        cout << " 5 - TODOS LOS REPORTES!         " << endl;
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

#endif // MENU_ADMINISTRACION_H_INCLUDED
