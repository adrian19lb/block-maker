#include <SFML/Window/Event.hpp>
#include <boost/test/unit_test.hpp>
#include <block-maker/Debug/DebugWorld.hpp>
#include <block-maker/Physic/RandomBlockSpawner.hpp>
#include <deque>

namespace bm::testing {
    
    class DebugBlocksTest : public debug::DebugWorld {
    public:
        DebugBlocksTest(b2World* world)
        : DebugWorld(world)
        , world(world)
        , spawner(std::make_unique<physic::RandomBlockSpawner>(world)) {
            blocks.emplace_front(spawner->createBlock(b2Vec2(2.5f, 0.f)));
        }

        Block* createBlock(b2Vec2 position) {
            blocks.emplace_front(spawner->createBlock(position));

            return blocks.front().get();
        }

        void createRectStaticBody(b2Vec2 position, b2Vec2 size) {
            b2BodyDef bodyDef;
            bodyDef.type = b2BodyType::b2_staticBody;
            bodyDef.position.Set(position.x, position.y);
            auto groundBody = world->CreateBody(&bodyDef);
            b2PolygonShape polygon;
            polygon.SetAsBox(size.x, size.y);
            groundBody->CreateFixture(&polygon, 0.f);
        }
     protected:
        void handleInput(sf::Event event) override {
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
                blocks.front()->moveLeft(1.f);
            }else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
                blocks.front()->moveRight(1.f);
            }else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
                blocks.emplace_front(spawner->createBlock(b2Vec2(2.5f, 0.f)));
            }else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                popBackBlockIfNotEmpty();
            }
        }
    private:
        void popBackBlockIfNotEmpty() {
            if (!blocks.empty()) {
                world->DestroyBody(blocks.back()->getBody());
                blocks.pop_back();
            }
        }

    private:
        b2World* world;
        std::unique_ptr<bm::physic::BlockSpawner> spawner;
        std::deque<std::unique_ptr<Block>> blocks;
    };

    
    BOOST_AUTO_TEST_SUITE(LibIntegrationTest)
    BOOST_AUTO_TEST_CASE(testRandomBlockCreation) {
        b2Vec2 gravity(0.f, 1.f);
        b2World world(gravity);
        DebugBlocksTest debuger(&world);
        
        debuger.createRectStaticBody(b2Vec2(0.f, 4.f), b2Vec2(10.f, 0.1f));
        debuger.createRectStaticBody(b2Vec2(0.f, 4.f), b2Vec2(0.1f, 8.f));
        debuger.createRectStaticBody(b2Vec2(5.32f, 0.f), b2Vec2(0.1f, 8.f));
        debuger.update();
    }
    BOOST_AUTO_TEST_SUITE_END()



}
