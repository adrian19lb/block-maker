#ifndef BLOCK_HPP_INCLUDED
#define BLOCK_HPP_INCLUDED

#include <SFML/Graphics/Drawable.hpp>
#include <block-maker/Render/BodyShape.hpp>

namespace bm {
    
    class Block : public sf::Drawable {
    public:
        Block(b2Body* body, std::unique_ptr<render::BodyShape> shape);
        
        void moveLeft(float x);

        void moveRight(float x);

        void moveDown(float y);

        void moveUp(float y);

        void update();

        b2Body* getBody() const;

        void freeze();
    private:
        void stop();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    private:
        b2Body* body;
        std::unique_ptr<render::BodyShape> shape;
    };

}

#endif // BLOCK_HPP_INCLUDED
