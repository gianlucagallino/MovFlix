#ifndef FUNCION_PANTALLAINTRODUCTORIA_H_INCLUDED
#define FUNCION_PANTALLAINTRODUCTORIA_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

void PantallaIntroductoria() {
    system("cls");  // Limpia la pantalla.

    // Establece el color de la fuente en rojo.
    rlutil::setColor(rlutil::RED);

    // Imprime el logo de MovFlix.
    rlutil::locate(40, 12);
    cout << "   __  _______ _   ________   _____  __" << endl;
    rlutil::locate(40, 13);
    cout << "  /  |/  / __ | | / / __/ /  /  _/ |/_/" << endl;
    rlutil::locate(40, 14);
    cout << " / /|_/ / /_/ / |/ / _// /___/ /_>  <" << endl;
    rlutil::locate(40, 15);
    cout << "/_/  /_/|____/|___/_/ /____/___/_/|_|" << endl;
    rlutil::locate(40, 16);
    cout << endl;

    // Restablece el color de la fuente a blanco.
    rlutil::setColor(rlutil::WHITE);

    rlutil::locate(40, 17);
    cout << "   PRESIONE UNA TECLA PARA CONTINUAR!  ";

    rlutil::anykey();  // Espera a que el usuario presione una tecla.
}

#endif // FUNCION_PANTALLAINTRODUCTORIA_H_INCLUDED
