#ifndef FUNCION_PANTALLAINTRODUCTORIA_H_INCLUDED
#define FUNCION_PANTALLAINTRODUCTORIA_H_INCLUDED

void PantallaIntroductoria() {
    system("cls");
    rlutil::setColor(rlutil::RED);
    cout<<"   __  _______ _   ________   _____  __"<<endl;
    cout<<"  /  |/  / __ | | / / __/ /  /  _/ |/_/"<<endl;
    cout<<" / /|_/ / /_/ / |/ / _// /___/ /_>  <  "<<endl;
    cout<<"/_/  /_/|____/|___/_/ /____/___/_/|_|  "<<endl;
    cout<<"                                       "<<endl;
    rlutil::setColor(rlutil::WHITE);
    cout<<"   PRESIONE UNA TECLA PARA CONTINUAR!  "<<endl;
    rlutil::anykey();
}

#endif // FUNCION_PANTALLAINTRODUCTORIA_H_INCLUDED
