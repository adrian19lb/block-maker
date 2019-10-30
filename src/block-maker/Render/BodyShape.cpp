#include <block-maker/Render/BodyShape.hpp>

namespace bm::render {
        
    BodyShape::BodyShape(ShapeCompoisteFactory* shapeCreator, b2Body* bodyToRender)
    : bodyToRender{bodyToRender}
    , renderableShapeFactory{shapeCreator}
    , bodyRenderShape{shapeCreator->create(bodyToRender)} {
        setFillColor(sf::Color(sf::Color::Red));
        setOutlineThickness(-0.005);
        setScale();
    }

  
        void BodyShape::setTexture(const sf::Texture& texture)  {
            bodyRenderShape->setTexture(texture);
        }

        void BodyShape::setFillColor(sf::Color&& color)  {
            bodyRenderShape->setFillColor( std::forward<sf::Color>(color) );
        }

        void BodyShape::setOutlineColor(sf::Color&& color)  {
            bodyRenderShape->setOutlineColor( std::forward<sf::Color>(color) );
        }

        void BodyShape::setOutlineThickness(float thickness)  {
            bodyRenderShape->setOutlineThickness(thickness);
        }
   
        void BodyShape::setScale(float sx, float sy) {
            scale.x = sx;
            scale.y = sy;
        }

        void BodyShape::changeBody(b2Body* body) {
            bodyToRender = body;
        }

        void BodyShape::update() {
            bodyRenderShape =  renderableShapeFactory->create(bodyToRender) ;
        }

    
        void BodyShape::draw(sf::RenderTarget& target, sf::RenderStates states) const  {
            states.transform.scale(scale);
            target.draw(*bodyRenderShape, states);
        }
}
