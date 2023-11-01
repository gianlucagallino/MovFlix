#ifndef CLASE_ARCHIVORESENIAS_H_INCLUDED
#define CLASE_ARCHIVORESENIAS_H_INCLUDED


class ArchivoResenias {
  private:
    char _nombre[30];
  public:
    ArchivoResenias(const char *nom) {
        strcpy(_nombre,nom);
    }
    const char *getNombre() {
        return _nombre;
    }
    void setNombre(const char *nom) {
        strcpy(_nombre,nom);
    }

    bool listarRegistros() {
        Resenia reg;
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

    bool agregarRegistro(Resenia reg) {
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

    int buscarRegistro(int buscado) {
        Resenia reg;
        int cont=0;
        FILE *p=fopen(_nombre,"ab+");
        if (p==NULL) {
            cout<<"ERROR DE ARCHIVO"<<endl;
            system("pause");
            return -2;
        }
        while(fread(&reg, sizeof reg, 1, p)==1) {
            if(reg.getIdResenia()==buscado&&reg.getEstado()!=false) {
                fclose(p);
                return cont;
            }
            cont++;
        }
        fclose(p);
        return -1;
    }

    bool modificarRegistro(int pos, Resenia  reg) {
        FILE *p=fopen(_nombre,"rb+");
        if (p==NULL) {
            cout<<"ERROR DE ARCHIVO"<<endl;
            system("pause");
            return false;
        }
        fseek(p,sizeof(Resenia)*pos, 0);
        bool esc=fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return esc;
    }

    Resenia leerRegistro(int pos) {
        Resenia reg;
        reg.setEstado(false);
        FILE *p=fopen(_nombre,"rb");
        if (p==NULL) {
            cout<<"ERROR DE ARCHIVO"<<endl;
            system("pause");
            return reg;
        }
        fseek(p,sizeof(Resenia)*pos, 0);
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
        return (cantByte / sizeof(Resenia));
    }
};

#endif // CLASE_ARCHIVORESENIAS_H_INCLUDED
