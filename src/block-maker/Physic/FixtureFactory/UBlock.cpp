#include <block-maker/Physic/FixtureFactory/UBlock.hpp>

namespace bm::physic {

    UBlock::UBlock(ShapeFactoryPtr shapeFactory, Fixture fixture)
    : FileFixtureFactory<std::vector, float>( std::move(shapeFactory), fixture,
                                             std::make_unique<binder::XmlResource<std::vector, float>>("resources/xml/BlockPhysicAttributes.xml")) {
        appendShapesCoords( {"letterU", "shapesPositions" } );
    }
}
