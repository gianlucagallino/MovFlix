#ifndef CLASE_ARCHIVOPELICULAS_H_INCLUDED
#define CLASE_ARCHIVOPELICULAS_H_INCLUDED

#include "clase_Pelicula.h"

class ArchivoPeliculas {
  private:
    char _nombre[30]; // Nombre del archivo de pel�culas
  public:
    // Constructor que recibe el nombre del archivo
    ArchivoPeliculas(const char *nom) {
        strcpy(_nombre, nom);
    }

    // Obtiene el nombre del archivo
    const char *getNombre() {
        return _nombre;
    }

    // Establece el nombre del archivo
    void setNombre(const char *nom) {
        strcpy(_nombre, nom);
    }

    // Lista los registros de pel�culas activas en el archivo
    bool listarRegistros() {
        Pelicula reg; // Objeto de la clase Pelicula
        int cont = 0;
        FILE *p = fopen(_nombre, "rb");
        if (p == NULL) {
            cout << "ERROR DE ARCHIVO" << endl;
            system("pause");
            return false;
        }
        fseek(p, 0, 1);
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            if (reg.getEstado() == true)
                reg.Mostrar(); // Muestra el registro de la pel�cula
            cout << endl;
            cont++;
        }
        if (cont == 0) {
            cout<<"NO HAY REGISTROS EN EL ARCHIVO"<<endl;
        }
        fclose(p);
        return true;
    }

    // Agrega un nuevo registro de pel�cula al archivo
    bool agregarRegistro(Pelicula reg) {
        FILE *p = fopen(_nombre, "ab");
        if (p == NULL) {
            cout << "ERROR DE ARCHIVO" << endl;
            system("pause");
            return false;
        }
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }

    // Busca un registro de pel�cula por su ID
    int buscarRegistro(int buscado) {
        Pelicula reg;
        int cont = 0;
        FILE *p = fopen(_nombre, "ab+");
        if (p == NULL) {
            cout << "ERROR DE ARCHIVO" << endl;
            system("pause");
            return -2;
        }
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            if (reg.getIdPelicula() == buscado && reg.getEstado() != false) {
                fclose(p);
                return cont; // Devuelve la posici�n del registro encontrado
            }
            cont++;
        }
        fclose(p);
        return -1; // Registro no encontrado
    }

    // Modifica un registro de pel�cula en una posici�n dada
    bool modificarRegistro(int pos, Pelicula reg) {
        FILE *p = fopen(_nombre, "rb+");
        if (p == NULL) {
            cout << "ERROR DE ARCHIVO" << endl;
            system("pause");
            return false;
        }
        fseek(p, sizeof(Pelicula) * pos, 0);
        bool esc = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return esc; // Devuelve true si la modificaci�n se realiz� con �xito
    }

    // Lee un registro de pel�cula en una posici�n dada
    Pelicula leerRegistro(int pos) {
        Pelicula reg;
        reg.setEstado(false);
        FILE *p = fopen(_nombre, "rb");
        if (p == NULL) {
            cout << "ERROR DE ARCHIVO" << endl;
            system("pause");
            return reg;
        }
        fseek(p, sizeof(Pelicula) * pos, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }

    // Cuenta la cantidad de registros en el archivo de pel�culas
    int contarRegistros() {
        FILE *p = fopen(_nombre, "ab+");
        if (p == NULL) {
            cout << "ERROR DE ARCHIVO" << endl;
            return -2;
        }
        fseek(p, 0, 2);
        int cantByte = ftell(p); // Devuelve la cantidad de bytes en el archivo
        fclose(p);
        return (cantByte / sizeof(Pelicula)); // Calcula la cantidad de registros
    }
};


#endif // CLASE_ARCHIVOPELICULAS_H_INCLUDED
