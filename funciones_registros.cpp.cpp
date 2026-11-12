// Programa 2: Funciones y registros (struct) en C++
import <iostream>;
import <vector>;
import <string>;
import <iomanip>;
using namespace std;

// Registro (struct) que representa un estudiante
struct Estudiante {
    int id;
    string nombre;
    int edad;
    double notas[3];
};

// Funcion: calcula el promedio de un estudiante
double promedio(const Estudiante& e) {
    return (e.notas[0] + e.notas[1] + e.notas[2]) / 3.0;
}

// Funcion: devuelve si aprobo (>= 3.0)
bool aprobo(const Estudiante& e) {
    return promedio(e) >= 3.0;
}

// Funcion: imprime un registro
void mostrar(const Estudiante& e) {
    cout << left << setw(4) << e.id << setw(10) << e.nombre
         << setw(6) << e.edad << fixed << setprecision(2)
         << setw(10) << promedio(e)
         << (aprobo(e) ? "Aprobado" : "Reprobado") << "\n";
}

// Funcion: busca un estudiante por id (retorna puntero o nullptr)
const Estudiante* buscar(const vector<Estudiante>& lista, int id) {
    for (const auto& e : lista)
        if (e.id == id) return &e;
    return nullptr;
}

// Funcion: paso por referencia para modificar el registro
void corregirNota(Estudiante& e, int indice, double nuevaNota) {
    e.notas[indice] = nuevaNota;
}

// Funcion recursiva: factorial
long long factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    vector<Estudiante> curso = {
        {1, "Ana",    20, {4.5, 3.8, 4.0}},
        {2, "Luis",   22, {2.5, 3.0, 2.8}},
        {3, "Maria",  19, {5.0, 4.7, 4.9}},
        {4, "Carlos", 21, {3.0, 2.0, 3.5}}
    };

    cout << left << setw(4) << "ID" << setw(10) << "Nombre"
         << setw(6) << "Edad" << setw(10) << "Promedio" << "Estado\n";
    cout << string(40, '-') << "\n";
    for (const auto& e : curso) mostrar(e);

    cout << "\nBuscando estudiante con id 3...\n";
    if (const Estudiante* e = buscar(curso, 3))
        cout << "Encontrado: " << e->nombre << "\n";

    cout << "\nCorrigiendo nota de Luis (nota 1 -> 4.0)...\n";
    corregirNota(curso[1], 0, 4.0);
    mostrar(curso[1]);

    cout << "\nFactorial de 5 (recursiva): " << factorial(5) << "\n";
    return 0;
}
