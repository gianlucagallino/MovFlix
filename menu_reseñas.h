#ifndef MENU_RESEnaS_H_INCLUDED
#define MENU_RESEnaS_H_INCLUDED

void menurese�as(){
int op;
    system("cls");
    while(true) {
        cout << "                     " << endl;
        cout << "    MENU RESE�AS   " << endl;
        cout << "---------------------" << endl;
        cout << " 1 -         " << endl;
        cout << " 2 -        " << endl;
        cout << " 3 -       " << endl;
        cout << "---------------------" << endl;
        cout << " 0 - FIN DEL PROGRAMA " << endl;
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
            return;
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

#endif // MENU_RESE�AS_H_INCLUDED
