#include <block-maker/Physic/FixtureFactory/HalfPlusBlock.hpp>

namespace bm::physic {

    HalfPlusBlock::HalfPlusBlock(ShapeFactoryPtr shapeFactory, Fixture fixture)
    : FileFixtureFactory<std::vector, float>( std::move(shapeFactory), fixture,
                                             std::make_unique<binder::XmlResource<std::vector, float>>("resources/xml/BlockPhysicAttributes.xml")) {
        appendShapesCoords( {"halfPlus", "shapesPositions" } );
    }
}
