#ifndef BODYSHAPE_HPP_INCLUDED
#define BODYSHAPE_HPP_INCLUDED

#include <block-maker/Render/Renderable.hpp>
#include <block-maker/Render/ShapeCompositeFactory/ShapeCompositeFactory.hpp>
#include <Box2D/Dynamics/b2Body.h>

namespace bm::render {

    class BodyShape : public Renderable {
    public:
        BodyShape(ShapeCompoisteFactory* shapeCreator, b2Body* bodyToRender);
    public:
        void setTexture(const sf::Texture& texture) override;

        void setFillColor(sf::Color&& color) override;

        void setOutlineColor(sf::Color&& color) override;

        void setOutlineThickness(float thickness) override;
    public:
        void setScale(float sx = 20.f, float sy = 20.f);

        void changeBody(b2Body* body);

        void update();
    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    private:
        b2Body* bodyToRender;
        ShapeCompoisteFactory* renderableShapeFactory;
        ShapeCompositePtr bodyRenderShape;
        sf::Vector2f scale;
    };

}

#endif // BODYSHAPE_HPP_INCLUDED
