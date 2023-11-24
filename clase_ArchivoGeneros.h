#ifndef CLASE_ARCHIVOGENEROS_H_INCLUDED
#define CLASE_ARCHIVOGENEROS_H_INCLUDED

#include "clase_Genero.h"

class ArchivoGeneros {
  private:
    char _nombre[30]; // Nombre del archivo de g�neros
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

    // Lista los registros de g�neros activos en el archivo
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
                reg.Mostrar(); // Muestra el registro del g�nero
            cout << endl;
            cont++;
        }
        if (cont == 0) {
            cout<<"NO HAY REGISTROS EN EL ARCHIVO"<<endl;
        }
        fclose(p);
        return true;
    }

    // Agrega un nuevo registro de g�nero al archivo
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

    // Busca un registro de g�nero por su ID
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
                return cont; // Devuelve la posici�n del registro encontrado
            }
            cont++;
        }
        fclose(p);
        return -1; // Registro no encontrado
    }

    // Modifica un registro de g�nero en una posici�n dada
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
        return esc; // Devuelve true si la modificaci�n se realiz� con �xito
    }

    // Lee un registro de g�nero en una posici�n dada
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

    // Cuenta la cantidad de registros en el archivo de g�neros
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
