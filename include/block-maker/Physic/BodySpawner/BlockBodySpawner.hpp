#ifndef BLOCKBODYSPAWNER_HPP_INCLUDED
#define BLOCKBODYSPAWNER_HPP_INCLUDED

#include <block-maker/Resource/Holder/TypeIndexKeyContainer.hpp>
#include <block-maker/Physic/FixtureFactory/FixtureFactory.hpp>
#include <Box2D/Dynamics/b2Body.h>
#include <functional>

namespace bm::physic {

    using BodyCreator = std::function<b2Body*(const b2BodyDef*)>;

    class BlockBodySpawner {
    protected:
        using iterator = container::TypeIndexKeyContainer<FixtureFactory>::iterator;
    public:
        BlockBodySpawner(BodyCreator&& bodyCreator);
        template<typename Param, typename Class, typename T>
        BlockBodySpawner(b2Body* (Class::*f)(Param), T* d);
        template<typename TypeBlock> b2Body* create(b2BodyType bodyType, b2Vec2 blockOrigin = b2Vec2(0.f, 0.f));
    protected:
        b2Body* createBodyFromDefinition(b2BodyType bodyType, b2Vec2& blockOrigin);
        void appendFixturesFrom(FixtureFactory& factory, b2Body* body);
    public:
        template<typename TypeBlock, typename ShapeFactoryType, typename TArg, typename... RArg>
        void append(TArg firstSetArg, RArg... secondSetArg);
        template<typename TypeBlock> void remove();
    protected:
        iterator begin();
        iterator end();
        template<typename TypeBlock> TypeBlock& get();
    private:
        container::TypeIndexKeyContainer<FixtureFactory> factories;
        BodyCreator creator;
    };
}

#include <block-maker/Physic/BodySpawner/BlockBodySpawner.inl>

#endif // BLOCKBODYSPAWNER_HPP_INCLUDED
