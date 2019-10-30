#ifndef RECTSHAPEFACTORY_HPP_INCLUDED
#define RECTSHAPEFACTORY_HPP_INCLUDED

#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <block-maker/Physic/FixtureFactory/ShapeFactory.hpp>

namespace bm::physic {

    class RectShapeFactory : public ShapeFactory {
    public:
        RectShapeFactory(b2Vec2&& size);
        ShapePtr createShape(const b2Vec2& position) override;
        boost::variant<float, b2Vec2> getSize() const override;
        void setSize(const b2Vec2& size);
    private:
        b2Vec2 mSize;
    };
}

#endif // RECTSHAPEFACTORY_HPP_INCLUDED
