#ifndef PLUSBLOCK_HPP_INCLUDED
#define PLUSBLOCK_HPP_INCLUDED

#include <block-maker/Physic/FixtureFactory/FileFixtureFactory.hpp>
#include <block-maker/Loader/Xml/Xml.hpp>
#include <block-maker/Resource/Binder/XmlResource.hpp>

namespace bm::physic {

    class PlusBlock : public FileFixtureFactory<std::vector, float> {
    public:
        PlusBlock(ShapeFactoryPtr shapeFactory, Fixture fixture);
        ~PlusBlock() = default;
    };
}

#endif // PLUSBLOCK_HPP_INCLUDED
