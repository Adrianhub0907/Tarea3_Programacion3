
#ifndef TAREA3_PROGRAMACION3_CONCEPTOS_H
#define TAREA3_PROGRAMACION3_CONCEPTOS_H

#include <concepts>
#include <iterator>

namespace core_numeric {
    template <typename C>
    concept Iterable = requires(C c) {
        std::begin (c);
        std::end (c);
    };
    template <typename T >
    concept Addable = requires(T a , T b ) {
        { a + b } -> std::same_as <T>;
    };
    template <typename T>
    concept Divisible = requires(T a , std::size_t n ) {
        { a / n } -> std::same_as <T>;
    };
    //extra
    template <typename T>
        concept Subtractable = requires(T a , T b ) {
        { a - b } -> std::same_as <T>;
        };
}

#endif //TAREA3_PROGRAMACION3_CONCEPTOS_H
