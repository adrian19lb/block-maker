#include <block-maker/Physic/FixtureFactory/LBlock.hpp>

namespace bm::physic {

    LBlock::LBlock(ShapeFactoryPtr shapeFactory, Fixture fixture)
    : FileFixtureFactory<std::vector, float>( std::move(shapeFactory), fixture,
                                             std::make_unique<binder::XmlResource<std::vector, float>>("resources/xml/BlockPhysicAttributes.xml")) {
        appendShapesCoords( {"letterL", "shapesPositions" } );
    }
}
