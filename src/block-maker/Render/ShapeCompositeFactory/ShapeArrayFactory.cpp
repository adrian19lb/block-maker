#include <block-maker/Render/ShapeCompositeFactory/ShapeArrayFactory.hpp>

namespace bm::render {

    ShapeArrayFactory::ShapeArrayFactory() {
    }

    ShapeCompositePtr ShapeArrayFactory::create(b2Body* body) {
        try {
            mBody = body;
            createRenderableShape();
        }catch (const std::runtime_error& error) {
            std::cerr << error.what() << std::endl;
        }

        return std::move(shapes);
    }

    void ShapeArrayFactory::createRenderableShape() {
        shapes = std::move( std::make_unique<ShapeArray>() );
        for (auto fixture = mBody->GetFixtureList(); fixture; fixture = fixture->GetNext() ) {
            auto physicSegmentShape = fixture->GetShape();
            auto renderableSegmentShape = transform(physicSegmentShape);
            shapes->append( std::move(renderableSegmentShape) );
        }
    }

    ShapePtr ShapeArrayFactory::transform(b2Shape* shape) {
        if ( auto physicPolygon = dynamic_cast<b2PolygonShape*>(shape) ) {
            renderableShapeCreator = std::move( std::make_unique<RenderablePolygonCreator>(physicPolygon, mBody) );
        }

        else if ( auto physicCircle = dynamic_cast<b2CircleShape*>(shape) ) {
            renderableShapeCreator = std::move( std::make_unique<RenderableCircleCreator>(physicCircle, mBody) );
        }

        else {
            throw std::runtime_error("Can't create renderable shape");
        }

        return std::move( renderableShapeCreator->create() );
    }
}
