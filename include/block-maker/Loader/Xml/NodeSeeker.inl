namespace bm::loader {

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    Xml<TContainer, T, R...>::NodeSeeker::NodeSeeker(rapidxml::xml_node<>* root)
    : mRoot(root) {
    }

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    void Xml<TContainer, T, R...>::NodeSeeker::changeRoot(rapidxml::xml_node<>* root) {
        mRoot = root;
    }

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    rapidxml::xml_node<>* Xml<TContainer, T, R...>::NodeSeeker::findNode(std::string&& nodeName) {
        auto soughtParentNode = tryFindValueByNodeName(mRoot, nodeName.c_str()); //add seeking by attribute
        assert(mRoot != soughtParentNode);
        return soughtParentNode;
    }

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    rapidxml::xml_node<>* Xml<TContainer, T, R...>::NodeSeeker::tryFindValueByNodeName(rapidxml::xml_node<>* node, const char* nodeName) {
        if (auto soughtNode = node->first_node(nodeName); !soughtNode) {
            auto nextNodeSibling = node->next_sibling(nodeName);
            auto firstNodeChild = node->first_node();
            seekNodeIfParentExist(nextNodeSibling, nodeName);
            seekNodeIfParentExist(firstNodeChild, nodeName);
        }else {
            return soughtNode;
        }

        return node;
    }

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    void Xml<TContainer, T, R...>::NodeSeeker::seekNodeIfParentExist(rapidxml::xml_node<>* parent, const char* nodeName) {
        if (parent) {
            tryFindValueByNodeName(parent, nodeName);
        }
    }

}
