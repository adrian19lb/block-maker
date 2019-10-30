#ifndef FIXTUREFACTORY_HPP_INCLUDED
#define FIXTUREFACTORY_HPP_INCLUDED

#include <vector>
#include <memory>
#include <Box2D/Dynamics/b2Fixture.h>

namespace bm::physic {

    using FixturesContainer = std::vector<b2FixtureDef>;

    class FixtureFactory {
    public:
        virtual FixturesContainer createFixture() = 0;
    };

    using FixtureFactoryPtr = std::unique_ptr<FixtureFactory>;
}

#endif // FIXTUREFACTORY_HPP_INCLUDED
