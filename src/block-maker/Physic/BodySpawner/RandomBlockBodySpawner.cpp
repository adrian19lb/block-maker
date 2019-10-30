#include <block-maker/Physic/BodySpawner/RandomBlockBodySpawner.hpp>

namespace bm::physic {

    b2Body* RandomBlockBodySpawner::create(b2BodyType bodyType, b2Vec2 bodyPosition) {
        auto newBody = createBodyFromDefinition(bodyType, bodyPosition);
        auto randomFactoryItr = randomGenerator.generateRandomIterator( begin(), end() );
        auto& randomFactory = *randomFactoryItr->second;
        appendFixturesFrom(randomFactory, newBody);

        return newBody;
    }

}
