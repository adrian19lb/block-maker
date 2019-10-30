#ifndef SHAPECOMPOSITE_HPP_INCLUDED
#define SHAPECOMPOSITE_HPP_INCLUDED

#include <SFML/Graphics/Shape.hpp>
#include <block-maker/Render/Renderable.hpp>
#include <memory>
#include <block-maker/Render/Shape.hpp>

namespace bm::render {

    class ShapeComposite : public Renderable {
    public:
        virtual void append(ShapePtr shape) = 0;
        virtual void erase(sf::Shape* shape) = 0;
        virtual void clear() = 0;
        virtual size_t count() = 0;
    };

    using ShapeCompositePtr = std::unique_ptr<ShapeComposite>;

}

#endif // SHAPECOMPOSITE_HPP_INCLUDED
