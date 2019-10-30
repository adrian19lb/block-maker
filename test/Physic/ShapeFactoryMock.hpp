#ifndef SHAPEFACTORYMOCK_HPP_INCLUDED
#define SHAPEFACTORYMOCK_HPP_INCLUDED

#include "../../include/Physic/FixtureFactory/ShapeFactory.hpp"

namespace bm::physic::testing {

    class ShapeFactoryMock : public ShapeFactory {
        MOCK_METHOD1( createShape, ShapePtr(const b2Vec2&) );
        MOCK_CONST_METHOD0( getSize, boost::variant<float, b2Vec2>() );
    };

}

#endif // SHAPEFACTORYMOCK_HPP_INCLUDED
