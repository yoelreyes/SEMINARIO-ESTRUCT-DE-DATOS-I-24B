#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;  // Tama�o m�ximo de la lista

class Empleado {
private:
    int claveEmpleado;
    string nombre;
    string domicilio;
    double sueldo;
    string reportaA;

public:
    // Constructor de la clase Empleado
    Empleado(int clave = 0, string nom = "", string dom = "", double sue = 0.0, string rep = "")
        : claveEmpleado(clave), nombre(nom), domicilio(dom), sueldo(sue), reportaA(rep) {}

    // Sobrecarga del operador de comparaci�n ==
    bool operator==(const Empleado& e) const {
        return claveEmpleado == e.claveEmpleado;  // Comparaci�n por clave
    }

    // M�todo para imprimir los datos del empleado
    void imprime() const {
        cout << "Clave: " << claveEmpleado << ", Nombre: " << nombre
             << ", Domicilio: " << domicilio << ", Sueldo: " << sueldo
             << ", Reporta a: " << reportaA << endl;
    }

    // Getters
    int getClaveEmpleado() const {
        return claveEmpleado;
    }
};

template <typename T>
class ListaEstatica {
private:
    T datos[MAX];
    int tam;

public:
    ListaEstatica() : tam(0) {}

    // M�todo para insertar un elemento en una posici�n espec�fica
    int Inserta(T elemento, int pos) {
        if (Llena()) {
            return -1;  // Lista llena
        }
        if (pos < 0 || pos > tam) {
            return -1;  // Posici�n inv�lida
        }
        for (int i = tam; i > pos; i--) {
            datos[i] = datos[i - 1];
        }
        datos[pos] = elemento;
        tam++;
        return 0;  // Inserci�n exitosa
    }

    // M�todo para agregar un elemento al final de la lista
    int Agrega(T elemento) {
        if (Llena()) {
            return -1;  // Lista llena
        }
        datos[tam++] = elemento;
        return 0;  // Agregado exitosamente
    }

    // M�todo para buscar un elemento en la lista
    int Busca(T elemento) const {
        if (Vacia()) {
            return -1;  // Lista vac�a
        }
        for (int i = 0; i < tam; i++) {
            if (datos[i] == elemento) {
                return i;  // Retorna la posici�n del elemento encontrado
            }
        }
        return -1;  // No se encontr� el elemento
    }

    // M�todo para eliminar un elemento en una posici�n espec�fica
    int Elimina(int pos) {
        if (Vacia() || pos < 0 || pos >= tam) {
            return -1;  // Lista vac�a o posici�n inv�lida
        }
        for (int i = pos; i < tam - 1; i++) {
            datos[i] = datos[i + 1];
        }
        tam--;
        return 0;  // Eliminaci�n exitosa
    }

    // M�todo para verificar si la lista est� vac�a
    int Vacia() const {
        return tam == 0;
    }

    // M�todo para verificar si la lista est� llena
    int Llena() const {
        return tam == MAX;
    }

    // M�todo para mostrar todos los elementos de la lista
    int Muestra() const {
        if (Vacia()) {
            cout << "La lista esta vacia." << endl;
            return -1;
        }
        for (int i = 0; i < tam; i++) {
            cout << "Posicion " << i << ": ";
            datos[i].imprime();
        }
        return 0;
    }
};

int main() {
    ListaEstatica<Empleado> lista;
    int opcion;

    do {
        cout << "Menu:\n";
        cout << "1. Agrega\n";
        cout << "2. Buscar\n";
        cout << "3. Elimina\n";
        cout << "4. Inserta\n";
        cout << "5. Muestra\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {  // Agrega
            int clave;
            string nombre, domicilio, reportaA;
            double sueldo;
            cout << "Ingrese clave, nombre, domicilio, sueldo, reportaA: ";
            cin >> clave >> nombre >> domicilio >> sueldo >> reportaA;
            Empleado emp(clave, nombre, domicilio, sueldo, reportaA);
            if (lista.Agrega(emp) == -1) {
                cout << "No se pudo agregar, la lista est� llena.\n";
            }
            break;
        }
        case 2: {  // Buscar
            int clave;
            cout << "Ingrese la clave del empleado a buscar: ";
            cin >> clave;
            Empleado emp(clave);
            int pos = lista.Busca(emp);
            if (pos == -1) {
                if (lista.Vacia()) {
                    cout << "La lista est� vacia.\n";
                } else {
                    cout << "No se encontr� el empleado.\n";
                }
            } else {
                cout << "Empleado encontrado en la posicion: " << pos << endl;
            }
            break;
        }
        case 3: {  // Elimina
            int pos;
            cout << "Ingrese la posicion a eliminar: ";
            cin >> pos;
            if (lista.Elimina(pos) == -1) {
                cout << "Posicion invalida o lista vacia.\n";
            }
            break;
        }
        case 4: {  // Inserta
            int clave, pos;
            string nombre, domicilio, reportaA;
            double sueldo;
            cout << "Ingrese clave, nombre, domicilio, sueldo, reportaA, posicion: ";
            cin >> clave >> nombre >> domicilio >> sueldo >> reportaA >> pos;
            Empleado emp(clave, nombre, domicilio, sueldo, reportaA);
            if (lista.Inserta(emp, pos) == -1) {
                cout << "No se pudo insertar. Lista llena o posicion invalida.\n";
            }
            break;
        }
        case 5: {  // Muestra
            lista.Muestra();
            break;
        }
        case 6:  // Salir
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opci�n no v�lida. Intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}

