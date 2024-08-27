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
    Materia(int c = 0, string n = "", string p = "", string l = "")
        : clave(c), nombre(n), profesor(p), libroTexto(l) {}

    // Sobrecarga de operadores de comparación
    bool operator==(const Materia& otra) const {
        return clave == otra.clave;
    }

    bool operator!=(const Materia& otra) const {
        return !(*this == otra);
    }

    bool operator<(const Materia& otra) const {
        return clave < otra.clave;
    }

    bool operator>(const Materia& otra) const {
        return clave > otra.clave;
    }

    // Sobrecarga del operador de adición
    Materia operator+(const Materia& otra) const {
        return Materia(clave + otra.clave,
                       nombre + " & " + otra.nombre,
                       profesor + " y " + otra.profesor,
                       libroTexto + " y " + otra.libroTexto);
    }

    // Sobrecarga de operadores de entrada/salida
    friend ostream& operator<<(ostream& os, const Materia& mat) {
        os << "Clave de la Materia: " << mat.clave << "\n"
           << "Nombre: " << mat.nombre << "\n"
           << "Profesor: " << mat.profesor << "\n"
           << "Libro de Texto: " << mat.libroTexto << "\n";
        return os;
    }

    friend istream& operator>>(istream& is, Materia& mat) {
        cout << "Ingrese la clave de la materia: ";
        is >> mat.clave;
        is.ignore();  // Limpiar el buffer de entrada
        cout << "Ingrese el nombre de la materia: ";
        getline(is, mat.nombre);
        cout << "Ingrese el nombre del profesor: ";
        getline(is, mat.profesor);
        cout << "Ingrese el libro de texto: ";
        getline(is, mat.libroTexto);
        return is;
    }

    // Métodos adicionales
    void imprime() const {
        cout << *this;  // Usa la sobrecarga del operador <<
    }

    void cambiaClave(int nuevaClave) {
        clave = nuevaClave;
    }

    void cambiaProfesor(const string& nuevoProfesor) {
        profesor = nuevoProfesor;
    }

    int getClave() const {
        return clave;
    }
};

// Función principal
int main() {
    Materia Programacion(101, "Programación", "Prof. García", "C++ para principiantes");
    Materia BasesDatos(102, "Bases de Datos", "Prof. Rodríguez", "Fundamentos de Bases de Datos");

    int opcion;
    do {
        cout << "\nMenu de opciones:" << endl;
        cout << "1. Cambiar la clave de la materia Programación" << endl;
        cout << "2. Cambiar el nombre del maestro que imparte la materia Bases de Datos" << endl;
        cout << "3. Imprimir todos los datos de la materia Bases de Datos" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int nuevaClave;
            cout << "Ingrese la nueva clave para la materia Programación: ";
            cin >> nuevaClave;
            Programacion.cambiaClave(nuevaClave);
            cout << "Clave de Programación cambiada exitosamente." << endl;
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
            cout << "Opción no válida." << endl;
            break;
        }
    } while (opcion != 4);

    return 0;
}
