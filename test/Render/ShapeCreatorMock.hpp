#ifndef SHAPECREATORMOCK_HPP_INCLUDED
#define SHAPECREATORMOCK_HPP_INCLUDED

#include <gmock/gmock.h>
#include <block-maker/Render/ShapeCreator/RenderableShapeCreator.hpp>

namespace bm::render::testing {

    template<typename T>
    class ShapeCreatorMock : public RenderableShapeCreator<T> {
    public:
        MOCK_METHOD0_T(create, ShapePtr());
    };


}


#endif // SHAPECREATORMOCK_HPP_INCLUDED
