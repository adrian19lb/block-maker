namespace bm::physic {

    template<template <typename... TArg> class TContainer>
    BasicFixtureFactory<TContainer>::BasicFixtureFactory(ShapeFactoryPtr factory, Fixture basicFixture)
    : shapeFactory{ std::move(factory) }
    , basicFixture{basicFixture} {
    }

    template<template <typename... TArg> class TContainer>
    FixturesContainer BasicFixtureFactory<TContainer>::createFixture() {
        auto shapesCoords = createShapesCoordsHolder();
        auto fixtures = std::move( createFixtureWithShape(shapesCoords) );

        return std::move(fixtures);
    }

    template<template <typename... TArg> class TContainer>
    FixturesContainer BasicFixtureFactory<TContainer>::createFixtureWithShape(const TContainer<b2Vec2>& shapesCoords) {
        FixturesContainer fixtures;
        for (const auto& i : shapesCoords) {
            auto scaledCoords = scaleAttributeDependOfSize(i);
            auto newShape = shapeFactory->createShape(scaledCoords);
            auto newFixture = appendToBasicFixture( newShape.get() );
            shapes.emplace_back( std::move(newShape) );
            fixtures.emplace_back( std::move(newFixture) );
        }
        return std::move(fixtures);
    }

    template<template <typename... TArg> class TContainer>
    b2Vec2 BasicFixtureFactory<TContainer>::scaleAttributeDependOfSize(const b2Vec2& attribute) {
        ShapePositionScaler<b2Vec2> multiplier(attribute);
        auto shapeSize = shapeFactory->getSize();
        auto newPosition = boost::apply_visitor(multiplier, shapeSize);

        return newPosition;

    }

    template<template <typename... TArg> class TContainer>
    b2FixtureDef BasicFixtureFactory<TContainer>::appendToBasicFixture(b2Shape* shape) {
        b2FixtureDef newExtendedFixture;
        newExtendedFixture.friction = basicFixture.friction;
        newExtendedFixture.density = basicFixture.density;
        newExtendedFixture.restitution = basicFixture.restitution;
        newExtendedFixture.shape = shape;

        return std::move(newExtendedFixture);
    }

}
