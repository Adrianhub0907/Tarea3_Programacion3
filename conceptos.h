#ifndef TAREA3_PROGRAMACION3_CONCEPTOS_H
#define TAREA3_PROGRAMACION3_CONCEPTOS_H

#include <concepts>
#include <iterator>

using namespace std;

namespace core_numeric {

    template <typename C>
    concept Iterable = requires(C c) {
        begin(c);
        end(c);
    };

    template <typename T>
    concept Addable = requires(T a, T b) {
        { a + b } -> same_as<T>;
    };

    template <typename T>
    concept Divisible = requires(T a, size_t n) {
        { a / n } -> same_as<T>;
    };

    // Concept personalizado adicional
    template <typename T>
    concept Subtractable = requires(T a, T b) {
        { a - b } -> same_as<T>;
    };

    template <typename T>
    concept Comparable = requires(T a, T b) {
        { a < b } -> same_as<bool>;
    };

}

#endif // TAREA3_PROGRAMACION3_CONCEPTOS_H