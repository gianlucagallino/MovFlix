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
#include "funcion_VerificarExistenciaGenero.h"
#include "funcion_VerificarExistenciaUsuario.h"
#include "clase_Director.h"
#include "clase_ArchivoDirectores.h"
#include "funcion_VerificarExistenciaDirector.h"
#include "clase_Pelicula.h"
#include "clase_ArchivoPeliculas.h"
#include "funcion_VerificarExistenciaPelicula.h"
#include "clase_Usuario.h"
#include "clase_ArchivoUsuarios.h"
#include "funcion_VerificarExistenciaReseniaDePelicula.h"
#include "clase_Resenia.h"
#include "clase_ArchivoResenias.h"
#include "menu_usuarios.h"
#include "menu_peliculas.h"
#include "menu_resenias.h"
#include "menu_generos.h"
#include "menu_directores.h"
#include "Reportes.h"
#include "menu_administracion.h"
#include "funcion_MostrarEquivalencias.h"

int main() {
    bool correrPrograma = true;
    char op;

    // Seteamos el color de fondo, para sobreescribir colores de consola del usuario.
    rlutil::setBackgroundColor(rlutil::RED);

    // Función para mostrar la pantalla introductoria
    PantallaIntroductoria();

    system("cls");
    while(correrPrograma) {
        system("cls");
        cout << endl;
        cout << "         MENU PRINCIPAL         " << endl;
        cout << "--------------------------------" << endl;
        cout << " A - ABML GENEROS               " << endl;
        cout << " B - ABML DIRECTORES            " << endl;
        cout << " C - ABML PELICULAS             " << endl;
        cout << " D - ABML USUARIOS              " << endl;
        cout << " E - ABML RESENIAS              " << endl;
        cout << " F - REPORTES                   " << endl;
        cout << " G - BACKUPS Y ADMINISTRACION   " << endl;
        cout << "--------------------------------" << endl;
        cout << " X - FIN DEL PROGRAMA " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        op = toupper(op);
        system("cls");
        switch (op) {
        case 'A':
            MenuGeneros();
            break;
        case 'B':
            MenuDirectores();
            break;
        case 'C':
            MenuPeliculas();
            break;
        case 'D':
            MenuUsuarios();
            break;
        case 'E':
            MenuResenias();
            break;
        case 'F':
            MenuReportes();
            break;
        case 'G':
            MenuAdministracion();
            break;
        case 'X':
            correrPrograma = false;
            break;
        default:
            gotoxy(10,10);
            rlutil::anykey("POR FAVOR, INGRESAR UNA OPCION CORRECTA (PRESIONE BOTON PARA CONTINUAR)");
            system("cls");
            break;
        }

    }
    system("cls");
    gotoxy(10,10);
    cout << "MUCHAS GRACIAS, VUELVA PRONTO!"<<endl;
    rlutil::msleep(2000);
    return 0;
}
