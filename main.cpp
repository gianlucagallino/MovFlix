#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

#include "rlutil.h"
#include "funcion_cargarCadena.h"
#include "funcion_pantallaIntroductoria.h"
#include "funcion_determinarPosicionAutonumerica.h"
#include "clase_Fecha.h"
#include "clase_Genero.h"
#include "clase_Director.h"
#include "clase_Pelicula.h"
#include "clase_Usuario.h"
#include "clase_Resenia.h"
#include "clase_ArchivoGeneros.h"
#include "clase_ArchivoDirectores.h"
#include "clase_ArchivoPeliculas.h"
#include "clase_ArchivoUsuarios.h"
#include "clase_ArchivoResenias.h"
#include "menu_usuarios.h"
#include "menu_peliculas.h"
#include "menu_resenias.h"
#include "menu_generos.h"
#include "menu_directores.h"
#include "Reportes.h"
#include "menu_administracion.h"

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

/* Falta hacer:
 - Mejoras graficas. Lo mejor posible, pero si se rompe, preferible que sea estable.
 - Desarrollar las clases y las funciones
 - Que cumpla con las cosas del tp tambien. por las dudas.
 - Hacer un menu de reportes interesante.
 - usar el system copy para el backup
 - HACER LAS VERIFICACIONES, es super importante que esten bien. que las clases compuestas, sus factores compuestos existan.
 - Comentar TODO el codigo, para que se note la atencion al detalle.
 - Actualizar la documentacion que hicimos para que diga bien lo que armamos.
 - Mostrarle a maxi si esta para un 10. ver que dice.
*/

/* Cosas para tener en cuenta:
 - Las funciones se escriben asi "EstoEsUnaFuncion()" primera letra mayus
 - Las variables, asi "estoEsUnaVariable" primera letra min
 - Los while(true) son mala practica, preferible hacerlo con un booleano.
 - Todo debe tener ABML
*/

int main() {
    bool correrPrograma = true;
    int op;

    PantallaIntroductoria();

    system("cls");
    while(correrPrograma) {
        system("cls");
        cout << endl;
        cout << "         MENU PRINCIPAL         " << endl;
        cout << "--------------------------------" << endl;
        cout << " 1 - ABML GENEROS               " << endl;
        cout << " 2 - ABML DIRECTORES            " << endl;
        cout << " 3 - ABML PELICULAS             " << endl;
        cout << " 4 - ABML USUARIOS              " << endl;
        cout << " 5 - ABML RESENIAS              " << endl;
        cout << " 6 - REPORTES                   " << endl;
        cout << " 7 - BACKUPS Y ADMINISTRACION   " << endl;
        cout << "--------------------------------" << endl;
        cout << " 0 - FIN DEL PROGRAMA " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        system("cls");
        switch (op) {
        case 1:
            MenuGeneros();
            break;
        case 2:
            MenuDirectores();
            break;
        case 3:
            MenuPeliculas();
            break;
        case 4:
            MenuUsuarios();
            break;
        case 5:
            MenuResenias();
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
            rlutil::msleep(2000);
            system("cls");
            break;
        }

    }
    system("cls");
    cout << "MUCHAS GRACIAS, VUELVA PRONTO!"<<endl;
    rlutil::msleep(2000);
    return 0;
}
