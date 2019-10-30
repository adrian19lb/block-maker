#include <boost/test/unit_test.hpp>
#include <block-maker/Loader/Buffer.hpp>
#include <fstream>
#include <sstream>

namespace bm::loader::testing {

    struct BufferFixture {
        BufferFixture()
        : emptyFileBuffer( std::make_unique<std::ifstream>() )
        , initFileBuffer( std::make_unique<std::ifstream>("test/resources/TxtTest.txt") ) {
            BOOST_TEST_PASSPOINT();
        }

        ~BufferFixture() = default;

        Buffer<std::string> emptyFileBuffer;
        Buffer<std::string> initFileBuffer;
    };

    BOOST_FIXTURE_TEST_SUITE(BufferTest, BufferFixture)
    BOOST_AUTO_TEST_CASE(constructorTest) {
        Buffer<std::string> buffer(initFileBuffer);
        std::string startValue = *buffer.begin();
        std::string endValue = *( --buffer.end() );

        BOOST_CHECK_EQUAL("HelloWorld", startValue);
        BOOST_CHECK_EQUAL("helloWorld", endValue);
    }

    BOOST_AUTO_TEST_CASE(appendTest) {
        emptyFileBuffer.append(1, 2, 3);
        Buffer<std::string> movedResourcesBuffer( std::move(emptyFileBuffer) );
        emptyFileBuffer.appendFromFiles( {"test/resources/TxtTest.txt"} );

        BOOST_CHECK_EQUAL( *movedResourcesBuffer.begin(), "1");
        BOOST_CHECK_EQUAL( *( --movedResourcesBuffer.end() ), "3");
        BOOST_CHECK_EQUAL( *emptyFileBuffer.begin(), "HelloWorld");
        BOOST_CHECK_EQUAL( *( --emptyFileBuffer.end() ), "helloWorld");
    }

    BOOST_AUTO_TEST_CASE(clearTest) {
        initFileBuffer.clear();
        BOOST_CHECK( !initFileBuffer.size() );
    }
    BOOST_AUTO_TEST_SUITE_END()
}


