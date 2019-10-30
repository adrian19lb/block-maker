#include <block-maker/Debug/DebugDraw.hpp>

namespace bm::debug {

    DebugDraw::DebugDraw(sf::RenderTarget &target)
    : target{target}
    , PIXEL_METERS(150.f)
    , RAD_DEGREES(57.2957795f) {
        SetFlags(e_shapeBit | e_jointBit | e_centerOfMassBit /*| e_aabbBit*/);
        // SetFlags(0xFFFF);
    }

    void DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
        sf::ConvexShape polygon(vertexCount);
        polygon.setOutlineThickness(1.f);
        polygon.setOutlineColor( EEColor(color) );
        polygon.setFillColor( sf::Color::Transparent );
        for (int32 i = 0; i < vertexCount; ++i) {
            polygon.setPoint( i, EEVector(vertices[i] ));
        }
        target.draw(polygon);
    }
    void DebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
        sf::ConvexShape polygon(vertexCount);
        polygon.setOutlineThickness(1.f);
        polygon.setFillColor( EEColor(color) );
        for (int32 i = 0; i < vertexCount; ++i) {
            polygon.setPoint(i, EEVector(vertices[i]) );
        }
        target.draw(polygon);
    }
    void DebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {
        sf::CircleShape circle{ radius*PIXEL_METERS };
        circle.setOutlineColor( EEColor(color) );
        circle.setOutlineThickness(1.f);
        circle.setFillColor(sf::Color::Transparent);
        circle.setOrigin( sf::Vector2f(radius * PIXEL_METERS, radius * PIXEL_METERS) );
        circle.setPosition( EEVector(center) );
        target.draw(circle);
    }
    void DebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {
        sf::CircleShape circle{ radius*PIXEL_METERS };
        circle.setOutlineColor( EEColor(color) );
        circle.setOutlineThickness(1.f);
        circle.setFillColor( EEColor(color) );
        circle.setOrigin( sf::Vector2f(radius * PIXEL_METERS, radius * PIXEL_METERS) );
        circle.setPosition( EEVector(center) );
        target.draw(circle);
    }
    void DebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
        sf::VertexArray line(sf::PrimitiveType::Lines, 2);
        sf::Vertex begin( EEVector(p1), EEColor(color) );
        sf::Vertex end( EEVector(p2), EEColor(color) );
        line.append(begin);
        line.append(end);
        target.draw(line);
    }
    void DebugDraw::DrawTransform(const b2Transform& xf) {

    }
}
