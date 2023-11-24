#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

//En este archivo se encuentra el menu, y sus funciones.

void reseniaMejorPuntaje();
void peliculaMejorPuntaje();
void UsuariomasActivo();
void GeneroFavoritoMayoria();
void CorrerTodoReporte();

void MenuReportes() {
    char op;
    bool correrMenu = true;
    system("cls");
    while(correrMenu) {
        system("cls");
        cout << endl;
        cout << "                    MENU REPORTES                  " << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " A - MOSTRAR RESENIA DE MAYOR PUNTAJE              " << endl;
        cout << " B - MOSTRAR PELICULA CON MAYOR PROMEDIO PUNTAJES  " << endl;
        cout << " C - MOSTRAR USUARIO QUE ESCRIBIO MAS RESENIAS     " << endl;
        cout << " D - MOSTRAR GENERO FAVORITO DE LA MAYORIA         " << endl;
        cout << " E - TODOS LOS REPORTES!                           " << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " X - VOLVER AL MENU PRINCIPAL                      " << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> op;
        system("cls");
        switch (op) {
        case 'A':
            reseniaMejorPuntaje();
            break;
        case 'B':
            peliculaMejorPuntaje();
            break;
        case 'C':
            UsuariomasActivo();
            break;
        case 'D':
            GeneroFavoritoMayoria();
            break;
        case 'E':
            CorrerTodoReporte();
            break;
        case 'X':
            correrMenu = false;
            break;
        default:
            gotoxy(10,10);
            rlutil::anykey("POR FAVOR, INGRESAR UNA OPCION CORRECTA (PRESIONE BOTON PARA CONTINUAR)");
            system("cls");
            break;
        }

    }
    return;
}

//Funciones de Resenia Mejor Puntaje

void cargarVectorRes(Resenia *v) {
    ArchivoResenias archresenia("resenias.dat");  // Abre un archivo de resenias llamado "resenias.dat"
    Resenia reg;  // Crea un objeto de tipo Resenia
    int pos = 0;  // Inicializa la posicion en 0
    int cantReg = archresenia.contarRegistros();  // Obtiene la cantidad de registros en el archivo

    // Recorre los registros en el archivo y los guarda en un vector
    for (int i = 0; i < cantReg; i++) {
        reg = archresenia.leerRegistro(i);
        v[pos] = reg;  // Guarda la resenia en el vector
        pos++;
    }
}

void mostrarMayorRes(Resenia *v, int tamanio) {
    Resenia mejorResenia, rese;  // Crea objetos de tipo Resenia para encontrar la mejor rese�a
    float maxPuntaje = 0;  // Inicializa el puntaje maximo en 0

    // Recorre el vector de resenias
    for (int i = 0; i < tamanio; i++) {
        rese = v[i];
        // Comprueba si la resenia esta activa y si su puntaje es mayor al puntaje maximo
        if (rese.getEstado() && rese > maxPuntaje) {
            maxPuntaje = rese.getPuntuacionResenia();  // Actualiza el puntaje maximo
            mejorResenia = rese;  // Guarda la mejor resenia
        }
    }

    // Muestra la mejor resenia o un mensaje si no hay resenias activas con un puntaje valido
    if (maxPuntaje == 0) {
        cout << "NO EXISTEN RESENIAS ACTIVAS CON UN PUNTAJE VALIDO" << endl;
        system("pause");
    } else {
        cout << "LA RESENIA CON LA MEJOR PUNTUACION ES: " << endl;
        mejorResenia.Mostrar();  // Muestra la mejor resenia
        system("pause");
    }
}

void reseniaMejorPuntaje() {
    ArchivoResenias archresenia("resenias.dat");  // Abre un archivo de resenias llamado "resenias.dat"

    Resenia *v;  // Crea un puntero a un vector de resenias
    int cantidadResenias = archresenia.contarRegistros();  // Obtiene la cantidad de resenias en el archivo

    // Verifica si existen resenias en el archivo
    if (cantidadResenias == 0) {
        cout << "NO HAY RESENIAS DISPONIBLES" << endl;
        system("pause");
        return;
    }

    v = new Resenia[cantidadResenias];  // Reserva memoria para el vector de resenias

    if (v == nullptr) {
        cout << "ERROR AL RESERVAR MEMORIA PARA EL VECTOR" << endl;
        system("pause");
        return;
    }

    cargarVectorRes(v);  // Carga las resenias en el vector
    mostrarMayorRes(v, cantidadResenias);  // Encuentra y muestra la mejor resenia
    delete[] v;  // Libera la memoria del vector
}

//Funciones de Pelicula con mejor promedio de puntajes.

void cargarVectorPel(Pelicula *v) {
    ArchivoPeliculas arch("peliculas.dat");  // Abre un archivo de peliculas llamado "peliculas.dat"
    Pelicula reg;  // Crea un objeto de tipo Pelicula
    int pos = 0;  // Inicializa la posicion en 0
    int cantReg = arch.contarRegistros();  // Obtiene la cantidad de registros en el archivo

    // Recorre los registros en el archivo y los guarda en un vector
    for (int i = 0; i < cantReg; i++) {
        reg = arch.leerRegistro(i);
        v[pos] = reg;  // Guarda la pelicula en el vector
        pos++;
    }
}

float PromediarResenias(Pelicula input) {
    ArchivoResenias arch("resenias.dat");  // Abre un archivo de resenias llamado "resenias.dat"
    Resenia reg;  // Crea un objeto de tipo Resenia
    int cantReg;
    float prom = 0;
    int cant = 0;

    cantReg = arch.contarRegistros();  // Obtiene la cantidad de resenias en el archivo

    // Recorre las resenias en el archivo y calcula el promedio de puntajes para la pelicula dada
    for (int i = 0; i < cantReg; i++) {
        reg = arch.leerRegistro(i);
        if (reg.getidPeliculaResenia()== input.getIdPelicula()) {
            prom += reg.getPuntuacionResenia();
            cant++;
        }
    }

    return prom / cant;  // Devuelve el promedio de puntajes
}

void mostrarMayorPel(Pelicula *v, int tamanio) {
    Pelicula mayorpel, reg;  // Crea objetos de tipo Pelicula para encontrar la pel�cula con el mejor promedio de rese�as
    float maxPuntaje = 0;  // Inicializa el promedio maximo en 0

    // Recorre el vector de pel�culas
    for (int i = 0; i < tamanio; i++) {
        reg = v[i];
        float prom = PromediarResenias(reg);  // Calcula el promedio de resenias para la pel�cula actual

        // Comprueba si el promedio es mayor al promedio maximo
        if (prom > maxPuntaje) {
            mayorpel = reg;  // Actualiza la pelicula con el mejor promedio
            maxPuntaje = prom;  // Actualiza el promedio maximo
        }
    }

    mayorpel.Mostrar();  // Muestra la pelicula con el mejor promedio de resenias
    system("pause");
}

void peliculaMejorPuntaje() {
    ArchivoPeliculas arch("peliculas.dat");  // Abre un archivo de pel�culas llamado "peliculas.dat"

    Pelicula *v;  // Crea un puntero a un vector de peliculas
    int cantidadRegistros = arch.contarRegistros();  // Obtiene la cantidad de peliculas en el archivo

    // Verifica si existen peliculas en el archivo
    if (cantidadRegistros == 0) {
        cout << "NO HAY PELICULAS DISPONIBLES" << endl;
        system("pause");
        return;
    }

    v = new Pelicula[cantidadRegistros];  // Reserva memoria para el vector de peliculas

    if (v == nullptr) {
        cout << "ERROR AL RESERVAR MEMORIA PARA EL VECTOR" << endl;
        system("pause");
        return;
    }

    cargarVectorPel(v);  // Carga las peliculas en el vector
    mostrarMayorPel(v, cantidadRegistros);  // Encuentra y muestra la pelicula con el mejor promedio de resenias
    delete[] v;  // Libera la memoria del vector
}


//Funciones de Mostrar Usuario Mas activo

void cargarVectorUsuarios(Usuario *v) {
    // Abrir el archivo de usuarios
    ArchivoUsuarios arch("usuarios.dat");
    Usuario reg;
    int pos = 0;
    int cantReg = arch.contarRegistros();

    // Leer los registros del archivo y cargarlos en el vector
    for (int i = 0; i < cantReg; i++) {
        reg = arch.leerRegistro(i);
        v[pos] = reg;
        pos++;
    }
}

int ConseguirCantResenias(Usuario input) {
    // Abrir el archivo de resenias
    ArchivoResenias arch("resenias.dat");
    Resenia reg;
    int cantReg;
    int cantidad = 0;

    // Contar la cantidad de registros en el archivo
    cantReg = arch.contarRegistros();

    // Recorrer los registros y contar las resenias del usuario dado
    for (int i = 0; i < cantReg; i++) {
        reg = arch.leerRegistro(i);
        if (reg.getidAutorResenia()== input.getIdUsuario()) {
            cantidad++;
        }
    }

    return cantidad;
}

void mostrarMasActivoUsuario(Usuario *v, int tamanio) {
    Usuario usuarioMasActivo, reg;
    int maxActividad = 0;
    int actividadUsuario;

    // Recorrer el vector de usuarios y encontrar el mas activo
    for (int i = 0; i < tamanio; i++) {
        reg = v[i];
        actividadUsuario = ConseguirCantResenias(reg);

        if (actividadUsuario > maxActividad) {
            usuarioMasActivo = reg;
            maxActividad = actividadUsuario;
        }
    }

    // Mostrar al usuario mas activo
    usuarioMasActivo.Mostrar();
    system("pause");

}

void UsuariomasActivo() {
    // Abrir el archivo de usuarios
    ArchivoUsuarios arch("usuarios.dat");

    Usuario *vec;
    int cantidadRegUsuarios = arch.contarRegistros();

    if (cantidadRegUsuarios == 0) {
        cout << "NO HAY USUARIOS DISPONIBLES" << endl;
        system("pause");
        return;
    }

    vec = new Usuario[cantidadRegUsuarios];

    if (vec == nullptr) {
        cout << "ERROR AL RESERVAR MEMORIA PARA EL VECTOR" << endl;
        system("pause");
        return;
    }

    // Cargar el vector de usuarios y mostrar al usuario mas activo
    cargarVectorUsuarios(vec);
    mostrarMasActivoUsuario(vec, cantidadRegUsuarios);
    delete[] vec;
}

//Funciones mostrar genero favorito de la mayoria

// Funcion para cargar un vector de generos desde un archivo
void cargarVectorGeneros(Genero *v) {
    ArchivoGeneros arch("generos.dat");
    Genero reg;
    int pos = 0;
    int cantReg = arch.contarRegistros();

    // Iterar a traves de los registros en el archivo de generos
    for (int i = 0; i < cantReg; i++) {
        reg = arch.leerRegistro(i);
        v[pos] = reg;  // Almacenar el genero en el vector
        pos++;
    }
}

// Funcion para obtener la cantidad de usuarios con un genero favorito dado
int ConseguirNumeroFavoritos(Genero input) {
    ArchivoUsuarios arch("usuarios.dat");
    Usuario reg;
    int cantReg;
    int cantidad = 0;

    cantReg = arch.contarRegistros();

    // Iterar a traves de los registros de usuarios y contar aquellos con el genero favorito dado
    for (int i = 0; i < cantReg; i++) {
        reg = arch.leerRegistro(i);
        if (reg.getidGeneroFavorito()== input.getIdGenero()) {
            cantidad++;
        }
    }

    return cantidad;
}

// Funcion para mostrar el genero mayoritario entre los usuarios
void mostrarGeneroMayoria(Genero *v, int tamanio) {
    Genero generomayoritario, reg;
    int maxFavoritos = 0;
    int cantTemp;

    // Encontrar el genero con la mayoria de favoritos entre los usuarios
    for (int i = 0; i < tamanio; i++) {
        reg = v[i];
        cantTemp = ConseguirNumeroFavoritos(reg);

        if (cantTemp > maxFavoritos) {
            generomayoritario = reg;
            maxFavoritos = cantTemp;
        }
    }

    generomayoritario.Mostrar();  // Mostrar el genero mayoritario
    system("pause");
}

// Funcion principal para encontrar el genero favorito mayoritario
void GeneroFavoritoMayoria() {
    ArchivoGeneros arch("generos.dat");

    Genero *vec;
    int cantidadReg = arch.contarRegistros();

    // Verificar si no hay registros de generos disponibles
    if (cantidadReg == 0) {
        cout << "NO HAY GENEROS DISPONIBLES" << endl;
        system("pause");
        return;
    }

    vec = new Genero[cantidadReg];

    // Verificar si hay un error al reservar memoria para el vector
    if (vec == nullptr) {
        cout << "ERROR AL RESERVAR MEMORIA PARA EL VECTOR" << endl;
        system("pause");
        return;
    }

    cargarVectorGeneros(vec);      // Cargar los generos desde el archivo
    mostrarGeneroMayoria(vec, cantidadReg);  // Encontrar y mostrar el genero mayoritario
    delete[] vec;  // Liberar la memoria asignada al vector
}

//Funciones correr todo reporte

void CorrerTodoReporte() {
    cout << "RESENIA CON MEJOR PUNTAJE" << endl;
    reseniaMejorPuntaje();
    cout << "PELICULA CON MEJORES RESENIAS" << endl;
    peliculaMejorPuntaje();
    cout << "USUARIO QUE MAS ESCRIBIO" << endl;
    UsuariomasActivo();
    cout << "GENERO FAVORITO DE LA MAYORIA DE USUARIOS" << endl;
    GeneroFavoritoMayoria();
}
#endif // REPORTES_H_INCLUDED
