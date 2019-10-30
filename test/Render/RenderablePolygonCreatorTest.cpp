#include <boost/test/unit_test.hpp>
#include <block-maker/Render/ShapeCreator/RenderablePolygonCreator.hpp>
#include <Physic/FakeBodySpawner.hpp>

namespace bm::render::testing {

    struct RenderablePolygonCreatorFixture {

        RenderablePolygonCreatorFixture() {
            physicPolygonShape.SetAsBox(0.50f, 0.50f);
            auto body = fakeBodySpawner.create( b2BodyType::b2_dynamicBody, b2Vec2(0.f, 0.f) );
            renderableShapeCreator = std::move( std::make_unique<RenderablePolygonCreator>(&physicPolygonShape, body) );
        }

        ~RenderablePolygonCreatorFixture() = default;

        physic::testing::FakeBodySpawner fakeBodySpawner;
        b2PolygonShape physicPolygonShape;
        RenderableShapeCreatorPtr<b2Vec2> renderableShapeCreator;
    };

    BOOST_FIXTURE_TEST_SUITE(RenderablePolygonCreatorTest, RenderablePolygonCreatorFixture)
    BOOST_AUTO_TEST_CASE(createTest) {
        auto renderableShape = renderableShapeCreator->create();
        auto renderableConvexShape = dynamic_cast<sf::ConvexShape*>( renderableShape.get() );

        BOOST_CHECK_EQUAL(physicPolygonShape.GetVertex(0).x, renderableConvexShape->getPoint(0).x);
        BOOST_CHECK_EQUAL(physicPolygonShape.GetVertex(0).y, renderableConvexShape->getPoint(0).y);
        BOOST_CHECK_EQUAL(physicPolygonShape.GetVertex(3).x, renderableConvexShape->getPoint(3).x);
        BOOST_CHECK_EQUAL(physicPolygonShape.GetVertex(3).y, renderableConvexShape->getPoint(3).y);
        BOOST_CHECK_EQUAL(physicPolygonShape.GetVertexCount(), renderableConvexShape->getPointCount());
    }
    BOOST_AUTO_TEST_SUITE_END()

}

