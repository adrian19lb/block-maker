#ifndef BOXBLOCK_HPP_INCLUDED
#define BOXBLOCK_HPP_INCLUDED

#include <block-maker/Physic/FixtureFactory/FileFixtureFactory.hpp>
#include <block-maker/Loader/Xml/Xml.hpp>
#include <block-maker/Resource/Binder/XmlResource.hpp>

namespace bm::physic {

    class BoxBlock : public FileFixtureFactory<std::vector, float> {
    public:
        BoxBlock(ShapeFactoryPtr shapeFactory, Fixture fixture);
        ~BoxBlock() = default;
    };
}

#endif // BOXBLOCK_HPP_INCLUDED
