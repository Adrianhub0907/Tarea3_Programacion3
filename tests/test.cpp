#include <iostream>
#include <vector>
#include "../conceptos.h"
#include "../algoritmo.h"

struct Coordenadas {
    double x = 0.0;
    double y = 0.0;
    Coordenadas operator+(const Coordenadas& otra) const {
        return {x + otra.x, y + otra.y};
    }
};

int main() {

    std::vector<double> numeros = {10.5, 20.0, 30.5};

    auto suma_num = core_numeric::sum(numeros);

    auto prom_num = core_numeric::mean(numeros);

    std::vector<Coordenadas> puntos = {{1.0, 2.0}, {3.0, 4.0}};
    auto suma_puntos = core_numeric::sum(puntos);

    std::cout << "Las pruebas validas compilaron correctamente.\n";


    return 0;
}
