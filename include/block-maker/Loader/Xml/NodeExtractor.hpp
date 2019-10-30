#ifndef NODEEXTRACTOR_HPP_INCLUDED
#define NODEEXTRACTOR_HPP_INCLUDED

#include <type_traits>

namespace bm::loader {

    template< template<typename... TArg> class TContainer, typename T, typename... R >
    class Xml<TContainer, T, R...>::NodeExtractor {
        template<typename U>
        using Enable_If_Map = typename File< TContainer, T, R...>::template Enable_If_Map<U>;
        template<typename U>
        using Enable_If_Not_Map = typename File< TContainer, T, R...>::template Enable_If_Not_Map<U>;
    public:
        NodeExtractor(rapidxml::xml_node<>* root)
        : root{root} {
        }

        template<typename U = Container, typename Enable_If_Map<U>::type* = nullptr> Container extract() {
        Container values;
            for (auto i = root->first_node(); i; i = i->next_sibling()) {
                T key = i->name();
                auto value = tryCastValue< std::common_type_t<R...> >( i->value() );
                values.emplace( std::make_pair(key, value) );
            }

            return std::move(values);
        }

    private:
        template<typename U> U tryCastValue(const std::string& chars) {
            U value;
            try {
                float basicValue = boost::lexical_cast<float>(chars);
                value = static_cast<U>(basicValue);

            }catch (const boost::bad_lexical_cast& error) {
                std::cerr << error.what() << std::endl;
            }
            return value;
        }

    public:
        template<typename U = Container, typename Enable_If_Not_Map<U>::type* = nullptr>
        Container extract() {
            Container values;
            for (auto i = root->first_node(); i; i = i->next_sibling()) {
                auto value = tryCastValue<T>( i->value() );
                values.insert(values.end(), value);
            }

            return std::move(values);
        }

        std::vector<std::string> extractNames() {
            std::vector<std::string> names;
            for (auto i = root->first_node(); i; i = i->next_sibling()) {
                std::string name = i->name();
                names.emplace_back(name);
            }
            return names;
        }
    private:
        rapidxml::xml_node<>* root;
    };
}

#include <block-maker/Loader/Xml/NodeExtractor.inl>
#endif // NODEEXTRACTOR_HPP_INCLUDED
