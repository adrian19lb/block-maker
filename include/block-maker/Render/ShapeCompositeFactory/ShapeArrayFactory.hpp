#ifndef SHAPEARRAYFACTORY_HPP_INCLUDED
#define SHAPEARRAYFACTORY_HPP_INCLUDED

#include <Box2D/Dynamics/b2Fixture.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Collision/Shapes/b2CircleShape.h>
#include <block-maker/Render/ShapeComposite/ShapeArray.hpp>
#include <block-maker/Render/ShapeCreator/RenderablePolygonCreator.hpp>
#include <block-maker/Render/ShapeCreator/RenderableCircleCreator.hpp>
#include "ShapeCompositeFactory.hpp"
#include <iostream>

namespace bm::render {

    class ShapeArrayFactory : public ShapeCompoisteFactory {
    public:
        ShapeArrayFactory();
        ~ShapeArrayFactory() = default;
        virtual ShapeCompositePtr create(b2Body* body) override;
    private:
        void createRenderableShape();
    protected:
        ShapePtr transform(b2Shape* shape);
    private:
        ShapeCompositePtr shapes;
        RenderableShapeCreatorPtr<b2Vec2> renderableShapeCreator;
        b2Body* mBody;
    };

}
#endif // SHAPEARRAYFACTORY_HPP_INCLUDED
