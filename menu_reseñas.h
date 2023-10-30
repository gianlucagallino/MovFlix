#ifndef MENU_RESEnaS_H_INCLUDED
#define MENU_RESEnaS_H_INCLUDED

void menureseñas(){
int op;
    system("cls");
    while(true) {
        cout << "                     " << endl;
        cout << "    MENU RESEÑAS   " << endl;
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

#endif // MENU_RESEñAS_H_INCLUDED
