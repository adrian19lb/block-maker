#ifndef RENDERABLEPOLYGONCREATOR_HPP_INCLUDED
#define RENDERABLEPOLYGONCREATOR_HPP_INCLUDED

#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Dynamics/b2Body.h>
#include <SFML/Graphics/ConvexShape.hpp>
#include <block-maker/Render/ShapeComposite/ShapeArray.hpp>
#include <block-maker/Render/ShapeCreator/RenderableShapeCreator.hpp>
#include <block-maker/AttributeTransformer/PhysicCoordTransformer.hpp>

namespace bm::render {

    class RenderablePolygonCreator : public RenderableShapeCreator<b2Vec2> {
    public:
        RenderablePolygonCreator(b2PolygonShape* polygon, b2Body* body);
        ShapePtr create() override;
    private:
        b2PolygonShape* physicPolygon;
    };

}


#endif // RENDERABLEPOLYGONCREATOR_HPP_INCLUDED
