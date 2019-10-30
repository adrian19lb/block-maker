#include <boost/test/unit_test.hpp>
#include <vector>
#include <block-maker/Resource/Binder/FileResource.hpp>
#include <Box2D/Common/b2Math.h>
#include <Loader/FileLoaderMock.hpp>

namespace bm::binder::testing {

    using ::testing::Return;
    using ::testing::_;
    using loader::testing::FileLoaderMock;

    struct FileResourceFixture {
        FileResourceFixture() {
            auto fileLoader{std::make_unique< FileLoaderMock<std::vector, float> >()};
            fileLoaderMock = std::shared_ptr< FileLoaderMock<std::vector, float> >{ std::shared_ptr< FileLoaderMock<std::vector, float> >{}, fileLoader.get()};
            resourceBinder = std::move( std::make_unique< FileResource<std::vector, float> >( std::move(fileLoader) ));

        }
        ~FileResourceFixture() = default;

        FileResourcePtr<std::vector, float> resourceBinder;
        std::shared_ptr< FileLoaderMock<std::vector, float> > fileLoaderMock;
    };


    BOOST_FIXTURE_TEST_SUITE(FileResourceBinderTest, FileResourceFixture)
    BOOST_AUTO_TEST_CASE(bindNodeTest) {
        std::vector<float> testVector{1.25f, 1.50f};
        EXPECT_CALL(*fileLoaderMock, loadFromNode(_))
            .WillOnce(Return(testVector));

        auto mathVector = resourceBinder->bindNode<b2Vec2, 2>( {"pathToNode" } );
        BOOST_CHECK_EQUAL(mathVector.x, 1.25f);
        BOOST_CHECK_EQUAL(mathVector.y, 1.50f);

    }

    BOOST_AUTO_TEST_CASE(bindChildsNodeTest) {
        std::map<std::string, std::vector<float> > testMap = {
            { "testNodeOne", std::vector<float>{1.25f, 1.50f} },
            { "testNodeTwo", std::vector<float>{2.25f, 2.50f} }
        };
        EXPECT_CALL(*fileLoaderMock, loadFromChildsNodes(_))
            .WillOnce(Return(testMap));

        auto mathsVectors = resourceBinder->bindChildsNodes<b2Vec2, 2>( { "pathToNode"} );
        BOOST_CHECK_EQUAL( mathsVectors.begin()->x, 1.25f);
        BOOST_CHECK_EQUAL( mathsVectors.begin()->y, 1.50f);
        BOOST_CHECK_EQUAL( mathsVectors.rbegin()->x, 2.25f);
        BOOST_CHECK_EQUAL( mathsVectors.rbegin()->y, 2.50f);
    }
    BOOST_AUTO_TEST_SUITE_END()
}
