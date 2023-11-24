#ifndef CLASE_ARCHIVOGENEROS_H_INCLUDED
#define CLASE_ARCHIVOGENEROS_H_INCLUDED

#include "clase_Genero.h"

class ArchivoGeneros {
  private:
    char _nombre[30]; // Nombre del archivo de géneros
  public:
    // Constructor que recibe el nombre del archivo
    ArchivoGeneros(const char *nom) {
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

    // Lista los registros de géneros activos en el archivo
    bool listarRegistros() {
        Genero reg; // Objeto de la clase Genero
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
                reg.Mostrar(); // Muestra el registro del género
            cout << endl;
            cont++;
        }
        if (cont == 0) {
            cout<<"NO HAY REGISTROS EN EL ARCHIVO"<<endl;
        }
        fclose(p);
        return true;
    }

    // Agrega un nuevo registro de género al archivo
    bool agregarRegistro(Genero reg) {
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

    // Busca un registro de género por su ID
    int buscarRegistro(int buscado) {
        Genero reg;
        int cont = 0;
        FILE *p = fopen(_nombre, "ab+");
        if (p == NULL) {
            cout << "ERROR DE ARCHIVO" << endl;
            system("pause");
            return -2;
        }
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            if (reg.getIdGenero() == buscado && reg.getEstado() != false) {
                fclose(p);
                return cont; // Devuelve la posición del registro encontrado
            }
            cont++;
        }
        fclose(p);
        return -1; // Registro no encontrado
    }

    // Modifica un registro de género en una posición dada
    bool modificarRegistro(int pos, Genero reg) {
        FILE *p = fopen(_nombre, "rb+");
        if (p == NULL) {
            cout << "ERROR DE ARCHIVO" << endl;
            system("pause");
            return false;
        }
        fseek(p, sizeof(Genero) * pos, 0);
        bool esc = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return esc; // Devuelve true si la modificación se realizó con éxito
    }

    // Lee un registro de género en una posición dada
    Genero leerRegistro(int pos) {
        Genero reg;
        reg.setEstado(false);
        FILE *p = fopen(_nombre, "rb");
        if (p == NULL) {
            cout << "ERROR DE ARCHIVO" << endl;
            system("pause");
            return reg;
        }
        fseek(p, sizeof(Genero) * pos, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }

    // Cuenta la cantidad de registros en el archivo de géneros
    int contarRegistros() {
        FILE *p = fopen(_nombre, "ab+");
        if (p == NULL) {
            cout << "ERROR DE ARCHIVO" << endl;
            return -2;
        }
        fseek(p, 0, 2);
        int cantByte = ftell(p); // Devuelve la cantidad de bytes en el archivo
        fclose(p);
        return (cantByte / sizeof(Genero)); // Calcula la cantidad de registros
    }
};

#endif // CLASE_ARCHIVOGENEROS_H_INCLUDED
