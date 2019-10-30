#include <SFML/Window/Event.hpp>
#include <block-maker/Debug/DebugWorld.hpp>

namespace bm::debug {

    DebugWorld::DebugWorld(b2World* worldToDebug)
    : dt(sf::seconds(1.f/60.f))
    , window(sf::VideoMode(800, 600), "Debug")
    , debugDraw{window}
    , world{worldToDebug} {
        world->SetDebugDraw(&debugDraw);
    }
    
    void DebugWorld::update() {
        sf::Time accumulator;
        sf::Clock timer;
        while (window.isOpen()) {
            sf::Event event;
            while(window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                handleInput(event); 
            }

            accumulator += timer.restart();
            while (accumulator >= dt) {
                makeStep();
                accumulator -= dt;
            }
            draw();
        }
    }
    
    void DebugWorld::makeStep() {
        int32 velocityIterations = 8;
        int32 positionIterations = 4;
        world->Step(dt.asSeconds(), velocityIterations, positionIterations);
    }
    
    void DebugWorld::draw() {
        window.clear();
        world->DrawDebugData();
        window.display();
    }

}
