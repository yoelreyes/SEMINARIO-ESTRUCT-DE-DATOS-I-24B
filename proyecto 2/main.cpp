#include <iostream>
#include <string>
using namespace std;

class Materia {
private:
    int clave;
    string nombre;
    string profesor;
    string libroTexto;

public:
    // Constructor
    Materia(int clave, string nombre, string profesor, string libroTexto)
        : clave(clave), nombre(nombre), profesor(profesor), libroTexto(libroTexto) {}

    // M�todos
    void imprime() {
        cout << "Clave de la Materia: " << clave << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Profesor: " << profesor << endl;
        cout << "Libro de Texto: " << libroTexto << endl;
    }

    void cambiaClave(int nuevaClave) {
        clave = nuevaClave;
    }

    void cambiaProfesor(string nuevoProfesor) {
        profesor = nuevoProfesor;
    }

    int getClave() {
        return clave;
    }

    string getNombre() {
        return nombre;
    }
};

// Funci�n principal
int main() {
    Materia Programacion(101, "Programaci�n", "Prof. Garc�a", "C++ para principiantes");
    Materia BasesDatos(102, "Bases de Datos", "Prof. Rodr�guez", "Fundamentos de Bases de Datos");

    int opcion;
    do {
        cout << "Menu de opciones:" << endl;
        cout << "1. Cambiar la clave de la materia Programaci�n" << endl;
        cout << "2. Cambiar el nombre del maestro que imparte la materia Bases de Datos" << endl;
        cout << "3. Imprimir todos los datos de la materia Bases de Datos" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int nuevaClave;
            cout << "Ingrese la nueva clave para la materia Programaci�n: ";
            cin >> nuevaClave;
            Programacion.cambiaClave(nuevaClave);
            cout << "Clave de Programaci�n cambiada exitosamente." << endl;
            break;
        }
        case 2: {
            string nuevoProfesor;
            cout << "Ingrese el nuevo nombre del maestro para la materia Bases de Datos: ";
            cin.ignore();
            getline(cin, nuevoProfesor);
            BasesDatos.cambiaProfesor(nuevoProfesor);
            cout << "Profesor de Bases de Datos cambiado exitosamente." << endl;
            break;
        }
        case 3: {
            cout << "Datos de la materia Bases de Datos:" << endl;
            BasesDatos.imprime();
            break;
        }
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opci�n no v�lida." << endl;
            break;
        }
    } while (opcion != 4);

    return 0;
}
