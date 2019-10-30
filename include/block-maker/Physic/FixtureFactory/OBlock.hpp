#ifndef OBLOCK_HPP_INCLUDED
#define OBLOCK_HPP_INCLUDED

#include <block-maker/Physic/FixtureFactory/FileFixtureFactory.hpp>
#include <block-maker/Loader/Xml/Xml.hpp>
#include <block-maker/Resource/Binder/XmlResource.hpp>

namespace bm::physic {

    class OBlock : public FileFixtureFactory<std::vector, float> {
    public:
        OBlock(ShapeFactoryPtr shapeFactory, Fixture fixture);
        ~OBlock() = default;
    };
}

#endif // OBLOCK_HPP_INCLUDED
