#ifndef DEBUGWORLD_HPP_INCLUDED
#define DEBUGWORLD_HPP_INCLUDED

#include <block-maker/Debug/DebugDraw.hpp>
#include <SFML/System/Time.hpp>

namespace bm::debug {

    class DebugWorld {
    public:
        void update();
    protected:
        DebugWorld(b2World* worldToDebug);

        virtual void draw();

        virtual void handleInput(sf::Event event) = 0;

    private:
        void makeStep();
    private:
        const sf::Time dt;
        sf::RenderWindow window;
        DebugDraw debugDraw;
        b2World* world;
    };


}

#endif // DEBUGWORLD_HPP_INCLUDED
