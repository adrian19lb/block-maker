#include <block-maker/Physic/FixtureFactory/OBlock.hpp>

namespace bm::physic {

    OBlock::OBlock(ShapeFactoryPtr shapeFactory, Fixture fixture)
    : FileFixtureFactory<std::vector, float>( std::move(shapeFactory), fixture,
                                             std::make_unique<binder::XmlResource<std::vector, float>>("resources/xml/BlockPhysicAttributes.xml")) {
        appendShapesCoords( {"dot", "shapesPositions" } );
    }
}
