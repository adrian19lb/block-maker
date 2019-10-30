#ifndef SHAPEPOSITIONSCALER_HPP_INCLUDED
#define SHAPEPOSITIONSCALER_HPP_INCLUDED

#include <boost/variant.hpp>
#include <SFML/System/Vector2.hpp>
#include <Box2D/Common/b2Math.h>

namespace bm::physic {

    template<typename T>
    class ShapePositionScaler : public boost::static_visitor<T> {
    public:
        ShapePositionScaler(const T& attribute);
        ShapePositionScaler() = delete;
        ~ShapePositionScaler() = default;
        T operator()(float radius);
        T operator()(const b2Vec2& rectSize);
        template<typename R>
        T operator()(const sf::Vector2<R>& rectSize);
    private:
        T shapePosition;
    };
}

#include <block-maker/Physic/ShapePositionScaler.inl>

#endif // SHAPEPOSITIONSCALER_HPP_INCLUDED
