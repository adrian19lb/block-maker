#ifndef SHAPE_HPP_INCLUDED
#define SHAPE_HPP_INCLUDED

#include <memory>
#include <SFML/Graphics/Shape.hpp>

namespace bm::render {

    using ShapePtr = std::unique_ptr<sf::Shape>;
}


#endif // SHAPE_HPP_INCLUDED
