#ifndef NODESEEKER_HPP_INCLUDED
#define NODESEEKER_HPP_INCLUDED

#include <cassert>

namespace bm::loader {

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    class Xml<TContainer, T, R...>::NodeSeeker {
    public:
        NodeSeeker(rapidxml::xml_node<>* root);
        void changeRoot(rapidxml::xml_node<>* root);
        rapidxml::xml_node<>* findNode(std::string&& nodeName);
    private:
        rapidxml::xml_node<>* tryFindValueByNodeName(rapidxml::xml_node<>* node, const char* nodeName);
        void seekNodeIfParentExist(rapidxml::xml_node<>* node, const char* nodeName);
    private:
        rapidxml::xml_node<>* mRoot;
    };

}

#include <block-maker/Loader/Xml/NodeSeeker.inl>

#endif // NODESEEKER_HPP_INCLUDED
