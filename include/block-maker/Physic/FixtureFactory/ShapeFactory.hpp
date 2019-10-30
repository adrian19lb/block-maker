#ifndef SHAPEFACTORY_HPP_INCLUDED
#define SHAPEFACTORY_HPP_INCLUDED

#include <memory>
#include <boost/variant.hpp>
#include <Box2D/Collision/Shapes/b2Shape.h>

namespace bm::physic {

    using ShapePtr = std::unique_ptr<b2Shape>;

    class ShapeFactory {
    public:
        virtual ShapePtr createShape(const b2Vec2& position) = 0;
        virtual boost::variant<float, b2Vec2> getSize() const = 0;
    };

    using ShapeFactoryPtr = std::unique_ptr<ShapeFactory>;
}
#endif // SHAPEFACTORY_HPP_INCLUDED
