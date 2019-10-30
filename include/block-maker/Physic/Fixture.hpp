#ifndef FIXTURE_HPP_INCLUDED
#define FIXTURE_HPP_INCLUDED

#include <Box2D/Common/b2Math.h>

namespace bm::physic {

    struct Fixture {

		float32 friction = 0.0f;
        
		float32 restitution = 0.0f;

		float32 density = 0.0f;

        Fixture(const Fixture& fixture) {
            copy(fixture);
        }

        Fixture() = default;

        Fixture& operator=(const Fixture&  fixture) {
            copy(fixture);
            return *this;
        }

    private:
        void copy(const Fixture& fixture){
            this->density = fixture.density;
            this->friction = fixture.friction;
            this->restitution = fixture.restitution;
        }
    };

}

#endif // FIXTURE_HPP_INCLUDED
