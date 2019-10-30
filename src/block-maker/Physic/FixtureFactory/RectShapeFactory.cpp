#include <block-maker/Physic/FixtureFactory/RectShapeFactory.hpp>

namespace bm::physic {

    RectShapeFactory::RectShapeFactory(b2Vec2&& size)
    : mSize{ std::move(size) } {
    }

    boost::variant<float, b2Vec2> RectShapeFactory::getSize() const {
        return mSize;
    }

    ShapePtr RectShapeFactory::createShape(const b2Vec2& position) {
        auto shape = std::make_unique<b2PolygonShape>();
        shape->SetAsBox(mSize.x/2, mSize.y/2, position, 0.f );

        return std::move(shape);
    }
}
