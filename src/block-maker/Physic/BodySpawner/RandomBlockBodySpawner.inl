namespace bm::physic {

    template<typename Param, typename Class, typename T>
    RandomBlockBodySpawner::RandomBlockBodySpawner(b2Body* (Class::*createBody)(Param), T* creator)
    : BlockBodySpawner{createBody, creator}
    , randomGenerator() {
    }
}
