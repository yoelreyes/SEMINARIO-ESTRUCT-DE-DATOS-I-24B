#include <iostream>
#include <string>
using namespace std;

// Clase Solicitud
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

    // Sobrecarga del operador '<<' para imprimir la solicitud
    friend ostream& operator<<(ostream& out, const Solicitud& s) {
        out << "Alumno: " << s.nombreAlumno << endl;
        out << "Carrera: " << s.carrera << endl;
        out << "Materias aprobadas: " << s.materiasAprobadas << endl;
        out << "Promedio general: " << s.promedio << endl;
        return out;
    }

    // Sobrecarga del operador '>>' para ingresar una solicitud
    friend istream& operator>>(istream& in, Solicitud& s) {
        cout << "Nombre del alumno: ";
        getline(in, s.nombreAlumno);
        cout << "Carrera: ";
        getline(in, s.carrera);
        cout << "Número de materias aprobadas: ";
        in >> s.materiasAprobadas;
        cout << "Promedio general: ";
        in >> s.promedio;
        in.ignore(); // Limpiar el buffer de entrada
        return in;
    }
};

// Nodo para la cola dinámica
template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;

    Nodo(T valor) : dato(valor), siguiente(nullptr) {}
};

// Clase ColaDinamica (cola con lista enlazada)
template <typename T>
class ColaDinamica {
private:
    Nodo<T>* frente; // Primer elemento de la cola
    Nodo<T>* final;  // Último elemento de la cola

public:
    ColaDinamica() : frente(nullptr), final(nullptr) {}

    // Verificar si la cola está vacía
    bool vacia() const {
        return frente == nullptr;
    }

    // Encolar un elemento (agregar al final)
    void encolar(const T& elemento) {
        Nodo<T>* nuevo = new Nodo<T>(elemento);
        if (vacia()) {
            frente = final = nuevo;
        } else {
            final->siguiente = nuevo;
            final = nuevo;
        }
    }

    // Desencolar un elemento (retirar del frente)
    bool desencolar() {
        if (vacia()) {
            cout << "No hay solicitudes en la cola." << endl;
            return false;
        }
        Nodo<T>* temp = frente;
        frente = frente->siguiente;
        if (!frente) final = nullptr;
        delete temp;
        return true;
    }

    // Obtener el frente de la cola
    T& obtenerFrente() const {
        if (vacia()) throw out_of_range("La cola está vacía");
        return frente->dato;
    }

    // Mostrar la solicitud del frente sin eliminarla
    void mostrarFrente() const {
        if (!vacia()) {
            cout << "Solicitud en proceso:" << endl;
            cout << obtenerFrente() << endl;
        } else {
            cout << "No hay solicitudes pendientes." << endl;
        }
    }

    // Destructor para liberar memoria
    ~ColaDinamica() {
        while (!vacia()) {
            desencolar();
        }
    }
};

int main() {
    ColaDinamica<Solicitud> colaSolicitudes;
    int opcion;

    do {
        cout << "Menú de opciones:" << endl;
        cout << "1. Dar de alta solicitud (Encolar)" << endl;
        cout << "2. Elaborar constancia (Desencolar)" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opción: ";
        cin >> opcion;
        cin.ignore(); // Ignorar salto de línea

        switch (opcion) {
            case 1: {
                Solicitud nuevaSolicitud;
                cin >> nuevaSolicitud;
                colaSolicitudes.encolar(nuevaSolicitud);
                cout << "Solicitud encolada correctamente." << endl;
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
