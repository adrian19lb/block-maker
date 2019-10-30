#ifndef COORDTRANSFROMER_HPP_INCLUDED
#define COORDTRANSFROMER_HPP_INCLUDED

#include <memory>

namespace bm::transformer {

    template<typename T>
    class CoordTransformer {
    public:
        virtual T transformToGlobalCoord(const T& localCoord) = 0;
        virtual T transformToGlobalCoord(float x, float y) = 0;
    };

    template<typename T>
    using CoordTransformerPtr = std::unique_ptr<CoordTransformer<T>>;

}

#endif // COORDTRANSFROMER_HPP_INCLUDED
