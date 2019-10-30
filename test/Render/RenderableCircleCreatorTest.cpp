#include <boost/test/unit_test.hpp>
#include <block-maker/Render/ShapeCreator/RenderableCircleCreator.hpp>
#include "../Physic/FakeBodySpawner.hpp"

namespace bm::render::testing {

    struct RenderableCircleCreatorFixture {
        RenderableCircleCreatorFixture()
        : fakeBodySpawner() {
            auto body = fakeBodySpawner.create(b2BodyType::b2_dynamicBody, b2Vec2(0.f, 0.f));
            physicCircleShape.m_radius = 0.5f;
            physicCircleShape.m_p = b2Vec2(0.f, 0.f);
            shapeCreator = std::move( std::make_unique<RenderableCircleCreator>(&physicCircleShape, body) );
        }

        ~RenderableCircleCreatorFixture() = default;

        physic::testing::FakeBodySpawner fakeBodySpawner;
        b2CircleShape physicCircleShape;
        std::unique_ptr< RenderableShapeCreator<b2Vec2> > shapeCreator;
    };

    BOOST_FIXTURE_TEST_SUITE(RenderableCircleCreatorTest, RenderableCircleCreatorFixture)
    BOOST_AUTO_TEST_CASE(createTest) {
        ShapePtr renderShape = shapeCreator->create();
        sf::CircleShape* renderCircleShape = dynamic_cast<sf::CircleShape*>(renderShape.get());
        auto radius = renderCircleShape->getRadius();
        auto position = renderCircleShape->getPosition();

        BOOST_CHECK_EQUAL(radius, physicCircleShape.m_radius);
        BOOST_CHECK_EQUAL(position.x, physicCircleShape.m_p.x);
        BOOST_CHECK_EQUAL(position.y, physicCircleShape.m_p.y);
    }
    BOOST_AUTO_TEST_SUITE_END()
}
