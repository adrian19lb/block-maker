#ifndef NBLOCK_HPP_INCLUDED
#define NBLOCK_HPP_INCLUDED

#include <block-maker/Physic/FixtureFactory/FileFixtureFactory.hpp>
#include <block-maker/Loader/Xml/Xml.hpp>
#include <block-maker/Resource/Binder/XmlResource.hpp>

namespace bm::physic {

    class NBlock : public FileFixtureFactory<std::vector, float> {
    public:
        NBlock(ShapeFactoryPtr shapeFactory, Fixture fixture);
        ~NBlock() = default;

    };
}

#endif // NBLOCK_HPP_INCLUDED
