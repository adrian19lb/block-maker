#include <block-maker/Render/ShapeCreator/RenderablePolygonCreator.hpp>

namespace bm::render {

    RenderablePolygonCreator::RenderablePolygonCreator(b2PolygonShape* polygon, b2Body* body)
    : RenderableShapeCreator<b2Vec2>( std::make_unique<transformer::PhysicCoordTransformer>(body))
    , physicPolygon{polygon} {
    }

    ShapePtr RenderablePolygonCreator::create() {
        auto renderShape = std::move( std::make_unique<sf::ConvexShape>( physicPolygon->GetVertexCount() ));
        for (int32 i = 0; i < renderShape->getPointCount(); ++i) {
            const auto& localPhysicVertexCoord = physicPolygon->GetVertex(i);
            auto vertexGlobalRenderCoord = transformToGlobalRenderCoord(localPhysicVertexCoord);

            renderShape->setPoint(i, vertexGlobalRenderCoord);
        }

        return std::move(renderShape);
    }


}
