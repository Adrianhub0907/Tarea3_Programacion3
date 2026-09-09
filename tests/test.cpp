#include <iostream>
#include <vector>
#include <string>
#include "../conceptos.h"
#include "../algoritmo.h"

using namespace std;
using namespace core_numeric;

struct Vectores3D {
    double x = 0.0, y = 0.0, z = 0.0;

    Vectores3D operator+(const Vectores3D& o) const {
        return {x + o.x, y + o.y, z + o.z};
    }
    Vectores3D operator-(const Vectores3D& o) const {
        return {x - o.x, y - o.y, z - o.z};
    }
    Vectores3D operator*(const Vectores3D& o) const {
        return {x * o.x, y * o.y, z * o.z};
    }
    Vectores3D operator/(size_t n) const {
        return {x / n, y / n, z / n};
    }
    bool operator<(const Vectores3D& o) const {
        return (x * x + y * y + z * z) < (o.x * o.x + o.y * o.y + o.z * o.z);
    }
};

struct Esfera {
    double radio = 0.0;
    bool operator<(const Esfera& otra) const {
        return radio < otra.radio;
    }
};

int main() {
    cout << "--- CASOS QUE COMPILAN CORRECTAMENTE ---\n";

    vector<double> v_double = {1.0, 2.0, 3.0, 4.0};
    vector<int> v_int = {1, 5, 3, 2};

    cout << "Suma (double): " << sum(v_double) << "\n";
    cout << "Mean (double): " << mean(v_double) << "\n";
    cout << "Variance (double): " << variance(v_double) << "\n";
    cout << "Max (int): " << max(v_int) << "\n";

    auto tr = transform_reduce(v_double, [](double x) { return x * x; });
    cout << "Transform Reduce: " << tr << "\n";

    cout << "Sum Variadic: " << sum_variadic(1, 2, 33, 4) << "\n";
    cout << "Mean Variadic: " << mean_variadic(0.1, 2.0, 3.0, 4.0) << "\n";
    cout << "Variance Variadic: " << variance_variadic(1.0, 2.0, 3.0, 4.0) << "\n";
    cout << "Max Variadic: " << max_variadic(1.0, 2.7, 3.0, 4.0) << "\n";

    vector<Vectores3D> v_vec = {{1, 0, 0}, {0, 2, 0}};
    auto vec_sum = sum(v_vec);
    auto vec_mean = mean(v_vec);
    cout << "Vectores3D Mean: (" << vec_mean.x << ", " << vec_mean.y << ", " << vec_mean.z << ")\n";

    vector<Esfera> esferas = {{1.5}, {3.0}, {0.5}};
    auto esf_max = max(esferas);
    cout << "Esfera Max Radio: " << esf_max.radio << "\n";


    cout << "CASOS QUE NO COMPILAN (VER COMENTARIOS EN CODIGO)";

    vector<string> palabras = {"hola", "mundo"};

    /*
    // FALLO 1: string no cumple con Divisible
    // Explicacion: string no tiene definido el operador '/' con size_t.
    // El concept Divisible falla en la restricción del algoritmo mean.
    auto m_str = mean(palabras);
    */

    /*
    // FALLO 2: string no cumple los concepts requeridos por variance
    // Explicacion: Falla el concept Subtractable ya que no se pueden restar strings (operador '-' no definido).
    auto v_str = variance(palabras);
    */

    /*
    // FALLO 3: Esfera no cumple Addable en sum()
    // Explicacion: La estructura Esfera no tiene implementado el operator+ sobrecargado.
    auto esf_sum = sum(esferas);
    */

    /*
    // FALLO 4: Int con objeto no compatible en variadic
    // Explicacion: No se pueden sumar tipos heterogeneos que no tengan conversion o el concept Addable unificado.
    auto err_var = sum_variadic("texto", 123);
    */

    return 0;
}