#ifndef CLASE_FECHA_H_INCLUDED
#define CLASE_FECHA_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/

class Fecha {
  private:
    int dia, mes, anio;
  public:
    void Cargar() {
        bool entra;
        entra=true;
        while (entra) {
            cout<<endl<<"INGRESE EL DIA: ";
            cin>>dia;
            if (setDia(dia)) {
                entra=false;
            } else {
                cout<<"EL DIA INGRESADO NO ES VALIDO:"<<endl;
            }
        }

        entra=true;
        while (entra==true) {
            cout<<"INGRESE EL MES: ";
            cin>>mes;
            if (setMes(mes)) {
                entra=false;
            } else {
                cout<<"EL MES INGRESADO NO ES VALIDO:"<<endl;
            }
        }

        entra=true;
        while (entra) {
            cout<<"INGRESE EL ANIO: ";
            cin>>anio;
            if (setAnio(anio)) {
                entra=false;
            } else {
                cout<<"EL ANIO INGRESADO NO ES VALIDO:"<<endl;
            }
        }

        if (!esFechaValida(dia, mes, anio)) {
            cout << "LA FECHA INGRESADA NO ES VALIDA. INTENTE NUEVAMENTE." << endl;
            cout << endl;
            Cargar();
        }
    };

    void Mostrar() {
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }

    //set


    bool setDia(int d) {
        if (dia<=31 && dia>=1) {
            dia=d;
            return true;
        } else return false;
    }
    bool setMes(int m) {
        if (mes>=1 && mes<=12) {
            mes=m;
            return true;
        } else return false;
    }
    bool setAnio(int a) {
        if (anio>=1000) {
            anio=a;
            return true;
        } else return false;
    }

    //get

    int getDia() {
        return dia;
    }
    int getMes() {
        return mes;
    }
    int getAnio() {
        return anio;
    }

    //Constructor
    Fecha(int d=6, int m=6, int a=6) {
        setDia(d);
        setMes(m);
        setAnio(a);
    }

    //Verificacion

    bool esFechaValida(int dia, int mes, int anio) {
        time_t now = time(0);
        tm *f = localtime(&now);    //fecha actual
        if (anio > f->tm_year + 1900 || (anio == f->tm_year + 1900 && mes > f->tm_mon + 1) || (anio == f->tm_year + 1900 && mes == f->tm_mon + 1 && dia > f->tm_mday)) {
            cout << "LA FECHA DEBE SER - O = A LA FECHA ACTUAL." << endl;
            return false;
        }

        bool esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);

        if (mes == 2) {
            if (esBisiesto) {
                return dia >= 1 && dia <= 29;
            } else {
                return dia >= 1 && dia <= 28;
            }
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            return dia >= 1 && dia <= 30;
        }
        return true;
    }
};


#endif // CLASE_FECHA_H_INCLUDED
