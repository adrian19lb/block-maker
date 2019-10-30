#ifndef RENDERABLE_HPP_INCLUDED
#define RENDERABLE_HPP_INCLUDED

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <memory>

namespace bm::render {

    class Renderable : public sf::Drawable {
    public:
        virtual void setTexture(const sf::Texture& texture) = 0;
        virtual void setFillColor(sf::Color&& color) = 0;
        virtual void setOutlineColor(sf::Color&& color) = 0;
        virtual void setOutlineThickness(float thickness) = 0;
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    };

    using RenderablePtr = std::unique_ptr<Renderable>;
    using RenderableHolder = std::vector<RenderablePtr>;
}


#endif // RENDERABLE_HPP_INCLUDED
