namespace bm::physic {

    template<typename T>
    ShapePositionScaler<T>::ShapePositionScaler(const T& position)
    : shapePosition{position} {
    }

    template<typename T>
    T ShapePositionScaler<T>::operator()(float radius) {
        shapePosition *= radius;
        return shapePosition;
    }

    template<typename T>
    T ShapePositionScaler<T>::operator()(const b2Vec2& rectSize) {
        shapePosition.x *= rectSize.x;
        shapePosition.y *= rectSize.y;
        return shapePosition;
    }

    template<typename T>
    template<typename R>
    T ShapePositionScaler<T>::operator()(const sf::Vector2<R>& rectSize) {
        shapePosition.x *= rectSize.x;
        shapePosition.y *= rectSize.y;
        return shapePosition;
    }
}
