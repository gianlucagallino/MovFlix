#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#include "rlutil.h"
#include "funcion_pantallaIntroductoria.h"
#include "menu_usuarios.h"
#include "menu_peliculas.h"
#include "menu_resenias.h"

/* Falta hacer:
 - Mejoras graficas. Lo mejor posible, pero si se rompe, preferible que sea estable.
 - Desarrollar las clases y las funciones
 - HACER LAS VERIFICACIONES, es super importante que esten bien.
 - Comentar TODO el codigo, para que se note la atencion al detalle.
 - Actualizar la documentacion que hicimos para que diga bien lo que armamos.
 - Mostrarle a maxi si esta para un 10. ver que dice.
*/

/* Cosas para tener en cuenta:
 - Las funciones se escriben asi "EstoEsUnaFuncion()" primera letra mayus
 - Las variables, asi "estoEsUnaVariable" primera letra min
 - Los while(true) son mala practica, preferible hacerlo con un booleano.
*/

int main() {
    bool correrPrograma = true;
    int op;

    PantallaIntroductoria();

    system("cls");
    while(correrPrograma) {
        cout << endl;
        cout << "         MENU PRINCIPAL         " << endl;
        cout << "--------------------------------" << endl;
        cout << " 1 - USUARIOS                   " << endl;
        cout << " 2 - PELICULAS                  " << endl;
        cout << " 3 - RESENIAS                   " << endl;
        cout << " 4 - GENEROS PELICULA           " << endl;
        cout << " 5 - AUTORES                    " << endl;
        cout << " 6 - REPORTES                   " << endl;
        cout << " 7 - BACKUPS Y ADMINISTRACION   " << endl;
        cout << "--------------------------------" << endl;
        cout << " 0 - FIN DEL PROGRAMA " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        system("cls");
        switch (op) {
        case 1:
            MenuUsuarios();
            break;
        case 2:
            MenuPeliculas();
            break;
        case 3:
            MenuResenias();
            break;
        case 4:
            MenuGeneros();
            break;
        case 5:
            MenuAutores();
            break;
        case 6:
            //El nombre del archivo DEBE SER "Reportes.h"
            MenuReportes();
            break;
        case 7:
             //un full wipe, un establecer todo, un backup individual, un reset individual, un recover individual, un wipe individual
            MenuAdministracion();
            break;
        case 0:
            correrPrograma = false;
            break;
        default:
            cout << "POR FAVOR, INGRESAR UNA OPCION CORRECTA" << endl;
            system("pause");
            system("cls");
            break;
        }

    }
    system("cls");
    cout << "MUCHAS GRACIAS, VUELVA PRONTO!"<<endl;
    system("pause");
    return 0;
}
