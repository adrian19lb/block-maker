#ifndef BASICFIXTUREFACTORY_HPP_INCLUDED
#define BASICFIXTUREFACTORY_HPP_INCLUDED

#include <block-maker/Physic/Fixture.hpp>
#include <block-maker/Physic/ShapePositionScaler.hpp>
#include <block-maker/Physic/FixtureFactory/ShapeFactory.hpp>
#include <block-maker/Physic/FixtureFactory/FixtureFactory.hpp>

namespace bm::physic {

    template<template <typename... TArg> class TContainer>
    class BasicFixtureFactory : public FixtureFactory {
    public:
        BasicFixtureFactory(Fixture fixture);
        BasicFixtureFactory(ShapeFactoryPtr shapeFactory, Fixture fixture);
        FixturesContainer createFixture() override;
    protected:
        virtual TContainer<b2Vec2> createShapesCoordsHolder() = 0;
    private:
        FixturesContainer createFixtureWithShape(const TContainer<b2Vec2>& shapesCoords);
        b2FixtureDef appendToBasicFixture(b2Shape* shape);
        b2Vec2 scaleAttributeDependOfSize(const b2Vec2& attribute);
    private:
        ShapeFactoryPtr shapeFactory;
        Fixture basicFixture;
        std::vector<ShapePtr> shapes;
    };

}

#include <block-maker/Physic/FixtureFactory/BasicFixtureFactory.inl>

#endif // BASICFIXTUREFACTORY_HPP_INCLUDED
