#include <boost/test/unit_test.hpp>
#include <block-maker/Render/ShapeComposite/ShapeArray.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace bm::render::testing {

    struct ShapeArrayFixture {
        ShapeArrayFixture()
        : dummyShape{ std::make_unique<sf::RectangleShape>( sf::Vector2f(100.f, 100.f) )}
        , rawDummyShape{ dummyShape.get() }
        , shapeComposite{ std::make_unique<ShapeArray>() } {
        }

        ~ShapeArrayFixture() = default;

        ShapePtr dummyShape;
        sf::Shape* rawDummyShape;
        ShapeCompositePtr shapeComposite;
    };


    BOOST_FIXTURE_TEST_SUITE(ShapeArrayTest, ShapeArrayFixture)
    BOOST_AUTO_TEST_CASE(appendAndEraseTest) {
        shapeComposite->append( std::move(dummyShape) );
        shapeComposite->erase( rawDummyShape );

        BOOST_CHECK_EQUAL( 0, shapeComposite->count() );
    }

    BOOST_AUTO_TEST_CASE(clearTest) {
        shapeComposite->append( std::move(dummyShape) );
        shapeComposite->clear();

        BOOST_CHECK_EQUAL( 0, shapeComposite->count() );
    }
    BOOST_AUTO_TEST_SUITE_END()
}
