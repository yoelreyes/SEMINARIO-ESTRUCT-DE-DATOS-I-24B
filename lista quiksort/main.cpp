#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Clase Solicitud
class Solicitud {
private:
    string nombreAlumno;
    string carrera;
    string preparatoria;
    float promedio;

public:
    Solicitud() : nombreAlumno(""), carrera(""), preparatoria(""), promedio(0.0) {}

    Solicitud(string nombre, string carrera, string prepa, float promedio)
        : nombreAlumno(nombre), carrera(carrera), preparatoria(prepa), promedio(promedio) {}

    float getPromedio() const {
        return promedio;
    }

    string getNombre() const {
        return nombreAlumno;
    }

    friend ostream& operator<<(ostream& out, const Solicitud& s) {
        out << "Alumno: " << s.nombreAlumno << endl;
        out << "Carrera: " << s.carrera << endl;
        out << "Preparatoria: " << s.preparatoria << endl;
        out << "Promedio general: " << s.promedio << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Solicitud& s) {
        cout << "Ingresa el nombre del alumno: ";
        getline(in, s.nombreAlumno);
        cout << "Ingresa la carrera a cursar: ";
        getline(in, s.carrera);
        cout << "Ingresa la preparatoria de procedencia: ";
        getline(in, s.preparatoria);
        cout << "Ingresa el promedio general: ";
        in >> s.promedio;
        in.ignore(); // Limpiar buffer para getline
        return in;
    }

    bool operator<(const Solicitud& other) const {
        return promedio > other.promedio; // Ordenar de mayor a menor promedio
    }

    bool operator==(const string& nombre) const {
        return nombreAlumno == nombre;
    }
};

// Clase Lista que maneja la lista de solicitudes
class ListaSolicitudes {
private:
    vector<Solicitud> lista;

    // Implementación del algoritmo de Quicksort
    void quicksort(int inicio, int fin) {
        if (inicio < fin) {
            int p = particion(inicio, fin);
            quicksort(inicio, p - 1);
            quicksort(p + 1, fin);
        }
    }

    int particion(int inicio, int fin) {
        Solicitud pivote = lista[fin];
        int i = inicio - 1;
        for (int j = inicio; j < fin; j++) {
            if (lista[j] < pivote) {
                i++;
                swap(lista[i], lista[j]);
            }
        }
        swap(lista[i + 1], lista[fin]);
        return i + 1;
    }

    // Implementación de la búsqueda binaria
    int busquedaBinaria(const string& nombre) {
        int inicio = 0;
        int fin = lista.size() - 1;
        while (inicio <= fin) {
            int medio = inicio + (fin - inicio) / 2;
            if (lista[medio].getNombre() == nombre) {
                return medio;
            }
            if (lista[medio].getNombre() < nombre) {
                inicio = medio + 1;
            } else {
                fin = medio - 1;
            }
        }
        return -1; // Si no se encuentra
    }

public:
    // Método para dar de alta una solicitud
    void agregarSolicitud(const Solicitud& nuevaSolicitud) {
        lista.push_back(nuevaSolicitud); // Insertar al final
        quicksort(0, lista.size() - 1);  // Ordenar después de cada inserción
    }

    // Método para buscar una solicitud
    void buscarSolicitud(const string& nombre) {
        int posicion = busquedaBinaria(nombre);
        if (posicion != -1) {
            cout << "posiciones adelante " << posicion  << " en la lista." << endl;
            cout << lista[posicion] << endl;
        } else {
            cout << "Solicitud no encontrada. Debes dar de alta una solicitud." << endl;
        }
    }

    // Mostrar todas las solicitudes (opcional, para depuración)
    void mostrarSolicitudes() {
        for (int i = 0; i < lista.size(); i++) {
            cout << "Lugar " << i + 1 << ": " << endl;
            cout << lista[i] << endl;
        }
    }
};

int main() {
    ListaSolicitudes listaSolicitudes;
    int opcion;

    do {
        cout << "Menu de opciones:" << endl;
        cout << "1. Dar de alta solicitud" << endl;
        cout << "2. Buscar solicitud" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea después de la elección

        switch (opcion) {
            case 1: {
                Solicitud nuevaSolicitud;
                cin >> nuevaSolicitud; // Sobrecargamos el operador >> para ingresar los datos
                listaSolicitudes.agregarSolicitud(nuevaSolicitud);
                cout << "Solicitud agregada y lista ordenada." << endl;
                break;
            }
            case 2: {
                string nombre;
                cout << "Ingresa el nombre del alumno para buscar su solicitud: ";
                getline(cin, nombre);
                listaSolicitudes.buscarSolicitud(nombre);
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
