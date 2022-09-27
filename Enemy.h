#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"

class Enemy
{
private:
    float speed;
    sf::RectangleShape shape;
    sf::Vector2i dSize;

public:
    Enemy(const sf::Vector2i &displaySize);
    int CollisionCheck() const;
    const sf::Vector2f& GetPos() const;
    void MoveLeft();
    void MoveRight();
    void MoveTo(sf::Vector2f position);
    void Draw(sf::RenderWindow &window) const;
    inline void Restart() {shape.setPosition(sf::Vector2f((dSize.x - shape.getSize().x) / 2, 0));}
    inline void SpeedUp(float ratio) { speed *= ratio; }
};