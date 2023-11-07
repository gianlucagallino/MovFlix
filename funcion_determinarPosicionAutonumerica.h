#ifndef FUNCION_DETERMINARPOSICIONAUTONUMERICA_H_INCLUDED
#define FUNCION_DETERMINARPOSICIONAUTONUMERICA_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

int DeterminarPosicionAutonumerica(const char *archivo, int tamanioRegistro) {
    //El AB+ cumple la funcion de generar el archivo, si no existe.
    FILE *p=fopen(archivo,"ab+");
    if (p==NULL) {
        cout<<"ERROR DE ARCHIVO"<<endl;
        system("pause");
        return -1;
    }
    fseek(p,0,2);
    int cantByte=ftell(p);
    fclose(p);
    return (cantByte / tamanioRegistro)+1;
}

#endif // FUNCION_DETERMINARPOSICIONAUTONUMERICA_H_INCLUDED
