#include <iostream>
#include <string>
using namespace std;

// Clase SocioClub
class SocioClub {
private:
    int numeroSocio;          // Número único de socio
    string nombre;            // Nombre del socio
    string domicilio;         // Domicilio del socio
    string fechaIngreso;      // Fecha de ingreso del socio

public:
    // Constructores
    SocioClub() : numeroSocio(0), nombre(""), domicilio(""), fechaIngreso("") {}

    SocioClub(int num, string nom, string dom, string fecha)
        : numeroSocio(num), nombre(nom), domicilio(dom), fechaIngreso(fecha) {}

    // Sobrecarga del operador '<<' para imprimir los datos de un socio
    friend ostream& operator<<(ostream& out, const SocioClub& socio) {
        out << "Número de socio: " << socio.numeroSocio << endl;
        out << "Nombre: " << socio.nombre << endl;
        out << "Domicilio: " << socio.domicilio << endl;
        out << "Fecha de ingreso: " << socio.fechaIngreso << endl;
        return out;
    }

    // Sobrecarga del operador '>>' para ingresar los datos de un socio
    friend istream& operator>>(istream& in, SocioClub& socio) {
        cout << "Número de socio: ";
        in >> socio.numeroSocio;
        in.ignore(); // Limpiar el buffer de entrada para evitar problemas con getline

        cout << "Nombre del socio: ";
        getline(in, socio.nombre);

        cout << "Domicilio del socio: ";
        getline(in, socio.domicilio);

        cout << "Fecha de ingreso: ";
        getline(in, socio.fechaIngreso);

        return in;
    }

    // Sobrecarga del operador '<' para ordenar por número de socio
    bool operator<(const SocioClub& otro) const {
        return numeroSocio < otro.numeroSocio;
    }

    // Sobrecarga del operador '==' para comparar por número de socio
    bool operator==(const SocioClub& otro) const {
        return numeroSocio == otro.numeroSocio;
    }

    // Métodos de acceso
    int getNumeroSocio() const {
        return numeroSocio;
    }

    string getNombre() const {
        return nombre;
    }

    string getDomicilio() const {
        return domicilio;
    }
};

// Nodo de la lista simplemente ligada
template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;

    Nodo(T valor) : dato(valor), siguiente(nullptr) {}
};

// Clase Lista simplemente ligada
template <typename T>
class Lista {
private:
    Nodo<T>* cabeza;

public:
    Lista() : cabeza(nullptr) {}

    // Insertar en la lista de manera ordenada
    bool insertarOrdenado(const T& valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (!cabeza || valor < cabeza->dato) { // Insertar al inicio si está vacía o es el menor
            nuevo->siguiente = cabeza;
            cabeza = nuevo;
            return true;
        }

        Nodo<T>* actual = cabeza;
        while (actual->siguiente && actual->siguiente->dato < valor) {
            actual = actual->siguiente;
        }

        if (actual->dato == valor) {
            delete nuevo; // Evitar duplicados (número de socio único)
            return false;
        }

        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
        return true;
    }

    // Eliminar un socio por número de socio
    bool eliminar(int numeroSocio) {
        if (!cabeza) return false; // Lista vacía

        if (cabeza->dato.getNumeroSocio() == numeroSocio) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return true;
        }

        Nodo<T>* actual = cabeza;
        while (actual->siguiente && actual->siguiente->dato.getNumeroSocio() != numeroSocio) {
            actual = actual->siguiente;
        }

        if (actual->siguiente) {
            Nodo<T>* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
            return true;
        }

        return false; // No se encontró el socio
    }

    // Buscar un socio por nombre y domicilio
    void buscar(string nombre, string domicilio) {
        Nodo<T>* actual = cabeza;
        while (actual) {
            if (actual->dato.getNombre() == nombre && actual->dato.getDomicilio() == domicilio) {
                cout << "Socio encontrado:" << endl;
                cout << actual->dato << endl;
                return;
            }
            actual = actual->siguiente;
        }
        cout << "Socio no encontrado." << endl;
    }

    // Mostrar todos los socios
    void mostrar() const {
        Nodo<T>* actual = cabeza;
        if (!actual) {
            cout << "No hay socios registrados." << endl;
        } else {
            while (actual) {
                cout << actual->dato << endl;
                actual = actual->siguiente;
            }
        }
    }

    // Contar el número de socios
    int contar() const {
        int total = 0;
        Nodo<T>* actual = cabeza;
        while (actual) {
            total++;
            actual = actual->siguiente;
        }
        return total;
    }
};

int main() {
    Lista<SocioClub> listaSocios;
    string opcion;
    int aux;
    do {
        cout << "Menú de opciones:" << endl;
        cout << "1. Registrar nuevo socio" << endl;
        cout << "2. Dar de baja un socio" << endl;
        cout << "3. Generar reporte de todos los socios" << endl;
        cout << "4. Buscar socio por nombre y domicilio" << endl;
        cout << "5. Calcular el total de socios" << endl;
        cout << "6. Salir" << endl;
        cout << "Elige una opción: ";
        cin >> opcion;

        cin.ignore(); // Limpiar el buffer de entrada

        aux = stoi(opcion);
        switch (aux) {
            case 1: {
                SocioClub nuevoSocio;
                cin >> nuevoSocio;
                if (listaSocios.insertarOrdenado(nuevoSocio)) {
                    cout << "Socio registrado correctamente." << endl;
                } else {
                    cout << "Error: Ya existe un socio con ese número." << endl;
                }
                break;
            }
            case 2: {
                int numeroSocio;
                cout << "Ingresa el número de socio a dar de baja: ";
                cin >> numeroSocio;
                if (listaSocios.eliminar(numeroSocio)) {
                    cout << "Socio eliminado correctamente." << endl;
                } else {
                    cout << "Error: No se encontró un socio con ese número." << endl;
                }
                break;
            }
            case 3:
                listaSocios.mostrar();
                break;
            case 4: {
                string nombre, domicilio;
                cout << "Ingresa el nombre del socio: ";
                getline(cin, nombre);
                cout << "Ingresa el domicilio del socio: ";
                getline(cin, domicilio);
                listaSocios.buscar(nombre, domicilio);
                break;
            }
            case 5:
                cout << "Total de socios registrados: " << listaSocios.contar() << endl;
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (aux != 6);

    return 0;
}
