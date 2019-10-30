#include <block-maker/AttributeTransformer/PhysicCoordTransformer.hpp>

namespace bm::transformer {

    PhysicCoordTransformer::PhysicCoordTransformer(b2Body* body)
    : body{body} {
    }

    b2Vec2 PhysicCoordTransformer::transformToGlobalCoord(const b2Vec2& localCoord) {
        auto globalCoord = body->GetWorldPoint(localCoord);

        return globalCoord;
    }

    b2Vec2 PhysicCoordTransformer::transformToGlobalCoord(float x, float y) {
        b2Vec2 globalCoord{x, y};

        return transformToGlobalCoord(globalCoord);

    }

}
