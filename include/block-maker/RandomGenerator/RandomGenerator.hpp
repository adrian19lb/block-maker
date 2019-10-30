#ifndef RANDOMGENERATOR_HPP_INCLUDED
#define RANDOMGENERATOR_HPP_INCLUDED

#include <random>
#include <algorithm>

namespace bm {

    class RandomGenerator {
    public:
        RandomGenerator()
        : rd()
        , seed{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()}
        , engine(seed) {
        }
        template<typename T>
        T generateRandomNumber(T upperBound, T lowerBound = 0) {
            std::uniform_int_distribution<> distribution(lowerBound, upperBound);

            return distribution(engine);
        }

        template<typename T>
        typename T::const_iterator generateRandomIterator(const T& container) {
            int number = generateRandomNumber(container.size() - 1);
            auto item = container.begin();
            std::advance(item, number);

            return item;
        }

        template<typename T>
        T generateRandomIterator(T begin, T end) {
            auto d = std::distance(begin, end);
            auto n = generateRandomNumber(d - 1);
            std::advance(begin, n);

            return begin;
        }
    private:
        std::random_device rd;
        std::seed_seq seed;
        std::mt19937 engine;
    };
}

#endif // RANDOMGENERATOR_HPP_INCLUDED
