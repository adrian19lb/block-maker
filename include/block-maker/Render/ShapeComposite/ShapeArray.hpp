#ifndef SHAPEARRAY_HPP_INCLUDED
#define SHAPEARRAY_HPP_INCLUDED

#include <block-maker/Render/ShapeComposite/ShapeComposite.hpp>

namespace bm::render {

    class ShapeArray : public ShapeComposite {
    public:
        ShapeArray();
        ~ShapeArray();
        void append(ShapePtr shape) override;
        void erase(sf::Shape* shape) override;
        void clear() override;
        size_t count() override;
        void setTexture(const sf::Texture& texture) override;
        void setFillColor(sf::Color&& color) override;
        void setOutlineColor(sf::Color&& color) override;
        void setOutlineThickness(float thickness) override;
    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    private:
        std::vector<ShapePtr> shapes;
    };

    using ShapeArrayPtr = std::unique_ptr<ShapeArray>;


}

#endif // SHAPEARRAY_HPP_INCLUDED
