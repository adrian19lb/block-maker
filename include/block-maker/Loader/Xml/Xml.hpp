#ifndef XML_HPP_INCLUDED
#define XML_HPP_INCLUDED

#include <block-maker/Loader/File.hpp>
#include <block-maker/Loader/Xml/rapidxml.hpp>
#include <block-maker/Loader/Buffer.hpp>

namespace bm::loader {

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    class Xml final : public File<TContainer, T, R... > {
        class NodeSeeker;
        class NodeExtractor;
    private:
        using Container = typename File<TContainer, T, R... >::Container;
        using ChildsContainer = typename File<TContainer, T, R... >::ChildsContainer;
        using value_type = typename Container::value_type;
        using iterator = typename Container::iterator;
        using const_iterator = typename Container::const_iterator;
    public:
        Xml(Buffer<char>& buffer);
        Xml(Buffer<char>&& buffer);
        Xml() = delete;
    private:
        void tryParseBufferWithFile();
    private:
        rapidxml::xml_node<>* findNode(NodePath&& path);
    public:
        virtual Container loadFromNode(NodePath path) override;
        virtual ChildsContainer loadFromChildsNodes(NodePath path) override;
        void parseFile(std::string&& filePath);
    private:
        ChildsContainer create(rapidxml::xml_node<>* parent);
    private:
        rapidxml::xml_document<> document;
        Buffer<char> mBuffer;
    };

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    using XmlPtr = std::unique_ptr< Xml<TContainer, T, R... > >;
}

#include <block-maker/Loader/Xml/Xml.inl>
#include <block-maker/Loader/Xml/NodeSeeker.hpp>
#include <block-maker/Loader/Xml/NodeExtractor.hpp>

#endif // XML_HPP_INCLUDED
