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
void RestauracionEntera();

void MenuAdministracion() {
    char op;
    bool correrMenu = true;
    while(correrMenu) {
        system("cls");
        cout << endl;
        cout << "         MENU ADMINISTRACION        " << endl;
        cout << "------------------------------------" << endl;
        cout << " A - BACKUP GENEROS                 " << endl;
        cout << " B - BACKUP DIRECTORES              " << endl;
        cout << " C - BACKUP PELICULAS               " << endl;
        cout << " D - BACKUP USUARIOS                " << endl;
        cout << " E - BACKUP RESENIAS                " << endl;
        cout << " F - RESTAURAR ARCHIVOS GENEROS     " << endl;
        cout << " G - RESTAURAR ARCHIVOS DIRECTORES  " << endl;
        cout << " H - RESTAURAR ARCHIVOS PELICULAS   " << endl;
        cout << " I - RESTAURAR ARCHIVOS USUARIOS    " << endl;
        cout << " J - RESTAURAR ARCHIVOS RESENIAS   " << endl;
        cout << " K - BACKUP ENTERO                 " << endl;
        cout << " L - RESTAURACION ENTERA           " << endl;
        cout << "------------------------------------" << endl;
        cout << "    X - VOLVER AL MENU PRINCIPAL    " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        op=toupper(op); //Funcion de cstdlib, que transforma un input minuscula en mayuscula. Es incluido por conveniencia.
        system("cls");
        switch (op) {
        case 'A':
            BackupGeneros();
            system("pause");
            break;
        case 'B':
            BackupDirectores();
            system("pause");
            break;
        case 'C':
            BackupPeliculas();
            system("pause");
            break;
        case 'D':
            BackupUsuarios();
            system("pause");
            break;
        case 'E':
            BackupResenias();
            system("pause");
            break;
        case 'F':
            RestaurarGeneros();
            system("pause");
            break;
        case 'G':
            RestaurarDirectores();
            system("pause");
            break;
        case 'H':
            RestaurarPeliculas();
            system("pause");
            break;
        case 'I':
            RestaurarUsuarios();
            system("pause");
            break;
        case 'J':
            RestaurarResenias();
            system("pause");
            break;
        case 'K':
            BackupEntero();
            system("pause");
            break;
        case 'L':
            RestauracionEntera();
            system("pause");
            break;
        case 'X':
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
        cout << "BACKUP REALIZADO." << endl;
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
        cout << "BACKUP REALIZADO." << endl;
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
        cout << "BACKUP REALIZADO." << endl;
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
        cout << "BACKUP REALIZADO." << endl;
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
        cout << "BACKUP REALIZADO." << endl;
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
        cout << "BACKUP RESTAURADO." << endl;
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
        cout << "BACKUP RESTAURADO." << endl;
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
        cout << "BACKUP RESTAURADO." << endl;
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
        cout << "BACKUP RESTAURADO." << endl;
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
        cout << "BACKUP RESTAURADO." << endl;
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

// Restaura los archivos desde sus copias de seguridad.
void RestauracionEntera() {
    RestaurarGeneros();
    RestaurarDirectores();
    RestaurarPeliculas();
    RestaurarUsuarios();
    RestaurarResenias();
}
#endif // MENU_ADMINISTRACION_H_INCLUDED
