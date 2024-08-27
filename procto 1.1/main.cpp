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
    Empleado(int clave = 0, string nom = "", string dom = "", double suel = 0.0, string rep = "")
        : claveEmpleado(clave), nombre(nom), domicilio(dom), sueldo(suel), reportaA(rep) {}

    // Sobrecarga de operadores
    bool operator==(const Empleado& otro) const {
        return claveEmpleado == otro.claveEmpleado;
    }

    bool operator!=(const Empleado& otro) const {
        return !(*this == otro);
    }

    bool operator<(const Empleado& otro) const {
        return sueldo < otro.sueldo;
    }

    bool operator>(const Empleado& otro) const {
        return sueldo > otro.sueldo;
    }

    Empleado operator+(const Empleado& otro) const {
        return Empleado(claveEmpleado + otro.claveEmpleado,
                        nombre + " & " + otro.nombre,
                        domicilio + " / " + otro.domicilio,
                        sueldo + otro.sueldo,
                        reportaA + " & " + otro.reportaA);
    }

    // Sobrecarga de operadores de entrada/salida
    friend ostream& operator<<(ostream& os, const Empleado& emp) {
        os << "Clave del Empleado: " << emp.claveEmpleado << "\n"
           << "Nombre: " << emp.nombre << "\n"
           << "Domicilio: " << emp.domicilio << "\n"
           << "Sueldo: " << emp.sueldo << "\n"
           << "Reporta a: " << emp.reportaA << "\n";
        return os;
    }

    friend istream& operator>>(istream& is, Empleado& emp) {
        cout << "Ingrese la clave del empleado: ";
        is >> emp.claveEmpleado;
        is.ignore();  // Limpiar el buffer de entrada
        cout << "Ingrese el nombre del empleado: ";
        getline(is, emp.nombre);
        cout << "Ingrese el domicilio del empleado: ";
        getline(is, emp.domicilio);
        cout << "Ingrese el sueldo del empleado: ";
        is >> emp.sueldo;
        is.ignore();  // Limpiar el buffer de entrada
        cout << "Ingrese a quien reporta el empleado: ";
        getline(is, emp.reportaA);
        return is;
    }

    // Métodos adicionales
    void imprime() const {
        cout << *this;  // Usa la sobrecarga del operador <<
    }

    void cambiaDomicilio(const string& nuevoDomicilio) {
        domicilio = nuevoDomicilio;
    }

    void cambiaReportaA(const string& nuevoReportaA) {
        reportaA = nuevoReportaA;
    }

    void actualizaSueldo(double porcentajeIncremento) {
        sueldo += sueldo * (porcentajeIncremento / 100.0);
    }

    int getClaveEmpleado() const {
        return claveEmpleado;
    }
};

// Función principal
int main() {
    Empleado JefePlanta(1, "Carlos Martinez", "Av. Revo 123", 50000, "Director General");
    Empleado JefePersonal(2, "Maria Lopez", "Calle  456", 45000, "Subdirector General");

    int opcion;
    do {
        cout << "\nMenu de opciones:" << endl;
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

