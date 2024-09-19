#include <iostream>
#include <string>
using namespace std;

class Solicitud {
private:
    string nombreAlumno;
    string carrera;
    int materiasAprobadas;
    float promedio;

public:
    Solicitud() : nombreAlumno(""), carrera(""), materiasAprobadas(0), promedio(0.0) {}

    // Constructor
    Solicitud(string nombre, string carrera, int materias, float promedio)
        : nombreAlumno(nombre), carrera(carrera), materiasAprobadas(materias), promedio(promedio) {}

    // Sobrecarga del operador de inserción '<<' para imprimir la solicitud
    friend ostream& operator<<(ostream& out, const Solicitud& s) {
        out << "Alumno: " << s.nombreAlumno << endl;
        out << "Carrera: " << s.carrera << endl;
        out << "Materias aprobadas: " << s.materiasAprobadas << endl;
        out << "Promedio general: " << s.promedio << endl;
        return out;
    }

    // Sobrecarga del operador de extracción '>>' para ingresar la solicitud
    friend istream& operator>>(istream& in, Solicitud& s) {
        cout << "Ingresa el nombre del alumno: ";
        getline(in, s.nombreAlumno);
        cout << "Ingresa la carrera del alumno: ";
        getline(in, s.carrera);
        cout << "Ingresa el número de materias aprobadas: ";
        in >> s.materiasAprobadas;
        cout << "Ingresa el promedio general: ";
        in >> s.promedio;
        in.ignore(); // Limpiar el buffer de entrada para evitar problemas con getline
        return in;
    }
};


template <typename T>
class Cola {
private:
    int frente;
    int final;
    static const int MAX = 100; // Tamaño máximo de la cola
    T elementos[MAX];

public:
    Cola() : frente(0), final(0) {} // Constructor inicializando una cola vacía

    bool vacia() const {
        return frente == final;
    }

    bool llena() const {
        return final == MAX;
    }

    bool encolar(const T& elemento) {
        if (llena()) {
            return false; // Si está llena, no se puede encolar
        }
        elementos[final++] = elemento;
        return true;
    }

    bool desencolar() {
        if (vacia()) {
            return false; // Si está vacía, no se puede desencolar
        }
        for (int i = 0; i < final - 1; i++) {
            elementos[i] = elementos[i + 1]; // Mover todos los elementos hacia adelante
        }
        final--; // Reducir el tamaño de la cola
        return true;
    }

    T& frenteElemento() {
        if (!vacia()) {
            return elementos[frente];
        }
        throw out_of_range("La cola está vacía");
    }

    void mostrarFrente() {
        if (!vacia()) {
            cout << "Solicitud a procesar:" << endl;
            cout << elementos[frente] << endl;
        } else {
            cout << "No hay solicitudes pendientes." << endl;
        }
    }
};

int main() {
    Cola<Solicitud> colaSolicitudes;
    int opcion;

    do {
        cout << "Menu de opciones:" << endl;
        cout << "1. Dar de alta solicitud (Encolar)" << endl;
        cout << "2. Elaborar constancia (Desencolar)" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opción: ";
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea después de la elección

        switch (opcion) {
            case 1: {
                Solicitud nuevaSolicitud;
                cin >> nuevaSolicitud; // Sobrecargamos el operador >> para ingresar los datos
                if (colaSolicitudes.encolar(nuevaSolicitud)) {
                    cout << "Solicitud encolada correctamente." << endl;
                } else {
                    cout << "Error: la cola de solicitudes está llena." << endl;
                }
                break;
            }
            case 2: {
                if (!colaSolicitudes.vacia()) {
                    colaSolicitudes.mostrarFrente();
                    colaSolicitudes.desencolar();
                    cout << "Constancia elaborada y solicitud atendida." << endl;
                } else {
                    cout << "No hay solicitudes pendientes." << endl;
                }
                break;
            }
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);

    return 0;
}
