#include <block-maker/Physic/FixtureFactory/PlusBlock.hpp>

namespace bm::physic {

    PlusBlock::PlusBlock(ShapeFactoryPtr shapeFactory, Fixture fixture)
    : FileFixtureFactory<std::vector, float>( std::move(shapeFactory), fixture,
                                             std::make_unique<binder::XmlResource<std::vector, float>>("resources/xml/BlockPhysicAttributes.xml")) {
        appendShapesCoords( {"plus", "shapesPositions" } );
    }
}
