#ifndef TYPEINDEXKEYCONTAINER_HPP_INCLUDED
#define TYPEINDEXKEYCONTAINER_HPP_INCLUDED

#include <typeindex>
#include <type_traits>
#include <map>
#include <iostream>
#include <exception>
#include <memory>

namespace bm::container {

    template<typename T>
    class TypeIndexKeyContainer {
    public:
        using Container = std::map< std::type_index, std::unique_ptr<T> >;
        using iterator = typename Container::iterator;
        using const_iterator = typename Container::const_iterator;
        using value_type = typename Container::value_type;
    public:
        template<typename R> R& get() {
            isChildOfClassTemplateArg<R>();
            auto& value = *tryGetValue<R>();

            return value;
        }

        template<typename R> R* tryGetValue() {
            R* castedValue;
            try {
                auto& value = items.at(typeid(R));
                castedValue = dynamic_cast<R*>(value.get());
            }catch (const std::bad_cast& error) {
                std::cerr << error.what() << std::endl;
                throw error;
            }catch (const std::out_of_range& error) {
                std::cerr << error.what() << std::endl;
                throw error;
            }
            return castedValue;
        }

        template<typename R, typename... TArg, typename... RArg>
        void append(TArg&&... arg, RArg&&...argg ) {
            isChildOfClassTemplateArg<R>();
            auto newItem = std::make_unique<R>(std::forward<TArg>(arg)..., std::forward<RArg>(argg)... );
            std::type_index id(typeid(R));
            items.emplace( std::make_pair(id, std::move(newItem)) );
        }

        template<typename R> void remove() {
            isChildOfClassTemplateArg<R>();
            items.erase(typeid(R));
        }

        size_t size() const {
            return items.size();
        }

        iterator begin() {
            return items.begin();
        }

        iterator end() {
            return items.end();
        }


    private:
        template<typename R> void isChildOfClassTemplateArg() {
            static_assert(std::is_base_of<T, R>::value, "R is not child of T");
        }
    private:
        Container items;
    };
}


#endif // TYPEINDEXKEYCONTAINER_HPP_INCLUDED
