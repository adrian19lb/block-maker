namespace bm::physic {

    template<template <typename... TArg> class TContainer, typename T, typename...R>
    FileFixtureFactory<TContainer, T, R... >::FileFixtureFactory( ShapeFactoryPtr shapeFactory, Fixture fixture,
                        binder::FileResourcePtr<TContainer, T, R...> binder)
    : BasicFixtureFactory<TContainer>{std::move(shapeFactory), fixture}
    , binder{ std::move(binder) } {
    }

    template<template <typename... TArg> class TContainer, typename T, typename...R>
    TContainer<b2Vec2> FileFixtureFactory<TContainer, T, R... >::createShapesCoordsHolder() {
        return std::move(shapesCoords);
    }

    template<template <typename... TArg> class TContainer, typename T, typename...R>
    void FileFixtureFactory<TContainer, T, R... >::appendShapesCoords(loader::NodePath path) {
        shapesCoords = std::move( binder->template bindChildsNodes<b2Vec2, 2>(path) );
    }
}
