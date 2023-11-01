#ifndef CLASE_ARCHIVODIRECTORES_H_INCLUDED
#define CLASE_ARCHIVODIRECTORES_H_INCLUDED

class ArchivoDirectores {
  private:
    char _nombre[30];
  public:
    ArchivoDirectores(const char *nom) {
        strcpy(_nombre,nom);
    }
    const char *getNombre() {
        return _nombre;
    }
    void setNombre(const char *nom) {
        strcpy(_nombre,nom);
    }

    bool listarRegistros() {
        Director reg;
        FILE *p=fopen(_nombre,"rb");
        if (p==NULL) {
            cout<<"ERROR DE ARCHIVO"<<endl;
            system("pause");
            return false;
        }
        fseek(p, 0, 1);
        while(fread(&reg, sizeof reg, 1, p)==1) {
            if (reg.getEstado()==true)reg.Mostrar();
        }
        fclose(p);
        return true;
    }

    bool agregarRegistro(Director reg) {
        FILE *p=fopen(_nombre,"ab");
        if (p==NULL) {
            cout<<"ERROR DE ARCHIVO"<<endl;
            system("pause");
            return false;
        }
        bool escribio=fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    /*
    int buscarRegistro(int a) {
        Genero reg;
        int cont=0;
        FILE *p=fopen(_nombre,"ab+"); //para que funcione si es el prim.
        if (p==NULL) {
            cout<<"ERROR DE ARCHIVO"<<endl;

            system("pause");
            return -2;
        }
        while(fread(&reg, sizeof reg, 1, p)==1) {
            if(reg.getDNI()==a&&reg.getEstado()!=false) {
                fclose(p);
                return cont;
            }
            cont++;
        }
        fclose(p);
        return -1;
    }
    */ //BORRAR

    bool modificarRegistro(int pos, Director  reg) {
        FILE *p=fopen(_nombre,"rb+");
        if (p==NULL) {
            cout<<"ERROR DE ARCHIVO"<<endl;
            system("pause");
            return false;
        }
        fseek(p,sizeof(Director )*pos, 0);
        bool esc=fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return esc;
    }

    Director leerRegistro(int pos) {
        Director reg;
        reg.setEstado(false);
        FILE *p=fopen(_nombre,"rb");
        if (p==NULL) {
            cout<<"ERROR DE ARCHIVO"<<endl;
            system("pause");
            return reg;
        }
        fseek(p,sizeof(Director)*pos, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }

    int contarRegistros() {
        FILE *p=fopen(_nombre,"ab+");
        if (p==NULL) {
            cout<<"ERROR DE ARCHIVO"<<endl;
            return -2;
        }
        fseek(p,0,2);
        int cantByte=ftell(p);//devuelve la cant de bytes de principio al puntero, osea el fin
        fclose(p);
        return (cantByte / sizeof(Director));
    }
};

#endif // CLASE_ARCHIVODIRECTORES_H_INCLUDED
