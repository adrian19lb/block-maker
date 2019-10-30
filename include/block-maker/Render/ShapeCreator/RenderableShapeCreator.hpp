#ifndef RENDERABLESHAPECREATOR_HPP_INCLUDED
#define RENDERABLESHAPECREATOR_HPP_INCLUDED

#include <block-maker/Render/ShapeComposite/ShapeArray.hpp>
#include <block-maker/AttributeTransformer/CoordTransformer.hpp>

namespace bm::render {

    template<typename T>
    class RenderableShapeCreator {
    public:
        RenderableShapeCreator(transformer::CoordTransformerPtr<T> coordTransformer);
        virtual ShapePtr create() = 0;
    protected:
        sf::Vector2f transformToGlobalRenderCoord(T localPhysicCoord);
    private:
        transformer::CoordTransformerPtr<T> coordTransformer;
    };

    template<typename T>
    using RenderableShapeCreatorPtr = std::unique_ptr<RenderableShapeCreator<T>>;
}

#include <block-maker/Render/ShapeCreator/RenderableShapeCreator.inl>

#endif // RENDERABLESHAPECREATOR_HPP_INCLUDED
