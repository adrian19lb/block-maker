#include <block-maker/Physic/FixtureFactory/TBlock.hpp>

namespace bm::physic {

    TBlock::TBlock(ShapeFactoryPtr shapeFactory, Fixture fixture)
    : FileFixtureFactory<std::vector, float>( std::move(shapeFactory), fixture,
                                             std::make_unique<binder::XmlResource<std::vector, float>>("resources/xml/BlockPhysicAttributes.xml")) {
        appendShapesCoords( {"letterT", "shapesPositions" } );
    }
}
