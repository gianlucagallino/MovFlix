#ifndef MENU_USUARIOS_H_INCLUDED
#define MENU_USUARIOS_H_INCLUDED

void menuusuarios() {
    int op;
    bool correrMenu = true;
    system("cls");
    while(correrMenu) {
        cout << "                     " << endl;
        cout << "         MENU USUARIOS        " << endl;
        cout << "------------------------------" << endl;
        cout << " 1 - AGREGAR UN USUARIO       " << endl;
        cout << " 2 - BUSCAR 1 USUARIO         " << endl;
        cout << " 3 - MOSTRAR TODOS LOS USUARIOS" << endl;
        cout << "------------------------------" << endl;
        cout << " 0 - VOLVER AL MENU PRINCIPAL " << endl;
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
        case 0:
            correrMenu = false;
            break;
        default:
            cout << "PORFAVOR INGRESAR UNA OPCION CORRECTA" << endl;
            system("pause");
            system("cls");
            break;
        }

    }
    return;
}

#endif // MENU_USUARIOS_H_INCLUDED
