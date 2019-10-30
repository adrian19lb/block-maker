#ifndef FILEFIXTUREFACTORY_HPP_INCLUDED
#define FILEFIXTUREFACTORY_HPP_INCLUDED

#include <block-maker/Physic/FixtureFactory/BasicFixtureFactory.hpp>
#include <block-maker/Resource/Binder/FileResource.hpp>

namespace bm::physic {

    template<template <typename... TArg> class TContainer, typename T, typename...R>
    class FileFixtureFactory : public BasicFixtureFactory<TContainer> {
    public:
        FileFixtureFactory( ShapeFactoryPtr shapeFactory, Fixture fixture,
                            binder::FileResourcePtr<TContainer, T, R...> binder);

        TContainer<b2Vec2> createShapesCoordsHolder() override;
    protected:
        void appendShapesCoords(loader::NodePath path);
    private:
        binder::FileResourcePtr<TContainer, T, R...> binder;
        TContainer<b2Vec2> shapesCoords;
    };

}

#include <block-maker/Physic/FixtureFactory/FileFixtureFactory.inl>

#endif // FILEFIXTUREFACTORY_HPP_INCLUDED
