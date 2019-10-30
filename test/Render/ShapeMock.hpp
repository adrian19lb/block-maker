#ifndef SHAPEMOCK_HPP_INCLUDED
#define SHAPEMOCK_HPP_INCLUDED

#include <gmock/gmock.h>
#include <SFML/Graphics/Shape.hpp>

namespace bm::render::testing {

    class ShapeMock : public sf::Shape {
    public:
        MOCK_METHOD0(getPointCount, size_t());
        MOCK_METHOD1(getPoint, sf::Vector2f(size_t));
    };
}


#endif // SHAPEMOCK_HPP_INCLUDED
