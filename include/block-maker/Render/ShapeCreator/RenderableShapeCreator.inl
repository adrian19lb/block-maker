namespace bm::render {

    template<typename T>
    RenderableShapeCreator<T>::RenderableShapeCreator(transformer::CoordTransformerPtr<T> coordTransformer)
    : coordTransformer{std::move(coordTransformer)} {
    }

    template<typename T>
    sf::Vector2f RenderableShapeCreator<T>::transformToGlobalRenderCoord(T localPhysicCoord) {
        auto globalPhysicCoord = coordTransformer->transformToGlobalCoord(localPhysicCoord);

        return sf::Vector2f(globalPhysicCoord.x, globalPhysicCoord.y);
    }
}
