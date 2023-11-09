#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

void reseniaMejorPuntaje();
void peliculaMejorPuntaje();

void MenuReportes() {
    int op;
    bool correrMenu = true;
    system("cls");
    while(correrMenu) {
        cout << endl;
        cout << "                    MENU REPORTES                  " << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " 1 - MOSTRAR RESE�A DE MAYOR PUNTAJE               " << endl;
        cout << " 2 - MOSTRAR PELICULA CON MAYOR PROMEDIO PUNTAJES  " << endl;
        cout << " 3 -                                               " << endl;
        cout << " 4 -                                               " << endl;
        cout << " 5 - TODOS LOS REPORTES!                           " << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " 0 - VOLVER AL MENU PRINCIPAL                      " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        system("cls");
        switch (op) {
        case 1:
            reseniaMejorPuntaje();
            break;
        case 2:
            peliculaMejorPuntaje();
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

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

void cargarVectorRes(Resenia *v) {
    ArchivoResenias archresenia("resenias.dat");  // Abre un archivo de rese�as llamado "resenias.dat"
    Resenia reg;  // Crea un objeto de tipo Resenia
    int pos = 0;  // Inicializa la posici�n en 0
    int cantReg = archresenia.contarRegistros();  // Obtiene la cantidad de registros en el archivo

    // Recorre los registros en el archivo y los guarda en un vector
    for (int i = 0; i < cantReg; i++) {
        reg = archresenia.leerRegistro(i);
        v[pos] = reg;  // Guarda la rese�a en el vector
        pos++;
    }
}

void mostrarMayorRes(Resenia *v, int tamanio) {
    Resenia mejorResenia, rese;  // Crea objetos de tipo Resenia para encontrar la mejor rese�a
    float maxPuntaje = 0;  // Inicializa el puntaje m�ximo en 0

    // Recorre el vector de rese�as
    for (int i = 0; i < tamanio; i++) {
        rese = v[i];
        // Comprueba si la rese�a est� activa y si su puntaje es mayor al puntaje m�ximo
        if (rese.getEstado() && rese > maxPuntaje) {
            maxPuntaje = rese.getPuntuacionResenia();  // Actualiza el puntaje m�ximo
            mejorResenia = rese;  // Guarda la mejor rese�a
        }
    }

    // Muestra la mejor rese�a o un mensaje si no hay rese�as activas con un puntaje v�lido
    if (maxPuntaje == 0) {
        cout << "NO EXISTEN RESE�AS ACTIVAS CON UN PUNTAJE V�LIDO" << endl;
    } else {
        cout << "LA RESE�A CON LA MEJOR PUNTUACI�N ES: " << endl;
        mejorResenia.Mostrar();  // Muestra la mejor rese�a
    }
}

void reseniaMejorPuntaje() {
    ArchivoResenias archresenia("resenias.dat");  // Abre un archivo de rese�as llamado "resenias.dat"

    Resenia *v;  // Crea un puntero a un vector de rese�as
    int cantidadResenias = archresenia.contarRegistros();  // Obtiene la cantidad de rese�as en el archivo

    // Verifica si existen rese�as en el archivo
    if (cantidadResenias == 0) {
        cout << "NO HAY RESE�AS DISPONIBLES" << endl;
        return;
    }

    v = new Resenia[cantidadResenias];  // Reserva memoria para el vector de rese�as

    if (v == nullptr) {
        cout << "ERROR AL RESERVAR MEMORIA PARA EL VECTOR" << endl;
        return;
    }

    cargarVectorRes(v);  // Carga las rese�as en el vector
    mostrarMayorRes(v, cantidadResenias);  // Encuentra y muestra la mejor rese�a
    delete[] v;  // Libera la memoria del vector
}

void cargarVectorPel(Pelicula *v) {
    ArchivoPeliculas arch("peliculas.dat");  // Abre un archivo de pel�culas llamado "peliculas.dat"
    Pelicula reg;  // Crea un objeto de tipo Pelicula
    int pos = 0;  // Inicializa la posici�n en 0
    int cantReg = arch.contarRegistros();  // Obtiene la cantidad de registros en el archivo

    // Recorre los registros en el archivo y los guarda en un vector
    for (int i = 0; i < cantReg; i++) {
        reg = arch.leerRegistro(i);
        v[pos] = reg;  // Guarda la pel�cula en el vector
        pos++;
    }
}

float PromediarResenias(Pelicula input) {
    ArchivoResenias arch("resenias.dat");  // Abre un archivo de rese�as llamado "resenias.dat"
    Resenia reg;  // Crea un objeto de tipo Resenia
    int cantReg;
    float prom = 0;
    int cant = 0;

    cantReg = arch.contarRegistros();  // Obtiene la cantidad de rese�as en el archivo

    // Recorre las rese�as en el archivo y calcula el promedio de puntajes para la pel�cula dada
    for (int i = 0; i < cantReg; i++) {
        reg = arch.leerRegistro(i);
        if (strcmp(reg.getPeliculaResenia().getNombrePelicula(), input.getNombrePelicula()) == 0) {
            prom += reg.getPuntuacionResenia();
            cant++;
        }
    }

    return prom / cant;  // Devuelve el promedio de puntajes
}

void mostrarMayorPel(Pelicula *v, int tamanio) {
    Pelicula mayorpel, reg;  // Crea objetos de tipo Pelicula para encontrar la pel�cula con el mejor promedio de rese�as
    float maxPuntaje = 0;  // Inicializa el promedio m�ximo en 0

    // Recorre el vector de pel�culas
    for (int i = 0; i < tamanio; i++) {
        reg = v[i];
        float prom = PromediarResenias(reg);  // Calcula el promedio de rese�as para la pel�cula actual

        // Comprueba si el promedio es mayor al promedio m�ximo
        if (prom > maxPuntaje) {
            mayorpel = reg;  // Actualiza la pel�cula con el mejor promedio
            maxPuntaje = prom;  // Actualiza el promedio m�ximo
        }
    }

    mayorpel.Mostrar();  // Muestra la pel�cula con el mejor promedio de rese�as
}

void peliculaMejorPuntaje() {
    ArchivoPeliculas arch("peliculas.dat");  // Abre un archivo de pel�culas llamado "peliculas.dat"

    Pelicula *v;  // Crea un puntero a un vector de pel�culas
    int cantidadRegistros = arch.contarRegistros();  // Obtiene la cantidad de pel�culas en el archivo

    // Verifica si existen pel�culas en el archivo
    if (cantidadRegistros == 0) {
        cout << "NO HAY PEL�CULAS DISPONIBLES" << endl;
        return;
    }

    v = new Pelicula[cantidadRegistros];  // Reserva memoria para el vector de pel�culas

    if (v == nullptr) {
        cout << "ERROR AL RESERVAR MEMORIA PARA EL VECTOR" << endl;
        return;
    }

    cargarVectorPel(v);  // Carga las pel�culas en el vector
    mostrarMayorPel(v, cantidadRegistros);  // Encuentra y muestra la pel�cula con el mejor promedio de rese�as
    delete[] v;  // Libera la memoria del vector
}

#endif // REPORTES_H_INCLUDED
