#include <iostream>
#include <string>
using namespace std;

const int MAX = 100; // Definimos el tama�o m�ximo de la pila

class Empleado {
public:
    int clave;
    string nombre;
    string domicilio;
    float sueldo;
    string reportaA;

    // Constructor
    Empleado() : clave(0), nombre(""), domicilio(""), sueldo(0.0), reportaA("") {}
    // M�todos adicionales pueden definirse aqu�
};

template <typename T>
class Pila {
private:
    T datos[MAX];
    int tam;

public:
    Pila() : tam(0) {}  // Inicializamos la pila como vac�a

    bool llena() const {
        return tam == MAX;
    }

    bool vacia() const {
        return tam == 0;
    }

    bool push(const T& elemento) {
        if (llena()) {
            return false; // La pila est� llena, no se puede agregar m�s elementos
        }
        datos[tam++] = elemento;
        return true;
    }

    bool pop() {
        if (vacia()) {
            return false; // La pila est� vac�a, no se puede eliminar ning�n elemento
        }
        tam--;  // Disminuye el tama�o, quitando el �ltimo elemento
        return true;
    }

    T top() const {
        if (!vacia()) {
            return datos[tam - 1]; // Retorna el elemento en la cima de la pila
        }
        throw out_of_range("La pila est� vac�a");
    }

    void muestraTop() const {
        if (!vacia()) {
            T elemento = top();
            cout << "Empleado en la cima de la pila: " << endl;
            cout << "Clave: " << elemento.clave << endl;
            cout << "Nombre: " << elemento.nombre << endl;
            cout << "Domicilio: " << elemento.domicilio << endl;
            cout << "Sueldo: " << elemento.sueldo << endl;
            cout << "Reporta a: " << elemento.reportaA << endl;
        } else {
            cout << "La pila est� vac�a." << endl;
        }
    }
};
int main() {
    Pila<Empleado> pila;
    int opcion;

    do {
        cout << "Menu de opciones: " << endl;
        cout << "1. Push (Apilar Empleado)" << endl;
        cout << "2. Pop (Desapilar Empleado)" << endl;
        cout << "3. Top (Ver Empleado en la cima)" << endl;
        cout << "4. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Empleado emp;
                cout << "Ingresa la clave del empleado: ";
                cin >> emp.clave;
                cout << "Ingresa el nombre del empleado: ";
                cin.ignore();
                getline(cin, emp.nombre);
                cout << "Ingresa el domicilio del empleado: ";
                getline(cin, emp.domicilio);
                cout << "Ingresa el sueldo del empleado: ";
                cin >> emp.sueldo;
                cout << "Ingresa el nombre de la persona a quien reporta: ";
                cin.ignore();
                getline(cin, emp.reportaA);

                if (pila.push(emp)) {
                    cout << "Empleado apilado exitosamente." << endl;
                } else {
                    cout << "Error: La pila est� llena." << endl;
                }
                break;
            }
            case 2: {
                if (pila.pop()) {
                    cout << "Empleado desapilado exitosamente." << endl;
                } else {
                    cout << "Error: La pila est� vac�a." << endl;
                }
                break;
            }
            case 3: {
                pila.muestraTop();
                break;
            }
            case 4: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default:
                cout << "Opci�n inv�lida. Por favor, elige una opci�n v�lida." << endl;
        }
    } while (opcion != 4);

    return 0;
}
