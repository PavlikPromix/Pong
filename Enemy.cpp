#include "Enemy.h"

Enemy::Enemy(const sf::Vector2i &displaySize) : speed(1.0f), dSize(displaySize), shape(sf::RectangleShape(sf::Vector2f(displaySize.x * 0.4f, 10.0f)))
{
    shape.setPosition(sf::Vector2f((displaySize.x - shape.getSize().x) / 2, 0));
}

int Enemy::CollisionCheck() const
{
    if (shape.getPosition().x + shape.getSize().x > dSize.x)
        return 1;

    if (shape.getPosition().x < 0)
        return 2;
    return 0;
}

void Enemy::MoveLeft()
{
    if (CollisionCheck() == 2)
        shape.setPosition(sf::Vector2f(0, shape.getPosition().y));
    else
        shape.move(sf::Vector2f(-speed, 0));
}

void Enemy::MoveRight()
{
    if (CollisionCheck() == 1)
        shape.setPosition(sf::Vector2f(dSize.x - shape.getSize().x, shape.getPosition().y));
    else
        shape.move(sf::Vector2f(speed, 0));
}

void Enemy::Draw(sf::RenderWindow &window) const
{
    window.draw(shape);
}

void Enemy::MoveTo(sf::Vector2f position)
{
    if (shape.getPosition().x + (shape.getSize().x / 2) < position.x)
        MoveRight();
    if (shape.getPosition().x + (shape.getSize().x / 2) > position.x)
        MoveLeft();
}

const sf::Vector2f &Enemy::GetPos() const
{
    return shape.getPosition();
}