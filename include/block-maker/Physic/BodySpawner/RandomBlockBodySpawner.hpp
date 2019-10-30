#ifndef RANDOMBLOCKBODYSPAWNER_HPP_INCLUDED
#define RANDOMBLOCKBODYSPAWNER_HPP_INCLUDED

#include <block-maker/Physic/BodySpawner/BlockBodySpawner.hpp>
#include <block-maker/RandomGenerator/RandomGenerator.hpp>
#include <block-maker/Physic/BodySpawner/RandomBodySpawner.hpp>

namespace bm::physic {

    class RandomBlockBodySpawner final : private BlockBodySpawner, public RandomBodySpawner {
    public:
        using BlockBodySpawner::append;
        using BlockBodySpawner::remove;
    public:
        template<typename Param, typename Class, typename T>
        RandomBlockBodySpawner(b2Body* (Class::*createBody)(Param), T* creator);
        b2Body* create(b2BodyType bodyType, b2Vec2 bodyPosition = b2Vec2(0.f, 0.f)) override;
    private:
        RandomGenerator randomGenerator;
    };

}

#include <block-maker/Physic/BodySpawner/RandomBlockBodySpawner.inl>

#endif // RANDOMBLOCKBODYSPAWNER_HPP_INCLUDED
