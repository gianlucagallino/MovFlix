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

// Limpia un archivo con el nombre especificado.
// Devuelve true si la operación fue exitosa.
bool LimpiarArchivo(const char *n) {
    FILE *p;
    p = fopen(n, "wb");
    if (p == NULL) {
        return false;
    }
    fclose(p);
    return true;
}

// Realiza una copia de seguridad de los registros en el archivo de géneros.
void BackupGeneros() {
    ArchivoGeneros arc("Generos.dat"), arcBackup("Generos.bkp");
    if (LimpiarArchivo("Generos.bkp")) {
        Genero reg;
        int cantReg = arc.contarRegistros();
        for (int i = 0; i < cantReg; i++) {
            reg = arc.leerRegistro(i);
            arcBackup.agregarRegistro(reg);
        }
    }
}

// Realiza una copia de seguridad de los registros en el archivo de directores.
void BackupDirectores() {
    ArchivoDirectores arc("Directores.dat"), arcBackup("Directores.bkp");
    if (LimpiarArchivo("Directores.bkp")) {
        Director reg;
        int cantReg = arc.contarRegistros();
        for (int i = 0; i < cantReg; i++) {
            reg = arc.leerRegistro(i);
            arcBackup.agregarRegistro(reg);
        }
    }
}

// Realiza una copia de seguridad de los registros en el archivo de películas.
void BackupPeliculas() {
    ArchivoPeliculas arc("Peliculas.dat"), arcBackup("Peliculas.bkp");
    if (LimpiarArchivo("Peliculas.bkp")) {
        Pelicula reg;
        int cantReg = arc.contarRegistros();
        for (int i = 0; i < cantReg; i++) {
            reg = arc.leerRegistro(i);
            arcBackup.agregarRegistro(reg);
        }
    }
}

// Realiza una copia de seguridad de los registros en el archivo de usuarios.
void BackupUsuarios() {
    ArchivoUsuarios arc("Usuarios.dat"), arcBackup("Usuarios.bkp");
    if (LimpiarArchivo("Usuarios.bkp")) {
        Usuario reg;
        int cantReg = arc.contarRegistros();
        for (int i = 0; i < cantReg; i++) {
            reg = arc.leerRegistro(i);
            arcBackup.agregarRegistro(reg);
        }
    }
}

// Realiza una copia de seguridad de los registros en el archivo de reseñas.
void BackupResenias() {
    ArchivoResenias arc("Resenias.dat"), arcBackup("Resenias.bkp");
    if (LimpiarArchivo("Resenias.bkp")) {
        Resenia reg;
        int cantReg = arc.contarRegistros();
        for (int i = 0; i < cantReg; i++) {
            reg = arc.leerRegistro(i);
            arcBackup.agregarRegistro(reg);
        }
    }
}

// Restaura los registros de copia de seguridad en el archivo de géneros.
void RestaurarGeneros() {
    ArchivoGeneros arc("Generos.dat"), arcBackup("Generos.bkp");
    if (LimpiarArchivo("Generos.dat")) {
        Genero reg;
        int cantReg = arcBackup.contarRegistros();
        for (int i = 0; i < cantReg; i++) {
            reg = arcBackup.leerRegistro(i);
            arc.agregarRegistro(reg);
        }
    }
}

// Restaura los registros de copia de seguridad en el archivo de directores.
void RestaurarDirectores() {
    ArchivoDirectores arc("Directores.dat"), arcBackup("Directores.bkp");
    if (LimpiarArchivo("Directores.dat")) {
        Director reg;
        int cantReg = arcBackup.contarRegistros();
        for (int i = 0; i < cantReg; i++) {
            reg = arcBackup.leerRegistro(i);
            arc.agregarRegistro(reg);
        }
    }
}

// Restaura los registros de copia de seguridad en el archivo de películas.
void RestaurarPeliculas() {
    ArchivoPeliculas arc("Peliculas.dat"), arcBackup("Peliculas.bkp");
    if (LimpiarArchivo("Peliculas.dat")) {
        Pelicula reg;
        int cantReg = arcBackup.contarRegistros();
        for (int i = 0; i < cantReg; i++) {
            reg = arcBackup.leerRegistro(i);
            arc.agregarRegistro(reg);
        }
    }
}

// Restaura los registros de copia de seguridad en el archivo de usuarios.
void RestaurarUsuarios() {
    ArchivoUsuarios arc("Usuarios.dat"), arcBackup("Usuarios.bkp");
    if (LimpiarArchivo("Usuarios.dat")) {
        Usuario reg;
        int cantReg = arcBackup.contarRegistros();
        for (int i = 0; i < cantReg; i++) {
            reg = arcBackup.leerRegistro(i);
            arc.agregarRegistro(reg);
        }
    }
}

// Restaura los registros de copia de seguridad en el archivo de reseñas.
void RestaurarResenias() {
    ArchivoResenias arc("Resenias.dat"), arcBackup("Resenias.bkp");
    if (LimpiarArchivo("Resenias.dat")) {
        Resenia reg;
        int cantReg = arcBackup.contarRegistros();
        for (int i = 0; i < cantReg; i++) {
            reg = arcBackup.leerRegistro(i);
            arc.agregarRegistro(reg);
        }
    }
}

// Realiza una copia de seguridad de todos los archivos.
void BackupEntero() {
    BackupGeneros();
    BackupDirectores();
    BackupPeliculas();
    BackupUsuarios();
    BackupResenias();
}

// Establece los datos de inicio restaurando los archivos desde sus copias de seguridad.
void EstablecerDatosDeInicio() {
    RestaurarGeneros();
    RestaurarDirectores();
    RestaurarPeliculas();
    RestaurarUsuarios();
    RestaurarResenias();
}
#endif // MENU_ADMINISTRACION_H_INCLUDED
