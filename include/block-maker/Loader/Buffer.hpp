#ifndef BUFFER_HPP_INCLUDED
#define BUFFER_HPP_INCLUDED

#include <istream>
#include <vector>
#include <iterator>
#include <iostream>
#include <initializer_list>
#include <boost/lexical_cast.hpp>

namespace bm::loader {

    using istream_ptr = std::unique_ptr<std::istream>;

    template <typename T>
    class Buffer {
        using iterator = typename std::vector<T>::iterator;
    public:
        Buffer() = delete;
        ~Buffer() = default;
        Buffer(Buffer&& buffer);
        Buffer(const Buffer& buffer);
        Buffer& operator=(Buffer&& buffer);
        Buffer& operator=(const Buffer& buffer);
        Buffer(istream_ptr stream);
    private:
        void tryMoveStreamResources(std::istream* stream);
    public:
        template<typename... R>
        void append(R&&... values);
    private:
        template<typename... R>
        void tryPerfectForwardAppend(R&&... values);
    public:
        void appendFromFiles(std::initializer_list<std::string> filePaths);
        template<typename... R>
        std::istream& operator<<(R&&... values);
        iterator begin();
        iterator end();
        T& front();
        T& back();
        void clear();
        size_t size();
    private:
        std::vector<T> buffer;
    };

}

#include <block-maker/Loader/Buffer.inl>

#endif // BUFFER_HPP_INCLUDED
