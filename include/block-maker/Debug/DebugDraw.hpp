#ifndef DEBUGDRAW_HPP_INCLUDED
#define DEBUGDRAW_HPP_INCLUDED

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace bm::debug {

    class DebugDraw : public b2Draw {
    private:
        sf::RenderTarget &target;
        const float PIXEL_METERS;
        const float RAD_DEGREES;
    private:
        inline sf::Color EEColor(const b2Color& gCol) {
            return sf::Color( static_cast<sf::Uint8>(255*gCol.r), static_cast<sf::Uint8>(255*gCol.g), static_cast<sf::Uint8>(255*gCol.b) );
        }
        inline sf::Vector2f EEVector(const b2Vec2& gVec){ return sf::Vector2f(gVec.x*PIXEL_METERS,gVec.y*PIXEL_METERS); }
    public:
        DebugDraw(sf::RenderTarget &target);
        void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
        void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
        void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
        void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
        void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
        void DrawTransform(const b2Transform& xf);
    };

}

#endif // DEBUGDRAW_HPP_INCLUDED
