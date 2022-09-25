#include "Ball.h"

Ball::Ball(const sf::Vector2i &displaySize)
{
    srand(time(NULL));
    shape = sf::CircleShape(10.0f);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(sf::Vector2(5.0f, 5.0f));
    shape.setPosition(sf::Vector2f(displaySize.x / 2, displaySize.y / 2));

    const float direction[5] = {0.0f, 1.0f, -1.0f, 1.5f, -1.5f};
    SetAngle(sf::Vector2f(direction[rand() % 5], direction[rand() % 4 + 1]));
    dSize = displaySize;
}

void Ball::SetAngle(const sf::Vector2f &angle) { moveAngle = angle; }

const sf::Vector2f &Ball::GetAngle() const { return moveAngle; }

void Ball::SetPos(const sf::Vector2f &pos) { shape.setPosition(pos); }

const sf::Vector2f &Ball::GetPos() const { return shape.getPosition(); }

void Ball::CollisionCheck(const sf::Vector2f &playerPos)
{
    if (GetPos().x < 5)
    {
        SetPos(sf::Vector2f(5.0f, GetPos().y));
        SetAngle(sf::Vector2f(-GetAngle().x, GetAngle().y));
    }
    if (GetPos().x > dSize.x - 10)
    {
        SetPos(sf::Vector2f(dSize.x - 10, GetPos().y));
        SetAngle(sf::Vector2f(-GetAngle().x, GetAngle().y));
    }
    if (GetPos().x > playerPos.x - 8 && GetPos().x < playerPos.x + dSize.x + 8 * 0.4f && GetPos().y > dSize.y - 20 && GetPos().y < dSize.y)
    { // Player collision detected
        SetPos(sf::Vector2f(GetPos().x, dSize.y - 20));
        float centerx = playerPos.x + (dSize.x * 0.2f);
        float quatersize = (centerx - playerPos.x) / 4;
        if (GetPos().x == centerx)
            SetAngle(sf::Vector2f(0, -GetAngle().y));
        else
            SetAngle(sf::Vector2f(GetPos().x < centerx ? -((centerx - GetPos().x) / quatersize) : (GetPos().x - centerx) / quatersize, -GetAngle().y));
        SpeedUp();
        // std::cout << moveAngle.y << ' ' << GetAngle().x << '\n';
    }
    if (GetPos().x > playerPos.y && GetPos().x < playerPos.y + dSize.x * 0.4f && GetPos().y < 10 && GetPos().y > 0)
    { // Enemy collision detected
        SetPos(sf::Vector2f(GetPos().x, 10));
        float centerx = playerPos.y + (dSize.x * 0.2f);
        float quatersize = (centerx - playerPos.y) / 4;
        if (GetPos().x == centerx)
            SetAngle(sf::Vector2f(0, -GetAngle().y));
        else
            SetAngle(sf::Vector2f(GetPos().x < centerx ? -((centerx - GetPos().x) / quatersize) : (GetPos().x - centerx) / quatersize, -GetAngle().y));
        // std::cout << moveAngle.y << ' ' << GetAngle().x << '\n';
    }
}

void Ball::Draw(sf::RenderWindow &window) const
{
    window.draw(shape);
}

void Ball::Move(const sf::Vector2f &positions)
{
    CollisionCheck(positions);
    shape.move(moveAngle);
}

void Ball::SpeedUp()
{
    SetAngle(sf::Vector2f(GetAngle().x, GetAngle().y - acceleration));
}
