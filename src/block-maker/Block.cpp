#include <block-maker/Block.hpp>

namespace bm {
        
    Block::Block(b2Body* body, std::unique_ptr<render::BodyShape> shape)
    : body(body)
    , shape(std::move(shape)) {
            
    }

    void Block::moveLeft(float x) {
        body->SetLinearVelocity(b2Vec2(-x, 0.f));
    }

    void Block::moveRight(float x) {
        body->SetLinearVelocity(b2Vec2(x, 0.f));
    }
    
    void Block::moveDown(float y) {
        body->ApplyAngularImpulse(-y, true);
    }

    void Block::moveUp(float y) {
        body->SetLinearVelocity(b2Vec2(0.f, y));
    }

    void Block::stop() {
        body->SetLinearVelocity(b2Vec2(0.f, 0.f));
    }
        
    b2Body* Block::getBody() const {
       return body;
    }
        
    void Block::update() {
        stop();
        shape->update(); 
    }

    void Block::freeze() {
        body->SetGravityScale(0.f); 
    }

    void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(*shape, states); 
    }

}
