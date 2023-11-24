#ifndef FUNCION_DETERMINARPOSICIONAUTONUMERICA_H_INCLUDED
#define FUNCION_DETERMINARPOSICIONAUTONUMERICA_H_INCLUDED

int DeterminarPosicionAutonumerica(const char *archivo, int tamanioRegistro) {
    // Abrimos el archivo en modo "append binario más" para crearlo si no existe.
    FILE *p = fopen(archivo, "ab+");
    if (p == NULL) {
        cout << "ERROR DE ARCHIVO" << endl;
        system("pause");
        return -1;  // Se produce un error si no se puede abrir el archivo.
    }

    // Colocamos el puntero al final del archivo para obtener la cantidad de bytes.
    fseek(p, 0, 2);
    int cantByte = ftell(p);  // Obtenemos la posición actual del puntero.

    fclose(p);  // Cerramos el archivo.

    // Calculamos la próxima posición autonumérica dividiendo los bytes por el tamaño de registro y sumando 1.
    return (cantByte / tamanioRegistro) + 1;
}

#endif // FUNCION_DETERMINARPOSICIONAUTONUMERICA_H_INCLUDED
