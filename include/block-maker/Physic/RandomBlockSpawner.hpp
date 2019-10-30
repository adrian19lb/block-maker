#ifndef RANDOMBLOCKSPAWNER_H
#define RANDOMBLOCKSPAWNER_H

#include <Box2D/Dynamics/b2World.h>
#include <block-maker/Physic/Fixture.hpp>
#include <block-maker/Physic/BodySpawner/RandomBlockBodySpawner.hpp>
#include <block-maker/Render/ShapeCompositeFactory/ShapeArrayFactory.hpp>
#include <block-maker/Physic/BlockSpawner.hpp>

namespace bm::physic {

    class RandomBlockSpawner : public BlockSpawner {
    public:
        RandomBlockSpawner(b2World* world);

        std::unique_ptr<Block> createBlock(b2Vec2 position) override;
        
        void setBlockSize(b2Vec2 size);
        
        void setFixture(Fixture fixture);
    protected:
        virtual void appendNewBlockTemplatesTo(RandomBlockBodySpawner* spawner);

        template<typename T,typename... BlockType> void append(RandomBlockBodySpawner* spawner) {
            ( spawner->append<BlockType, T>(size, fixture),... );
        }

    private:
        b2World* world;
        render::ShapeArrayFactory factory;
        Fixture fixture;
        b2Vec2 size;
    };

}

#endif /* RANDOMBLOCKSPAWNER_H */
