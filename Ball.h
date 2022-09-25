#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

class Ball
{
private:
    sf::CircleShape shape;
    sf::Vector2f moveAngle;
    sf::Vector2i dSize;
    const float acceleration = 0.4f;

public:
    Ball(const sf::Vector2i &displaySize);
    void SetAngle(const sf::Vector2f &angle);
    const sf::Vector2f &GetAngle() const;

    void SetPos(const sf::Vector2f &pos);
    const sf::Vector2f &GetPos() const;

    void CollisionCheck(const sf::Vector2f &playerPos);
    void Draw(sf::RenderWindow &window) const;
    void Move(const sf::Vector2f &positions);
    void SpeedUp();
    inline void Restart()
    {
        srand(time(NULL));
        shape.setPosition(sf::Vector2f(dSize.x / 2, dSize.y / 2));
        const float direction[5] = {0.0f, 1.0f, -1.0f, 1.5f, -1.5f};
        SetAngle(sf::Vector2f(direction[rand() % 5], direction[rand() % 4 + 1]));
    }
};