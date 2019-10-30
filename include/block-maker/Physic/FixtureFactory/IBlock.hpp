#ifndef IBLOCK_HPP_INCLUDED
#define IBLOCK_HPP_INCLUDED

#include <block-maker/Physic/FixtureFactory/FileFixtureFactory.hpp>
#include <block-maker/Loader/Xml/Xml.hpp>
#include <block-maker/Resource/Binder/XmlResource.hpp>

namespace bm::physic {

    class IBlock : public FileFixtureFactory<std::vector, float> {
    public:
        IBlock(ShapeFactoryPtr shapeFactory, Fixture fixture);
        ~IBlock() = default;
    };
}

#endif // IBLOCK_HPP_INCLUDED
