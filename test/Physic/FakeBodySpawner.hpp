#ifndef FAKEBODYSPAWNER_HPP_INCLUDED
#define FAKEBODYSPAWNER_HPP_INCLUDED

#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2World.h>

namespace bm::physic::testing {

    class FakeBodySpawner {
    public:
        FakeBodySpawner()
        : world( b2Vec2(0.f, 10.f) ) {
        }

        ~FakeBodySpawner() = default;

        b2Body* create(b2BodyType type, b2Vec2&& position) {
            b2BodyDef bodyDef;
            bodyDef.type = type;
            bodyDef.position = std::move(position);

            return world.CreateBody(&bodyDef);
        }

    private:
        b2World world;
    };
}

#endif // FAKEBODYSPAWNER_HPP_INCLUDED
