#ifndef MENU_ADMINISTRACION_H_INCLUDED
#define MENU_ADMINISTRACION_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

bool LimpiarArchivo(const char *n);
void BackupGeneros();
void BackupDirectores();
void BackupPeliculas();
void BackupUsuarios();
void BackupResenias();
void RestaurarGeneros();
void RestaurarDirectores();
void RestaurarPeliculas();
void RestaurarUsuarios();
void RestaurarResenias();
void BackupEntero();
void EstablecerDatosDeInicio();

void MenuAdministracion() {
    int op;
    bool correrMenu = true;
    while(correrMenu) {
        system("cls");
        cout << endl;
        cout << "         MENU ADMINISTRACION        " << endl;
        cout << "------------------------------------" << endl;
        cout << " 1 - BACKUP GENEROS                 " << endl;
        cout << " 2 - BACKUP DIRECTORES              " << endl;
        cout << " 3 - BACKUP PELICULAS               " << endl;
        cout << " 4 - BACKUP USUARIOS                " << endl;
        cout << " 5 - BACKUP RESENIAS                " << endl;
        cout << " 6 - RESTAURAR ARCHIVOS GENEROS     " << endl;
        cout << " 7 - RESTAURAR ARCHIVOS DIRECTORES  " << endl;
        cout << " 8 - RESTAURAR ARCHIVOS PELICULAS   " << endl;
        cout << " 9 - RESTAURAR ARCHIVOS USUARIOS    " << endl;
        cout << " 10 - RESTAURAR ARCHIVOS RESENIAS   " << endl;
        cout << " 11 - BACKUP ENTERO                 " << endl;
        cout << " 12 - ESTABLECER DATOS DE INICIO    " << endl;
        cout << "------------------------------------" << endl;
        cout << "    0 - VOLVER AL MENU PRINCIPAL    " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        system("cls");
        switch (op) {
        case 1:
            BackupGeneros();
            break;
        case 2:
            BackupDirectores();
            break;
        case 3:
            BackupPeliculas();
            break;
        case 4:
            BackupUsuarios();
            break;
        case 5:
            BackupResenias();
            break;
        case 6:
            RestaurarGeneros();
            break;
        case 7:
            RestaurarDirectores();
            break;
        case 8:
            RestaurarPeliculas();
            break;
        case 9:
            RestaurarUsuarios();
            break;
        case 10:
            RestaurarResenias();
            break;
        case 11:
            BackupEntero();
            break;
        case 12:
            EstablecerDatosDeInicio();
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

bool LimpiarArchivo(const char *n) {
    FILE *p;
    p=fopen(n, "wb");
    if(p==NULL) {
        return false;
    }
    fclose(p);
}

void BackupGeneros() {
    ArchivoGeneros arc("Generos.dat"), arcBackup("Generos.bkp");
    LimpiarArchivo("Generos.bkp");
    Genero reg;
    int cantReg=arc.contarRegistros();
    for(int i=0; i<cantReg; i++) {
        reg=arc.leerRegistro(i);
        arcBackup.agregarRegistro(reg);
    }
}

void BackupDirectores() {
    ArchivoDirectores arc("Directores.dat"), arcBackup("Directores.bkp");
    LimpiarArchivo("Directores.bkp");
    Director reg;
    int cantReg=arc.contarRegistros();
    for(int i=0; i<cantReg; i++) {
        reg=arc.leerRegistro(i);
        arcBackup.agregarRegistro(reg);
    }
}

void BackupPeliculas() {
    ArchivoPeliculas arc("Directores.dat"), arcBackup("Directores.bkp");
    LimpiarArchivo("Directores.bkp");
    Pelicula reg;
    int cantReg=arc.contarRegistros();
    for(int i=0; i<cantReg; i++) {
        reg=arc.leerRegistro(i);
        arcBackup.agregarRegistro(reg);
    }
}

void BackupUsuarios() {
    ArchivoUsuarios arc("Usuarios.dat"), arcBackup("Usuarios.bkp");
    LimpiarArchivo("Usuarios.bkp");
    Usuario reg;
    int cantReg=arc.contarRegistros();
    for(int i=0; i<cantReg; i++) {
        reg=arc.leerRegistro(i);
        arcBackup.agregarRegistro(reg);
    }
}

void BackupResenias() {
    ArchivoResenias arc("Resenias.dat"), arcBackup("Resenias.bkp");
    LimpiarArchivo("Resenias.bkp");
    Resenia reg;
    int cantReg=arc.contarRegistros();
    for(int i=0; i<cantReg; i++) {
        reg=arc.leerRegistro(i);
        arcBackup.agregarRegistro(reg);
    }
}

void RestaurarGeneros() {
    ArchivoGeneros arc("Generos.dat"), arcBackup("Generos.bkp");
    Genero reg;
    LimpiarArchivo("Generos.dat");

    int cantReg=arcBackup.contarRegistros();
    for(int i=0; i<cantReg; i++) {
        reg=arcBackup.leerRegistro(i);
        arc.agregarRegistro(reg);
    }
}

void RestaurarDirectores() {
    ArchivoDirectores arc("Directores.dat"), arcBackup("Directores.bkp");
    Director reg;
    LimpiarArchivo("Directores.dat");

    int cantReg=arcBackup.contarRegistros();
    for(int i=0; i<cantReg; i++) {
        reg=arcBackup.leerRegistro(i);
        arc.agregarRegistro(reg);
    }
}

void RestaurarPeliculas() {
    ArchivoPeliculas arc("Directores.dat"), arcBackup("Directores.bkp");
    Pelicula reg;
    LimpiarArchivo("Directores.dat");

    int cantReg=arcBackup.contarRegistros();
    for(int i=0; i<cantReg; i++) {
        reg=arcBackup.leerRegistro(i);
        arc.agregarRegistro(reg);
    }
}

void RestaurarUsuarios() {
    ArchivoUsuarios arc("Usuarios.dat"), arcBackup("Usuarios.bkp");
    Usuario reg;
    LimpiarArchivo("Usuarios.dat");

    int cantReg=arcBackup.contarRegistros();
    for(int i=0; i<cantReg; i++) {
        reg=arcBackup.leerRegistro(i);
        arc.agregarRegistro(reg);
    }
}

void RestaurarResenias() {
    ArchivoResenias arc("Resenias.dat"), arcBackup("Resenias.bkp");
    Resenia reg;
    LimpiarArchivo("Resenias.dat");

    int cantReg=arcBackup.contarRegistros();
    for(int i=0; i<cantReg; i++) {
        reg=arcBackup.leerRegistro(i);
        arc.agregarRegistro(reg);
    }
}

void BackupEntero() {
    BackupGeneros();
    BackupDirectores();
    BackupPeliculas();
    BackupUsuarios();
    BackupResenias();
}

void EstablecerDatosDeInicio() {

    ArchivoGeneros arc1("Generos.dat"), arcIni1("Generos.bkp");
    Genero reg1;
    LimpiarArchivo("Generos.dat");

    int cantReg1=arcIni1.contarRegistros();
    for(int i=0; i<cantReg1; i++) {
        reg1=arcIni1.leerRegistro(i);
        arc1.agregarRegistro(reg1);
    }

    ArchivoDirectores arc2("Directores.dat"), arcIni2("Directores.ini");
    Director reg2;
    LimpiarArchivo("Directores.dat");
    int cantReg2=arcIni2.contarRegistros();
    for(int i=0; i<cantReg2; i++) {
        reg2=arcIni2.leerRegistro(i);
        arc2.agregarRegistro(reg2);
    }

    ArchivoPeliculas arc3("Peliculas.dat"), arcIni3("Peliculas.ini");
    Pelicula reg3;
    LimpiarArchivo("Peliculas.dat");
    int cantReg3=arcIni3.contarRegistros();
    for(int i=0; i<cantReg3; i++) {
        reg3=arcIni3.leerRegistro(i);
        arc3.agregarRegistro(reg3);
    }

    ArchivoUsuarios arc4("Usuarios.dat"), arcIni4("Usuarios.ini");
    Usuario reg4;
    LimpiarArchivo("Usuarios.dat");
    int cantReg4=arcIni4.contarRegistros();
    for(int i=0; i<cantReg4; i++) {
        reg4=arcIni4.leerRegistro(i);
        arc4.agregarRegistro(reg4);
    }

    ArchivoResenias arc5("Resenias.dat"), arcIni5("Resenias.ini");
    Resenia reg5;
    LimpiarArchivo("Resenias.dat");
    int cantReg5=arcIni5.contarRegistros();
    for(int i=0; i<cantReg5; i++) {
        reg5=arcIni5.leerRegistro(i);
        arc5.agregarRegistro(reg5);
    }
}
#endif // MENU_ADMINISTRACION_H_INCLUDED
