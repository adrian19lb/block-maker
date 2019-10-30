#include <block-maker/Render/ShapeComposite/ShapeArray.hpp>

namespace bm::render {

    ShapeArray::ShapeArray()
    : shapes{} {

    }

    ShapeArray::~ShapeArray() {
        clear();
    }

    void ShapeArray::append(ShapePtr shape) {
        shapes.emplace_back( std::move(shape) );
    }

    void ShapeArray::erase(sf::Shape* shape) {
        auto found = std::remove_if(shapes.begin(), shapes.end(), [&shape](auto& itr) {
            return itr.get() == shape;
        });

        shapes.erase(found, shapes.end());
    }

    void ShapeArray::clear() {
        shapes.clear();
    }

    size_t ShapeArray::count() {
        return shapes.size();
    }

    void ShapeArray::setFillColor(sf::Color&& color) {
        for (auto &i: shapes) {
            i->setFillColor( std::move(color) );
        }
    }

    void ShapeArray::setOutlineColor(sf::Color&& color) {
        for (auto& i : shapes) {
            i->setOutlineColor( std::move(color) );
        }
    }

    void ShapeArray::setOutlineThickness(float thickness) {
        for (auto& i : shapes) {
            i->setOutlineThickness(thickness);
        }
    }

    void ShapeArray::setTexture(const sf::Texture& texture) {
        for (auto& i : shapes) {
            i->setTexture(&texture);
        }
    }

    void ShapeArray::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        for (const auto& i : shapes) {
            target.draw(*i, states);
        }
    }
}
