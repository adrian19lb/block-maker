#ifndef LBLOCK_HPP_INCLUDED
#define LBLOCK_HPP_INCLUDED

#include <block-maker/Physic/FixtureFactory/FileFixtureFactory.hpp>
#include <block-maker/Loader/Xml/Xml.hpp>
#include <block-maker/Resource/Binder/XmlResource.hpp>

namespace bm::physic {

    class LBlock : public FileFixtureFactory<std::vector, float> {
    public:
        LBlock(ShapeFactoryPtr shapeFactory, Fixture fixture);
        ~LBlock() = default;
    };
}

#endif // LBLOCK_HPP_INCLUDED
