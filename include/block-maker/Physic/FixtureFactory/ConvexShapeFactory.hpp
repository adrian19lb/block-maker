#ifndef CONVEXSHAPEFACTORY_HPP_INCLUDED
#define CONVEXSHAPEFACTORY_HPP_INCLUDED

#include "ShapeFactory.hpp"
#include "../ShapeFactoryVisitor.hpp"

namespace bm::physic {

    class ConvexShapeFactory : public ShapeFactory {
    public:
        ConvexShapeFactory(float32 radius, int32 verticesNumber);
        ShapePtr createShape(const b2Vec2& position) override;
        boost::variant<float, b2Vec2> getSize() const {
            return radius;
        }
    private:
        float32 radius;
        int32 verticesNumber;
    };
}


#endif // CONVEXSHAPEFACTORY_HPP_INCLUDED
