#include <iostream>
#include <string>
#include <algorithm> // Para std::sort

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

    Solicitud(string nombre, string carrera, int materias, float promedio)
        : nombreAlumno(nombre), carrera(carrera), materiasAprobadas(materias), promedio(promedio) {}

    string getNombre() const {
        return nombreAlumno;
    }

    friend ostream& operator<<(ostream& out, const Solicitud& s) {
        out << "Alumno: " << s.nombreAlumno << endl;
        out << "Carrera: " << s.carrera << endl;
        out << "Materias aprobadas: " << s.materiasAprobadas << endl;
        out << "Promedio general: " << s.promedio << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Solicitud& s) {
        cout << "Ingresa el nombre del alumno: ";
        getline(in, s.nombreAlumno);
        cout << "Ingresa la carrera del alumno: ";
        getline(in, s.carrera);
        cout << "Ingresa el número de materias aprobadas: ";
        in >> s.materiasAprobadas;
        cout << "Ingresa el promedio general: ";
        in >> s.promedio;
        in.ignore();
        return in;
    }

    bool operator==(const string& nombre) const {
        return nombreAlumno == nombre;
    }

    bool operator<(const Solicitud& other) const {
        return nombreAlumno < other.nombreAlumno;
    }
};

// Clase Cola basada en plantillas
template <typename T>
class Cola {
private:
    int frente;
    int final;
    static const int MAX = 100;
    T elementos[MAX];

public:
    Cola() : frente(0), final(0) {}

    bool vacia() const {
        return frente == final;
    }

    bool llena() const {
        return final == MAX;
    }

    bool encolar(const T& elemento) {
        if (llena()) {
            return false;
        }
        elementos[final++] = elemento;
        return true;
    }

    bool desencolar() {
        if (vacia()) {
            return false;
        }
        for (int i = 0; i < final - 1; i++) {
            elementos[i] = elementos[i + 1];
        }
        final--;
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

    // Búsqueda lineal para encontrar una solicitud
    void buscarSolicitud(const string& nombre) {
        if (vacia()) {
            cout << "No hay solicitudes en la cola." << endl;
            return;
        }
        for (int i = frente; i < final; i++) {
            if (elementos[i].getNombre() == nombre) {
                cout << "Solicitud encontrada en la posición " << i - frente + 1 << ":" << endl;
                cout << "Constancias por atender antes: " << i - frente << endl;
                return;
            }
        }
        cout << "Solicitud no encontrada. Debes dar de alta una solicitud." << endl;
    }

    // Ordenar la cola por el nombre del alumno
    void ordenarCola() {
        sort(elementos + frente, elementos + final); // Ordenar usando el operador < sobrecargado
    }

    // Búsqueda binaria para encontrar una solicitud
    void buscarBinario(const string& nombre) {
        if (vacia()) {
            cout << "No hay solicitudes en la cola." << endl;
            return;
        }

        int inicio = frente;
        int fin = final - 1;
        while (inicio <= fin) {
            int medio = (inicio + fin) / 2;
            if (elementos[medio].getNombre() == nombre) {
                cout << "Solicitud encontrada en la posición " << medio - frente + 1 << "." << endl;
                cout << "Constancias por atender antes: " << medio - frente << endl;
                return;
            }
            if (elementos[medio].getNombre() < nombre) {
                inicio = medio + 1;
            } else {
                fin = medio - 1;
            }
        }
        cout << "Solicitud no encontrada. Debes dar de alta una solicitud." << endl;
    }
};

int main() {
    Cola<Solicitud> colaSolicitudes;
    int opcion;

    do {
        cout << "Menu de opciones:" << endl;
        cout << "1. Dar de alta solicitud (Encolar)" << endl;
        cout << "2. Elaborar constancia (Desencolar)" << endl;
        cout << "3. Buscar solicitud (Lineal)" << endl;
        cout << "4. Buscar solicitud (Binario)" << endl;
        cout << "5. Ordenar cola" << endl;
        cout << "6. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                Solicitud nuevaSolicitud;
                cin >> nuevaSolicitud;
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
            case 3: {
                string nombre;
                cout << "Ingresa el nombre del alumno para buscar su solicitud: ";
                getline(cin, nombre);
                colaSolicitudes.buscarSolicitud(nombre); // Búsqueda lineal
                break;
            }
            case 4: {
                string nombre;
                cout << "Ingresa el nombre del alumno para buscar su solicitud (binario): ";
                getline(cin, nombre);
                colaSolicitudes.buscarBinario(nombre); // Búsqueda binaria
                break;
            }
            case 5: {
                colaSolicitudes.ordenarCola(); // Ordenar la cola antes de usar la búsqueda binaria
                cout << "Cola ordenada correctamente." << endl;
                break;
            }
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 6);

    return 0;
}
