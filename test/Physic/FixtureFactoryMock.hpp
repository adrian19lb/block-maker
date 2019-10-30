#ifndef FIXTUREFACTORYMOCK_HPP_INCLUDED
#define FIXTUREFACTORYMOCK_HPP_INCLUDED

#include "../../include/Physic/FixtureFactory/FixtureFactory.hpp"

namespace bm::physic::testing {

    class FixtureFactoryMock : public FixtureFactory {
    public:
        MOCK_METHOD0( createFixture, FixturesContainer() );
    };
}

#endif // FIXTUREFACTORYMOCK_HPP_INCLUDED
