#include <block-maker/Render/ShapeCreator/RenderableCircleCreator.hpp>

namespace bm::render {

    RenderableCircleCreator::RenderableCircleCreator(b2CircleShape* physicCircle, b2Body* body)
    : RenderableShapeCreator<b2Vec2>( std::make_unique<transformer::PhysicCoordTransformer>(body) )
    , radius{physicCircle->m_radius}
    , localOriginPhysicCoord{physicCircle->m_p} {
    }

    ShapePtr RenderableCircleCreator::create() {
        auto globalRenderOriginCoord = transformToGlobalRenderCoord(localOriginPhysicCoord);

        return std::move( createRenderShape(globalRenderOriginCoord) );
    }

    ShapePtr RenderableCircleCreator::createRenderShape(sf::Vector2f const& position) {
        auto renderableShape = std::make_unique<sf::CircleShape>(radius);
        renderableShape->setOrigin(radius, radius);
        renderableShape->setPosition(position.x, position.y);

        return std::move(renderableShape);

    }
}
