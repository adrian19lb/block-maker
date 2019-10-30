#include <block-maker/Physic/FixtureFactory/NBlock.hpp>

namespace bm::physic {

    NBlock::NBlock(ShapeFactoryPtr shapeFactory, Fixture fixture)
    : FileFixtureFactory<std::vector, float>( std::move(shapeFactory), fixture,
                                             std::make_unique<binder::XmlResource<std::vector, float>>("resources/xml/BlockPhysicAttributes.xml")) {
        appendShapesCoords( {"letterN", "shapesPositions" } );
    }
}
