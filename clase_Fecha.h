#ifndef CLASE_FECHA_H_INCLUDED
#define CLASE_FECHA_H_INCLUDED

/*
  AUTORES:
  -Arias, Natalia (Virtual)
  -Gallino, Gianluca (Virtual)
  -Parra, Juan (Presencial)
*/
// Definición de la clase Fecha
class Fecha {
  private:
    int dia, mes, anio; // Propiedades de la fecha: día, mes y año

  public:
    // Método para cargar una fecha válida
    void Cargar() {
        bool entra;
        entra = true;

        while (entra) {
            cout << endl << "INGRESE EL DIA: ";
            cin >> dia;

            if (setDia(dia)) {
                entra = false;
            } else {
                cout << "EL DIA INGRESADO NO ES VALIDO:" << endl;
            }
        }

        entra = true;

        while (entra) {
            cout << "INGRESE EL MES: ";
            cin >> mes;

            if (setMes(mes)) {
                entra = false;
            } else {
                cout << "EL MES INGRESADO NO ES VALIDO:" << endl;
            }
        }

        entra = true;

        while (entra) {
            cout << "INGRESE EL ANIO: ";
            cin >> anio;

            if (setAnio(anio)) {
                entra = false;
            } else {
                cout << "EL ANIO INGRESADO NO ES VALIDO:" << endl;
            }
        }

        // Verifica si la fecha ingresada es válida
        if (!esFechaValida(dia, mes, anio)) {
            cout << "LA FECHA INGRESADA NO ES VALIDA. INTENTE NUEVAMENTE." << endl;
            cout << endl;
            Cargar();
        }
    };

    // Método para mostrar la fecha
    void Mostrar() {
        cout << dia << "/" << mes << "/" << anio << endl;
    }

    // Métodos de configuración (set)

    bool setDia(int d) {
        if (d <= 31 && d >= 1) {
            dia = d;
            return true;
        } else {
            return false;
        }
    }

    bool setMes(int m) {
        if (m >= 1 && m <= 12) {
            mes = m;
            return true;
        } else {
            return false;
        }
    }

    bool setAnio(int a) {
        if (a >= 1000) {
            anio = a;
            return true;
        } else {
            return false;
        }
    }

    // Métodos de obtención (get)

    int getDia() {
        return dia;
    }

    int getMes() {
        return mes;
    }

    int getAnio() {
        return anio;
    }

    // Constructor de la clase Fecha con valores por defecto (6/6/6)
    Fecha(int d = 6, int m = 6, int a = 6) {
        setDia(d);
        setMes(m);
        setAnio(a);
    }

    // Verifica si la fecha es válida
    bool esFechaValida(int dia, int mes, int anio) {
        time_t now = time(0);
        tm *f = localtime(&now); // Fecha actual

        // Compara la fecha ingresada con la fecha actual
        if (anio > f->tm_year + 1900 || (anio == f->tm_year + 1900 && mes > f->tm_mon + 1) ||
                (anio == f->tm_year + 1900 && mes == f->tm_mon + 1 && dia > f->tm_mday)) {
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
