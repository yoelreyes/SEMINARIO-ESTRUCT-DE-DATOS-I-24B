#include <iostream>
#include <string>
using namespace std;

class Empleado {
private:
    int claveEmpleado;
    string nombre;
    string domicilio;
    double sueldo;
    string reportaA;

public:
    // Constructor
    Empleado(int clave, string nom, string dom, double sueldo, string reporta)
        : claveEmpleado(clave), nombre(nom), domicilio(dom), sueldo(sueldo), reportaA(reporta) {}

    // Métodos
    void imprime() {
        cout << "Clave del Empleado: " << claveEmpleado << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Domicilio: " << domicilio << endl;
        cout << "Sueldo: " << sueldo << endl;
        cout << "Reporta a: " << reportaA << endl;
    }

    void cambiaDomicilio(string nuevoDomicilio) {
        domicilio = nuevoDomicilio;
    }

    void cambiaReportaA(string nuevoReportaA) {
        reportaA = nuevoReportaA;
    }

    void actualizaSueldo(double porcentajeIncremento) {
        sueldo += sueldo * (porcentajeIncremento / 100.0);
    }

    int getClaveEmpleado() {
        return claveEmpleado;
    }
};

// Función principal
int main() {
    Empleado JefePlanta(1, "Carlos Martinez", "Av. Siempre Viva 123", 50000, "Director General");
    Empleado JefePersonal(2, "Maria Lopez", "Calle Falsa 456", 45000, "Subdirector General");

    int opcion;
    do {
        cout << "Menu de opciones:" << endl;
        cout << "1. Cambiar domicilio" << endl;
        cout << "2. Actualizar sueldo" << endl;
        cout << "3. Imprimir datos de un empleado" << endl;
        cout << "4. Cambiar la persona a quien reporta" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int clave;
            string nuevoDomicilio;
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;
            cout << "Ingrese el nuevo domicilio: ";
            cin.ignore();
            getline(cin, nuevoDomicilio);

            if (clave == JefePlanta.getClaveEmpleado()) {
                JefePlanta.cambiaDomicilio(nuevoDomicilio);
            } else if (clave == JefePersonal.getClaveEmpleado()) {
                JefePersonal.cambiaDomicilio(nuevoDomicilio);
            } else {
                cout << "Clave del empleado no encontrada." << endl;
            }
            break;
        }
        case 2: {
            int clave;
            double porcentaje;
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;
            cout << "Ingrese el porcentaje de incremento: ";
            cin >> porcentaje;

            if (clave == JefePlanta.getClaveEmpleado()) {
                JefePlanta.actualizaSueldo(porcentaje);
            } else if (clave == JefePersonal.getClaveEmpleado()) {
                JefePersonal.actualizaSueldo(porcentaje);
            } else {
                cout << "Clave del empleado no encontrada." << endl;
            }
            break;
        }
        case 3: {
            int clave;
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;

            if (clave == JefePlanta.getClaveEmpleado()) {
                JefePlanta.imprime();
            } else if (clave == JefePersonal.getClaveEmpleado()) {
                JefePersonal.imprime();
            } else {
                cout << "Clave del empleado no encontrada." << endl;
            }
            break;
        }
        case 4: {
            int clave;
            string nuevoReportaA;
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;
            cout << "Ingrese el nuevo nombre de la persona a quien reporta: ";
            cin.ignore();
            getline(cin, nuevoReportaA);

            if (clave == JefePlanta.getClaveEmpleado()) {
                JefePlanta.cambiaReportaA(nuevoReportaA);
            } else if (clave == JefePersonal.getClaveEmpleado()) {
                JefePersonal.cambiaReportaA(nuevoReportaA);
            } else {
                cout << "Clave del empleado no encontrada." << endl;
            }
            break;
        }
        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
        }
    } while (opcion != 5);

    return 0;
}
