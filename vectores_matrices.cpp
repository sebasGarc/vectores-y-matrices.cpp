// Programa 1: Vectores y matrices en C++
import <iostream>;
import <vector>;
import <numeric>;
import <algorithm>;
import <iomanip>;
using namespace std;

using Matriz = vector<vector<int>>;

void imprimirMatriz(const Matriz& m, const string& nombre) {
    cout << nombre << ":\n";
    for (const auto& fila : m) {
        for (int x : fila) cout << setw(5) << x;
        cout << "\n";
    }
}

Matriz sumar(const Matriz& a, const Matriz& b) {
    Matriz r(a.size(), vector<int>(a[0].size()));
    for (size_t i = 0; i < a.size(); i++)
        for (size_t j = 0; j < a[0].size(); j++)
            r[i][j] = a[i][j] + b[i][j];
    return r;
}

Matriz multiplicar(const Matriz& a, const Matriz& b) {
    Matriz r(a.size(), vector<int>(b[0].size(), 0));
    for (size_t i = 0; i < a.size(); i++)
        for (size_t j = 0; j < b[0].size(); j++)
            for (size_t k = 0; k < b.size(); k++)
                r[i][j] += a[i][k] * b[k][j];
    return r;
}

Matriz transpuesta(const Matriz& a) {
    Matriz r(a[0].size(), vector<int>(a.size()));
    for (size_t i = 0; i < a.size(); i++)
        for (size_t j = 0; j < a[0].size(); j++)
            r[j][i] = a[i][j];
    return r;
}

int main() {
    // ---------- VECTORES ----------
    cout << "=== VECTORES ===\n";
    vector<int> v = {5, 3, 8, 1, 9, 2};
    v.push_back(7);

    cout << "Vector: ";
    for (int x : v) cout << x << " ";
    cout << "\nTamano: " << v.size() << endl;

    int suma = accumulate(v.begin(), v.end(), 0);
    cout << "Suma: " << suma << endl;
    cout << "Promedio: " << fixed << setprecision(2)
         << (double)suma / v.size() << endl;
    cout << "Maximo: " << *max_element(v.begin(), v.end()) << endl;
    cout << "Minimo: " << *min_element(v.begin(), v.end()) << endl;

    sort(v.begin(), v.end());
    cout << "Ordenado: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    // ---------- MATRICES ----------
    cout << "\n=== MATRICES ===\n";
    Matriz A = {{1, 2, 3}, {4, 5, 6}};
    Matriz B = {{7, 8, 9}, {10, 11, 12}};
    Matriz C = {{1, 2}, {3, 4}, {5, 6}};

    imprimirMatriz(A, "A (2x3)");
    imprimirMatriz(B, "B (2x3)");
    imprimirMatriz(C, "C (3x2)");
    imprimirMatriz(sumar(A, B), "A + B");
    imprimirMatriz(multiplicar(A, C), "A * C (2x2)");
    imprimirMatriz(transpuesta(A), "Transpuesta de A (3x2)");

    return 0;
}
