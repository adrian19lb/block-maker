#include <boost/test/unit_test.hpp>
#include <block-maker/Loader/Xml/Xml.hpp>
#include <memory>
#include <fstream>
#include "FileLoaderMock.hpp"

namespace bm::loader::testing {

    struct XmlFixture {
        XmlFixture()
        : dummyBuffer( std::make_unique<std::ifstream>("test/resources/XmlTest.xml") ) {
            testedXmlParser = std::make_unique< Xml<std::map, std::string, float> >(dummyBuffer); //move buffer to parser;
        }

        ~XmlFixture() = default;

        std::unique_ptr< Xml<std::map, std::string, float> > testedXmlParser;
        Buffer<char> dummyBuffer;
    };

    BOOST_FIXTURE_TEST_SUITE(XmlTest, XmlFixture)
    BOOST_AUTO_TEST_CASE(loadFromNodeTest) {
        auto mathVectorOne = testedXmlParser->loadFromNode( {"testChildOne", "testVectorOne" } );
        testedXmlParser = std::move( std::make_unique< loader::Xml<std::map, std::string, float> >(dummyBuffer) );
        testedXmlParser->parseFile("test/resources/XmlTest.xml");
        auto mathVectorTwo = testedXmlParser->loadFromNode( {"testChildTwo", "testVectorThree"} );

        BOOST_CHECK_EQUAL( mathVectorOne["x"], 1.25f);
        BOOST_CHECK_EQUAL( mathVectorOne["y"], 1.50f);
        BOOST_CHECK_EQUAL( mathVectorTwo["x"], 3.50f);
        BOOST_CHECK_EQUAL( mathVectorTwo["y"], 3.25f);
    }

    BOOST_AUTO_TEST_CASE(loadFromChildsNodesTest) {
        auto values = testedXmlParser->loadFromChildsNodes( { "testChildOne"} );
        BOOST_CHECK_EQUAL( values["testVectorOne"]["x"], 1.25f);
        BOOST_CHECK_EQUAL( values["testVectorOne"]["y"], 1.50f);
        BOOST_CHECK_EQUAL( values["testVectorTwo"]["x"], 2.25f);
        BOOST_CHECK_EQUAL( values["testVectorTwo"]["y"], 2.50f);
    }
    BOOST_AUTO_TEST_SUITE_END()
}
