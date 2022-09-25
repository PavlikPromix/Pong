#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::RectangleShape shape;
    sf::Vector2i dSize;
    float speed;

public:
    Player(const sf::Vector2i &displaySize);
    int CollisionCheck() const;
    void SetPos(int x);
    const sf::Vector2f& GetPos() const;
    void MoveLeft();
    void MoveRight();
    void Draw(sf::RenderWindow &window) const;
    inline void Restart() {shape.setPosition(sf::Vector2f((dSize.x - shape.getSize().x) / 2, dSize.y - shape.getSize().y));}
};