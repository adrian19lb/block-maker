#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <block-maker/Loader/File.hpp>

namespace bm::loader::testing {

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    class FileLoaderMock : public File<TContainer, T, R...> {
    public:
        using Container = typename File<TContainer, T, R...>::Container;
        using ChildsContainer = typename File<TContainer, T, R...>::ChildsContainer;
    public:
        virtual ~FileLoaderMock() = default;
        MOCK_METHOD1_T(loadFromNode, Container(NodePath));
        MOCK_METHOD1_T(loadFromChildsNodes, ChildsContainer(NodePath));
    };


}
