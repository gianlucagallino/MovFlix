#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#include "menu_usuarios.h"
#include "menu_peliculas.h"
#include "menu_resenias.h"

int main()
{
    int op;
    system("cls");
    while(true) {
        cout << "                     " << endl;
        cout << "    MENU PRINCIPAL   " << endl;
        cout << "---------------------" << endl;
        cout << " 1 - USUARIOS        " << endl;
        cout << " 2 - PELICULAS       " << endl;
        cout << " 3 - RESE�AS         " << endl;
        cout << "---------------------" << endl;
        cout << " 0 - FIN DEL PROGRAMA " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        system("cls");
        switch (op) {
        case 1:
            menuusuarios();
            break;
        case 2:
            menupeliculas();
            break;
        case 3:
            menuresenias();
            break;
        case 0:
            return 0;
            break;
        default:
            cout << "PORFAVOR INGRESAR UNA OPCION CORRECTA" << endl;
            system("pause");
            system("cls");
            break;
        }

    }
    return 0;
}
