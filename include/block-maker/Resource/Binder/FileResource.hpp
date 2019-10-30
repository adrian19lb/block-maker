#ifndef FILERESOURCE_HPP_INCLUDED
#define FILERESOURCE_HPP_INCLUDED

#include <memory>
#include <utility>
#include <block-maker/Loader/File.hpp>

namespace bm::binder {

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    class FileResource {
    public:
        FileResource(loader::FilePtr<TContainer, T, R...> loader);
        template<typename ValueType, size_t N> ValueType bindNode(loader::NodePath path);
        template<typename ValueType, size_t N> typename loader::File<TContainer, ValueType>::Container bindChildsNodes(loader::NodePath path);
    private:
        template<typename ValueType,  size_t N, typename ContainerType,
        typename Indices = std::make_index_sequence<N> >
        ValueType createFromSequence(const ContainerType& container);
        template<typename ValueType, typename ContainerType, size_t... I>
        ValueType createFromSequenceImpl(const ContainerType& container, std::index_sequence<I...>);
    private:
        loader::FilePtr<TContainer, T, R...> loader;
    };

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    using FileResourcePtr = std::unique_ptr< FileResource<TContainer, T, R...> >;
}

#include <block-maker/Resource/Binder/FileResource.inl>
#endif // FILERESOURCE_HPP_INCLUDED
