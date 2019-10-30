#ifndef RENDERABLESHAPEFACTORY_HPP_INCLUDED
#define RENDERABLESHAPEFACTORY_HPP_INCLUDED

#include <Box2D/Dynamics/b2Body.h>
#include <block-maker/Render/ShapeComposite/ShapeComposite.hpp>

namespace bm::render {

    class ShapeCompoisteFactory {
    public:
        virtual ShapeCompositePtr create(b2Body* body) = 0;
    };

}

#endif // RENDERABLESHAPEFACTORY_HPP_INCLUDED
