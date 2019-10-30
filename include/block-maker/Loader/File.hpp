#ifndef FILE_HPP_INCLUDED
#define FILE_HPP_INCLUDED

#include <initializer_list>
#include <memory>
#include <map>

namespace bm::loader {

    template<typename>
    struct is_pair : public std::false_type {
    };

    template<typename T, typename U>
    struct is_pair< std::pair<T, U> > : public std::true_type {
    };

    using NodePath = std::initializer_list<std::string>;

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    class File {
    public:
        using Container = TContainer<T, R...>;
        using ChildsContainer = std::map<std::string, Container>;
        using value_type = typename Container::value_type;
        using iterator = typename Container::iterator;
        using const_iterator = typename Container::const_iterator;
    protected:
        template<typename U>
        using Enable_If_Map = typename std::enable_if< is_pair< typename U::value_type >::value >;
        template<typename U>
        using Enable_If_Not_Map = typename std::enable_if< !is_pair< typename U::value_type >::value >;
    public:
        virtual ~File() = default;
        virtual Container loadFromNode(NodePath path) = 0;
        virtual ChildsContainer loadFromChildsNodes(NodePath path) = 0;
    };

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    using FilePtr = std::unique_ptr< File<TContainer, T, R...> >;
}

#endif // FILE_HPP_INCLUDED
