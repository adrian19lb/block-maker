namespace bm::loader {

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    Xml<TContainer, T, R...>::Xml(Buffer<char>& buffer)
    : mBuffer( std::move(buffer) ) {
        mBuffer.append('\0');
        if( mBuffer.size() ) {
            tryParseBufferWithFile();
        }
    }

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    Xml<TContainer, T, R...>::Xml(Buffer<char>&& buffer)
    : mBuffer( std::move(buffer) ) {
        mBuffer.append('\0');
        if( mBuffer.size() ) {
            tryParseBufferWithFile();
        }
    }

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    void Xml<TContainer, T, R...>::tryParseBufferWithFile() {
        try {
            document.parse<rapidxml::parse_no_data_nodes | rapidxml::parse_trim_whitespace>( &mBuffer.front() );
        }catch (const rapidxml::parse_error& error) {
            std::cerr << "Fail to parse buffer with xml parser: " << error.what() << std::endl;
        }
    }

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    void Xml<TContainer, T, R...>::parseFile(std::string&& filePath) {
        mBuffer.clear();
        mBuffer.appendFromFiles( {filePath} );
        mBuffer.append('\0');
        tryParseBufferWithFile();
    }

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    typename Xml<TContainer, T, R...>::Container Xml<TContainer, T, R...>::loadFromNode(NodePath path) {
        auto soughtNode = findNode( std::move(path) );
        NodeExtractor extractor(soughtNode);
        return std::move( extractor.extract() );
    }

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    rapidxml::xml_node<>* Xml<TContainer, T, R...>::findNode(NodePath&& nodePath) {
        NodeSeeker seeker( document.first_node() );
        rapidxml::xml_node<>* node;
        for (auto i : nodePath) {
            node = seeker.findNode( std::move(i) );
            seeker.changeRoot(node);
        }

        return node;
    }

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    typename Xml<TContainer, T, R...>::ChildsContainer Xml<TContainer, T, R...>::loadFromChildsNodes(NodePath path) {
        auto soughtNode = findNode( std::move(path) );
        auto values = std::move( create(soughtNode) );
        return std::move(values);
    }

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    typename Xml<TContainer, T, R...>::ChildsContainer Xml<TContainer, T, R...>::create(rapidxml::xml_node<>* parent) {
        ChildsContainer holder;
        for (auto i = parent->first_node(); i; i = i->next_sibling()) {
            NodeExtractor extractor(i);
            std::string nodeName = i->name();
            auto value = extractor.extract();
            holder.emplace( std::make_pair(nodeName, value) );
        }
        return std::move(holder);
    }
}
