#include <boost/test/unit_test.hpp>
#include <block-maker/Physic/FixtureFactory/RectShapeFactory.hpp>

namespace bm::physic::testing {

    struct RectShapeFactoryFixture {
        RectShapeFactoryFixture()
        : shapeFactory{std::make_unique<RectShapeFactory>( b2Vec2(0.25f, 0.25f) )}
        , expectedXCoords{-0.125f, 0.125f, 0.125f, -0.125f}
        , expectedYCoords{-0.125f, -0.125f, 0.125f, 0.125f} {
        }

        ~RectShapeFactoryFixture() = default;

        ShapeFactoryPtr shapeFactory;
        std::vector<float32> expectedXCoords;
        std::vector<float32> expectedYCoords;
    };

    BOOST_FIXTURE_TEST_SUITE(RectShapeFactoryTest, RectShapeFactoryFixture)
    BOOST_AUTO_TEST_CASE(createTest) {
        b2Vec2 shapeOrigin(0.f, 0.f);
        auto shape = shapeFactory->createShape(shapeOrigin);
        auto polygonShape = dynamic_cast<b2PolygonShape*>(shape.get());

        BOOST_CHECK_EQUAL(polygonShape->GetVertex(0).x, expectedXCoords[0]);
        BOOST_CHECK_EQUAL(polygonShape->GetVertex(0).y, expectedYCoords[0]);
        BOOST_CHECK_EQUAL(polygonShape->GetVertex(1).x, expectedXCoords[1]);
        BOOST_CHECK_EQUAL(polygonShape->GetVertex(1).y, expectedYCoords[1]);
        BOOST_CHECK_EQUAL(polygonShape->GetVertex(2).x, expectedXCoords[2]);
        BOOST_CHECK_EQUAL(polygonShape->GetVertex(2).y, expectedYCoords[2]);
        BOOST_CHECK_EQUAL(polygonShape->GetVertex(3).x, expectedXCoords[3]);
        BOOST_CHECK_EQUAL(polygonShape->GetVertex(3).y, expectedYCoords[3]);
        BOOST_CHECK_EQUAL(polygonShape->GetVertexCount(), 4);
    }
    BOOST_AUTO_TEST_SUITE_END()
}
