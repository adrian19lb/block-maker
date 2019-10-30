namespace bm::loader {

    template<typename T> Buffer<T>::Buffer(istream_ptr stream)
    : buffer() {
        tryMoveStreamResources( stream.get() );
    }

    template<typename T> Buffer<T>::Buffer(Buffer<T>&& buf) {
        this->buffer.swap(buf.buffer);
    }

    template<typename T> Buffer<T>::Buffer(const Buffer<T>& buf) {
        this->buffer = buf.buffer;
    }

    template<typename T> Buffer<T>& Buffer<T>::operator=(const Buffer<T>& buf) {
        this->buffer = buf.buffer;
        return *this;
    }

    template<typename T> Buffer<T>& Buffer<T>::operator=(Buffer<T>&& buf) {
        this->buffer.swap(buf.buffer);
        return *this;
    }

    template<typename T> void Buffer<T>::tryMoveStreamResources(std::istream* stream) {
        try {
            stream->exceptions(std::istream::badbit);
            std::move(std::istream_iterator<T>(*stream), std::istream_iterator<T>(), std::back_inserter<std::vector<T>>(buffer) );
        }catch (const std::ios_base::failure& error) {
            std::cerr << "Fail to move from stream to buffer. " << error.what() << std::endl;
            throw;
        }
    }

    template<typename T> typename Buffer<T>::iterator Buffer<T>::begin() {
        return buffer.begin();
    }

    template<typename T> typename Buffer<T>::iterator Buffer<T>::end() {
        return buffer.end();
    }

    template<typename T> T& Buffer<T>::front() {
        return buffer.at(0);
    }

    template<typename T> T& Buffer<T>::back() {
        int lastIndex = buffer.size() - 1;
        return buffer.at(lastIndex);
    }

    template<typename T>
    template<typename... R>
    void Buffer<T>::append(R&&... values) {
        tryPerfectForwardAppend( std::forward<R>(values)... );
    }

    template<typename T>
    template<typename... R>
    void Buffer<T>::tryPerfectForwardAppend(R&&... values) {
        try {
            int dummy[] = { 0, (buffer.emplace_back( std::forward<T>(boost::lexical_cast<T>(values)) ), 0)... };
        }catch(boost::bad_lexical_cast& error) {
            std::cerr << error.what() << std::endl;
            throw;
        }
    }
    template<typename T>
    void Buffer<T>::appendFromFiles(std::initializer_list<std::string> filePaths) {
        for (auto& i : filePaths) {
            auto stream = std::move( std::make_unique<std::ifstream>(i) );
            tryMoveStreamResources( stream.get() );
        }
    }

    template<typename T> void Buffer<T>::clear() {
        buffer.clear();
    }

    template<typename T> size_t Buffer<T>::size() {
        return buffer.size();
    }
}
