#include <block-maker/Physic/FixtureFactory/IBlock.hpp>

namespace bm::physic {

    IBlock::IBlock(ShapeFactoryPtr shapeFactory, Fixture fixture)
    : FileFixtureFactory<std::vector, float>( std::move(shapeFactory), fixture,
                                             std::make_unique<binder::XmlResource<std::vector, float>>("resources/xml/BlockPhysicAttributes.xml")) {
        appendShapesCoords( {"letterI", "shapesPositions" } );
    }
}
