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
        cout << " 1 - MOSTRAR RESEÑA DE MAYOR PUNTAJE               " << endl;
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
    ArchivoResenias archresenia("resenias.dat");  // Abre un archivo de reseñas llamado "resenias.dat"
    Resenia reg;  // Crea un objeto de tipo Resenia
    int pos = 0;  // Inicializa la posición en 0
    int cantReg = archresenia.contarRegistros();  // Obtiene la cantidad de registros en el archivo

    // Recorre los registros en el archivo y los guarda en un vector
    for (int i = 0; i < cantReg; i++) {
        reg = archresenia.leerRegistro(i);
        v[pos] = reg;  // Guarda la reseña en el vector
        pos++;
    }
}

void mostrarMayorRes(Resenia *v, int tamanio) {
    Resenia mejorResenia, rese;  // Crea objetos de tipo Resenia para encontrar la mejor reseña
    float maxPuntaje = 0;  // Inicializa el puntaje máximo en 0

    // Recorre el vector de reseñas
    for (int i = 0; i < tamanio; i++) {
        rese = v[i];
        // Comprueba si la reseña está activa y si su puntaje es mayor al puntaje máximo
        if (rese.getEstado() && rese > maxPuntaje) {
            maxPuntaje = rese.getPuntuacionResenia();  // Actualiza el puntaje máximo
            mejorResenia = rese;  // Guarda la mejor reseña
        }
    }

    // Muestra la mejor reseña o un mensaje si no hay reseñas activas con un puntaje válido
    if (maxPuntaje == 0) {
        cout << "NO EXISTEN RESEÑAS ACTIVAS CON UN PUNTAJE VÁLIDO" << endl;
    } else {
        cout << "LA RESEÑA CON LA MEJOR PUNTUACIÓN ES: " << endl;
        mejorResenia.Mostrar();  // Muestra la mejor reseña
    }
}

void reseniaMejorPuntaje() {
    ArchivoResenias archresenia("resenias.dat");  // Abre un archivo de reseñas llamado "resenias.dat"

    Resenia *v;  // Crea un puntero a un vector de reseñas
    int cantidadResenias = archresenia.contarRegistros();  // Obtiene la cantidad de reseñas en el archivo

    // Verifica si existen reseñas en el archivo
    if (cantidadResenias == 0) {
        cout << "NO HAY RESEÑAS DISPONIBLES" << endl;
        return;
    }

    v = new Resenia[cantidadResenias];  // Reserva memoria para el vector de reseñas

    if (v == nullptr) {
        cout << "ERROR AL RESERVAR MEMORIA PARA EL VECTOR" << endl;
        return;
    }

    cargarVectorRes(v);  // Carga las reseñas en el vector
    mostrarMayorRes(v, cantidadResenias);  // Encuentra y muestra la mejor reseña
    delete[] v;  // Libera la memoria del vector
}

void cargarVectorPel(Pelicula *v) {
    ArchivoPeliculas arch("peliculas.dat");  // Abre un archivo de películas llamado "peliculas.dat"
    Pelicula reg;  // Crea un objeto de tipo Pelicula
    int pos = 0;  // Inicializa la posición en 0
    int cantReg = arch.contarRegistros();  // Obtiene la cantidad de registros en el archivo

    // Recorre los registros en el archivo y los guarda en un vector
    for (int i = 0; i < cantReg; i++) {
        reg = arch.leerRegistro(i);
        v[pos] = reg;  // Guarda la película en el vector
        pos++;
    }
}

float PromediarResenias(Pelicula input) {
    ArchivoResenias arch("resenias.dat");  // Abre un archivo de reseñas llamado "resenias.dat"
    Resenia reg;  // Crea un objeto de tipo Resenia
    int cantReg;
    float prom = 0;
    int cant = 0;

    cantReg = arch.contarRegistros();  // Obtiene la cantidad de reseñas en el archivo

    // Recorre las reseñas en el archivo y calcula el promedio de puntajes para la película dada
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
    Pelicula mayorpel, reg;  // Crea objetos de tipo Pelicula para encontrar la película con el mejor promedio de reseñas
    float maxPuntaje = 0;  // Inicializa el promedio máximo en 0

    // Recorre el vector de películas
    for (int i = 0; i < tamanio; i++) {
        reg = v[i];
        float prom = PromediarResenias(reg);  // Calcula el promedio de reseñas para la película actual

        // Comprueba si el promedio es mayor al promedio máximo
        if (prom > maxPuntaje) {
            mayorpel = reg;  // Actualiza la película con el mejor promedio
            maxPuntaje = prom;  // Actualiza el promedio máximo
        }
    }

    mayorpel.Mostrar();  // Muestra la película con el mejor promedio de reseñas
}

void peliculaMejorPuntaje() {
    ArchivoPeliculas arch("peliculas.dat");  // Abre un archivo de películas llamado "peliculas.dat"

    Pelicula *v;  // Crea un puntero a un vector de películas
    int cantidadRegistros = arch.contarRegistros();  // Obtiene la cantidad de películas en el archivo

    // Verifica si existen películas en el archivo
    if (cantidadRegistros == 0) {
        cout << "NO HAY PELÍCULAS DISPONIBLES" << endl;
        return;
    }

    v = new Pelicula[cantidadRegistros];  // Reserva memoria para el vector de películas

    if (v == nullptr) {
        cout << "ERROR AL RESERVAR MEMORIA PARA EL VECTOR" << endl;
        return;
    }

    cargarVectorPel(v);  // Carga las películas en el vector
    mostrarMayorPel(v, cantidadRegistros);  // Encuentra y muestra la película con el mejor promedio de reseñas
    delete[] v;  // Libera la memoria del vector
}

#endif // REPORTES_H_INCLUDED
