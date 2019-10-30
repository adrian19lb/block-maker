#include <block-maker/Render/BodyShape.hpp>
#include <block-maker/Physic/FixtureFactory/RectShapeFactory.hpp>
#include <block-maker/Physic/RandomBlockSpawner.hpp>
#include <block-maker/Physic/BodySpawner/RandomBlockBodySpawner.hpp>
#include <block-maker/Physic/BlockFixtureFactory.hpp>

namespace bm::physic {
        
    RandomBlockSpawner::RandomBlockSpawner(b2World* world)
    : world(world)
    , fixture()
    , size(0.25f, 0.25f) {
        
    }

    std::unique_ptr<Block> RandomBlockSpawner::createBlock(b2Vec2 position) {
        auto bodySpawner = std::make_unique<RandomBlockBodySpawner>(&b2World::CreateBody, world);
        appendNewBlockTemplatesTo(bodySpawner.get());
        auto body = bodySpawner->create(b2BodyType::b2_dynamicBody, position);
        auto shape = std::make_unique<render::BodyShape>(&factory,body);

        return std::make_unique<Block>(body, std::move(shape));
    }

    void RandomBlockSpawner::setBlockSize(b2Vec2 size) {
        this->size = size;
    }

    void RandomBlockSpawner::setFixture(Fixture fixture) {
        this->fixture = fixture;
    }

    void RandomBlockSpawner::appendNewBlockTemplatesTo(RandomBlockBodySpawner* spawner) {
        append<RectShapeFactory, BoxBlock,TBlock,UBlock,OBlock,IBlock,LBlock,NBlock,PlusBlock, HalfPlusBlock>(spawner);
    }

}
