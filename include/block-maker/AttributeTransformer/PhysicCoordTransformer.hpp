#ifndef PHYSICCOORDTRANSFROMER_HPP_INCLUDED
#define PHYSICCOORDTRANSFROMER_HPP_INCLUDED

#include <block-maker/AttributeTransformer/CoordTransformer.hpp>
#include <Box2D/Dynamics/b2Body.h>

namespace bm::transformer {

    class PhysicCoordTransformer : public transformer::CoordTransformer<b2Vec2> {
    public:
        PhysicCoordTransformer(b2Body* body);
        b2Vec2 transformToGlobalCoord(const b2Vec2& localCoord) override;
        b2Vec2 transformToGlobalCoord(float x, float y) override;
    private:
        b2Body* body;
    };

    using PhysicCoordTransformerPtr = std::unique_ptr<PhysicCoordTransformer>;

}

#endif // PHYSICCOORDTRANSFROMER_HPP_INCLUDED
