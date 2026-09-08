
#ifndef TAREA3_PROGRAMACION3_ALGORITMO_H
#define TAREA3_PROGRAMACION3_ALGORITMO_H

#include "conceptos.h"

namespace core_numeric {
    template <Iterable C>
    requires Addable <typename C::value_type >
    auto sum ( const C & container ){
        using T = typename C :: value_type ;
        T result {};
        for ( const auto & value : container )
            result = result + value ;
        return result ;
    }

    template <Iterable C>
    requires Addable <typename C::value_type >
    auto mean (const C & container){
        auto total = sum(container);

        int count = 0;
        for ( const auto & value : container ) {
            count++;
        }

        return total/count;
    }
}



#endif //TAREA3_PROGRAMACION3_ALGORITMO_H
