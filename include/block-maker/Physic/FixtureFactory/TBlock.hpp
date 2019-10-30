#ifndef TBLOCK_HPP_INCLUDED
#define TBLOCK_HPP_INCLUDED

#include <block-maker/Physic/FixtureFactory/FileFixtureFactory.hpp>
#include <block-maker/Loader/Xml/Xml.hpp>
#include <block-maker/Resource/Binder/XmlResource.hpp>

namespace bm::physic {

    class TBlock : public FileFixtureFactory<std::vector, float> {
    public:
        TBlock(ShapeFactoryPtr shapeFactory, Fixture fixture);
        ~TBlock() = default;
    };
}

#endif // TBLOCK_HPP_INCLUDED
