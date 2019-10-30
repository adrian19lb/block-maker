#ifndef RENDERABLECIRCLECREATOR_HPP_INCLUDED
#define RENDERABLECIRCLECREATOR_HPP_INCLUDED

#include <block-maker/Render/ShapeCreator/RenderableShapeCreator.hpp>
#include <block-maker/AttributeTransformer/PhysicCoordTransformer.hpp>
#include <Box2D/Collision/Shapes/b2CircleShape.h>
#include <Box2D/Dynamics/b2Body.h>
#include <SFML/Graphics/CircleShape.hpp>

namespace bm::render {

    class RenderableCircleCreator : public RenderableShapeCreator<b2Vec2> {
    public:
        RenderableCircleCreator(b2CircleShape* physicCircle, b2Body* body);
        ShapePtr create() override;
    private:
        ShapePtr createRenderShape(sf::Vector2f const& position);
    private:
        float32 radius;
        b2Vec2 localOriginPhysicCoord;
    };

}

#endif // RENDERABLECIRCLECREATOR_HPP_INCLUDED
