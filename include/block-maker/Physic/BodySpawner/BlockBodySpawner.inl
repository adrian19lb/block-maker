namespace bm::physic {

    template<typename Param, typename Class, typename T>
    BlockBodySpawner::BlockBodySpawner(b2Body* (Class::*f)(Param), T* d) {
        creator = std::bind(f, d, std::placeholders::_1);
    }

    template<typename TypeBlock>
    b2Body* BlockBodySpawner::create(b2BodyType bodyType, b2Vec2 blockOrigin) {
        auto newBody = createBodyFromDefinition(bodyType, blockOrigin);
        auto& factory = get<TypeBlock>();
        appendFixturesFrom(factory, newBody);

        return newBody;
    }

    template<typename TypeBlock, typename ShapeFactoryType, typename TArg, typename... RArg>
    void BlockBodySpawner::append(TArg firstSetArg, RArg... secondSetArg) {
        auto newFixtureFactory{ std::make_unique<ShapeFactoryType>( std::forward<TArg>(firstSetArg) ) };
        factories.append<TypeBlock>( std::move(newFixtureFactory), std::forward<RArg>(secondSetArg)...);
    }

    template<typename TypeBlock> void BlockBodySpawner::remove() {
        factories.remove<TypeBlock>();
    }

    template<typename TypeBlock> TypeBlock& BlockBodySpawner::get() {
        return factories.get<TypeBlock>();
    }


}
