#ifndef XMLRESOURCE_HPP_INCLUDED
#define XMLRESOURCE_HPP_INCLUDED

#include "FileResource.hpp"
#include "../../Loader/Xml/Xml.hpp"
#include <fstream>

namespace bm::binder {

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    class XmlResource : public FileResource<TContainer, T, R...> {
    public:
        XmlResource(std::string filePath)
        : FileResource<TContainer, T, R...>( std::make_unique< loader::Xml<TContainer, T, R... > >( loader::Buffer<char>( std::make_unique<std::ifstream>(filePath) )) ) {
        }
    };

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    using XmlResourcePtr = std::unique_ptr< XmlResource<TContainer, T, R...> >;

}


#endif // XMLRESOURCE_HPP_INCLUDED
