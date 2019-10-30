#ifndef RANDOMBODYSPAWNER_HPP_INCLUDED
#define RANDOMBODYSPAWNER_HPP_INCLUDED

#include <Box2D/Dynamics/b2Body.h>

namespace bm::physic {

    class RandomBodySpawner {
        virtual b2Body* create(b2BodyType bodyType, b2Vec2 bodyPosition = b2Vec2(0.f, 0.f)) = 0;
    };

}

#endif // RANDOMBODYSPAWNER_HPP_INCLUDED
