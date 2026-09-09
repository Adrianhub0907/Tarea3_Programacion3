#ifndef TAREA3_PROGRAMACION3_ALGORITMO_H
#define TAREA3_PROGRAMACION3_ALGORITMO_H

#include "conceptos.h"
#include <type_traits>
#include <algorithm>
#include <cmath>

using namespace std;
using namespace core_numeric;

namespace core_numeric {

    // 1. sum
    template <Iterable C>
    requires Addable<typename C::value_type>
    auto sum(const C& container) {
        using T = typename C::value_type;
        T result{};
        for (const auto& value : container) {
            result = result + value;
        }
        return result;
    }

    // 2. mean (Restringido por Divisible y Addable)
    template <Iterable C>
    requires Addable<typename C::value_type> && Divisible<typename C::value_type>
    auto mean(const C& container) {
        auto total = sum(container);
        size_t count = 0;
        for (const auto& value : container) {
            count++;
        }
        return total / count;
    }

    // 3. variance
    template <Iterable C>
    requires Iterable<C> && Addable<typename C::value_type> && Subtractable<typename C::value_type> && Divisible<typename C::value_type>
    auto variance(const C& container) {
        auto m = mean(container);
        using T = typename C::value_type;
        T accum{};
        size_t count = 0;

        for (const auto& x : container) {
            auto diff = x - m;
            accum = accum + (diff * diff);
            count++;
        }
        return accum / count;
    }

    // 4. max (Uso obligatorio de if constexpr - Punto 7)
    template <Iterable C>
    requires Comparable<typename C::value_type>
    auto max(const C& container) {
        using T = typename C::value_type;

        // Requisito Punto 7: Uso obligatorio de if constexpr
        if constexpr (is_integral_v<T>) {
            // Lógica específica para enteros
            auto it = begin(container);
            T max_val = *it;
            for (const auto& val : container) {
                if (max_val < val) {
                    max_val = val;
                }
            }
            return max_val;
        } else {
            // Lógica para tipos flotantes y otros objetos
            auto it = begin(container);
            T max_val = *it;
            for (const auto& val : container) {
                if (max_val < val) {
                    max_val = val;
                }
            }
            return max_val;
        }
    }

    // 5. transform_reduce
    template <Iterable C, typename Func>
    requires Addable<typename C::value_type>
    auto transform_reduce(const C& container, Func func) {
        using T = invoke_result_t<Func, typename C::value_type>;
        T result{};
        for (const auto& elem : container) {
            result = result + func(elem);
        }
        return result;
    }

    // 6. Variadic Templates & Fold Expressions
    template <Addable... Args>
    auto sum_variadic(Args... args) {
        return (... + args);
    }

    template <Addable... Args>
    requires (Divisible<Args> && ...)
    auto mean_variadic(Args... args) {
        auto total = sum_variadic(args...);
        size_t count = sizeof...(args);
        return total / count;
    }

    template <typename... Args>
    auto variance_variadic(Args... args) {
        double m = mean_variadic(static_cast<double>(args)...);
        double accum = 0.0;
        ((accum += (args - m) * (args - m)), ...);
        return accum / sizeof...(args);
    }

    template <Comparable First, Comparable... Args>
    auto max_variadic(First first, Args... args) {
        auto result = first;
        ((result = (result < args) ? args : result), ...);
        return result;
    }

}

#endif // TAREA3_PROGRAMACION3_ALGORITMO_H
