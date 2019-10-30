#include <block-maker/Physic/BodySpawner/BlockBodySpawner.hpp>

namespace bm::physic {

    BlockBodySpawner::BlockBodySpawner(BodyCreator&& bodyCreator)
    : creator(bodyCreator) {
    }

    b2Body* BlockBodySpawner::createBodyFromDefinition(b2BodyType bodyType, b2Vec2& blockOrigin) {
        b2BodyDef bodyDef;
        bodyDef.type = bodyType;
        bodyDef.position = blockOrigin;

        return creator(&bodyDef);
    }

    void BlockBodySpawner::appendFixturesFrom(FixtureFactory& factory, b2Body* body) {
        auto fixtures = factory.createFixture();
        for (auto& i : fixtures) {
            body->CreateFixture(&i);
        }
    }

    BlockBodySpawner::iterator BlockBodySpawner::begin() {
        return factories.begin();
    }

    BlockBodySpawner::iterator BlockBodySpawner::end() {
        return factories.end();
    }
}
