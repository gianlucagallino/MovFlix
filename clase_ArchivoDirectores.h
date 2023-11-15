#ifndef CLASE_ARCHIVODIRECTORES_H_INCLUDED
#define CLASE_ARCHIVODIRECTORES_H_INCLUDED

#include "clase_Director.h"
class ArchivoDirectores {
  private:
    char _nombre[30]; // Nombre del archivo de directores
  public:
    // Constructor que recibe el nombre del archivo
    ArchivoDirectores(const char *nom) {
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

    // Lista los registros de directores activos en el archivo
    bool listarRegistros() {
        Director reg; // Objeto de la clase Director
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
                reg.Mostrar(); // Muestra el registro del director
            cout << endl;
            cont++;
        }
        if (cont == 0) {
            cout<<"NO HAY REGISTROS EN EL ARCHIVO"<<endl;
        }
        fclose(p);
        return true;
    }

    // Agrega un nuevo registro de director al archivo
    bool agregarRegistro(Director reg) {
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

    // Busca un registro de director por su ID
    int buscarRegistro(int buscado) {
        Director reg;
        int cont = 0;
        FILE *p = fopen(_nombre, "ab+");
        if (p == NULL) {
            cout << "ERROR DE ARCHIVO" << endl;
            system("pause");
            return -2;
        }
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            if (reg.getIdDirector() == buscado && reg.getEstado() != false) {
                fclose(p);
                return cont; // Devuelve la posición del registro encontrado
            }
            cont++;
        }
        fclose(p);
        return -1; // Registro no encontrado
    }

    // Modifica un registro de director en una posición dada
    bool modificarRegistro(int pos, Director reg) {
        FILE *p = fopen(_nombre, "rb+");
        if (p == NULL) {
            cout << "ERROR DE ARCHIVO" << endl;
            system("pause");
            return false;
        }
        fseek(p, sizeof(Director) * pos, 0);
        bool esc = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return esc; // Devuelve true si la modificación se realizó con éxito
    }

    // Lee un registro de director en una posición dada
    Director leerRegistro(int pos) {
        Director reg;
        reg.setEstado(false);
        FILE *p = fopen(_nombre, "rb");
        if (p == NULL) {
            cout << "ERROR DE ARCHIVO" << endl;
            system("pause");
            return reg;
        }
        fseek(p, sizeof(Director) * pos, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }

    // Cuenta la cantidad de registros en el archivo de directores
    int contarRegistros() {
        FILE *p = fopen(_nombre, "ab+");
        if (p == NULL) {
            cout << "ERROR DE ARCHIVO" << endl;
            return -2;
        }
        fseek(p, 0, 2);
        int cantByte = ftell(p); // Devuelve la cantidad de bytes en el archivo
        fclose(p);
        return (cantByte / sizeof(Director)); // Calcula la cantidad de registros
    }
};

#endif // CLASE_ARCHIVODIRECTORES_H_INCLUDED
