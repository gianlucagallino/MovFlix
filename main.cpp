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
#include "clase_ArchivoGeneros.h"
#include "funcion_Verificarexistencia_genero.h"
#include "clase_Director.h"
#include "clase_ArchivoDirectores.h"
#include "funcion_verificarexistencia_director.h"
#include "clase_Pelicula.h"
#include "clase_ArchivoPeliculas.h"
#include "funcion_encontrarPelicula.h"
#include "clase_Usuario.h"
#include "clase_ArchivoUsuarios.h"
#include "funcion_encontrarUsuario.h"
#include "clase_Resenia.h"
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
  -GALLIANO, GIANLUCA (Virtual)
  -PARRA, Juan (PRESENCIAL)
*/

/// QUEDA PARA HACER:
/*
 - Hacer un menu de reportes interesante, con cosas copadas. aprovechemos que tenemos tantos archivos.
 - HACER LAS VERIFICACIONES, no hay casi nada hecho. es importante que esten bien. que las clases compuestas, sus factores compuestos existan. TODO, minucioso, en detalle.
 - Incorporar temas cuatrimestre 2!! Importante, asi mostramos que sabemos eso.
 - Comentar TODO el codigo, para que se note la atencion al detalle, y sea mas facil de interpretar / estudiar.
 - Actualizar la documentacion que hicimos en google docs, para que diga bien lo que armamos, porque cambió bastante.
 - Mejoras graficas. Lo mejor posible, pero si se rompe, preferible que sea estable. usen rlutil. (acordarse de poner el fondo en negro, pq el de kloster es blanco si no)
*/

/// COMENTARIO JUAN: SI PARA LO DE IDENTIFICAR EL ID DEL JUGADOR NO PODES CON LO DE LA CARGA DE OPERADORES, SE ME OCURRIÓ QUE GUARDARA EL ID EN UNA VARIABLE
/// Y DESPUES SE LA PASE A UNA FUNCION DENTRO DE UN .H NUEVO DONDE RECORRA EL ARCHIVO DE USUARIOS Y CUANDO CONSIGUE UN MISMO ID, QUE LO MUESTRE.

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
            MenuReportes();
            break;
        case 7:
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
