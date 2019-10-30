namespace bm::binder {

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    FileResource<TContainer, T, R...>::FileResource(loader::FilePtr<TContainer, T, R...> loader)
    : loader{std::move(loader)} {
    }

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    template<typename ValueType, size_t N>
    ValueType FileResource<TContainer, T, R...>::bindNode(loader::NodePath path) {
        auto nodeValues = loader->loadFromNode( std::forward<loader::NodePath>(path) );

        return createFromSequence<ValueType, N>(nodeValues);
    }

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    template<typename ValueType, size_t N>
    typename loader::File<TContainer, ValueType>::Container FileResource<TContainer, T, R...>::bindChildsNodes(loader::NodePath path) {
        auto childsNodesValues = loader->loadFromChildsNodes(path);
        typename loader::File<TContainer, ValueType>::Container childsValues;
        for (auto& i : childsNodesValues) {
            auto transformedValue = createFromSequence<ValueType, N>(i.second);
            childsValues.emplace(childsValues.end(), transformedValue);
        }

        return std::move(childsValues);
    }

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    template<typename ValueType,  size_t N, typename ContainerType, typename Indices>
        ValueType FileResource<TContainer, T, R...>::createFromSequence(const ContainerType& container) {

        return createFromSequenceImpl<ValueType>(container, Indices{});
    }

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    template<typename ValueType, typename ContainerType, size_t... I>
    ValueType FileResource<TContainer, T, R...>::createFromSequenceImpl(const ContainerType& container, std::index_sequence<I...>) {
        return ValueType(container.at(I)... );
    }
}
