#ifndef UBLOCK_HPP_INCLUDED
#define UBLOCK_HPP_INCLUDED

#include <block-maker/Physic/FixtureFactory/FileFixtureFactory.hpp>
#include <block-maker/Loader/Xml/Xml.hpp>
#include <block-maker//Resource/Binder/XmlResource.hpp>

namespace bm::physic {

    class UBlock : public FileFixtureFactory<std::vector, float> {
    public:
        UBlock(ShapeFactoryPtr shapeFactory, Fixture fixture);
        ~UBlock() = default;
    };
}

#endif // UBLOCK_HPP_INCLUDED
