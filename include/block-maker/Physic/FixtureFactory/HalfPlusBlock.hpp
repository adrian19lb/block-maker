#ifndef HALFPLUSBLOCK_HPP_INCLUDED
#define HALFPLUSBLOCK_HPP_INCLUDED

#include <block-maker/Physic/FixtureFactory/FileFixtureFactory.hpp>
#include <block-maker/Loader/Xml/Xml.hpp>
#include <block-maker//Resource/Binder/XmlResource.hpp>

namespace bm::physic {

    class HalfPlusBlock : public FileFixtureFactory<std::vector, float> {
    public:
        HalfPlusBlock(ShapeFactoryPtr shapeFactory, Fixture fixture);
        ~HalfPlusBlock() = default;

    };
}

#endif // HALFPLUSBLOCK_HPP_INCLUDED
