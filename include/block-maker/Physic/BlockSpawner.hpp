#ifndef BLOCKSPAWNER_H
#define BLOCKSPAWNER_H

#include <Box2D/Common/b2Math.h>
#include <block-maker/Block.hpp>
#include <memory>

namespace bm::physic {

    class BlockSpawner {
    public:
        virtual ~BlockSpawner() = default;
        virtual std::unique_ptr<Block> createBlock(b2Vec2 position) = 0;
    };

}

#endif /* BLOCKSPAWNER_H */
