#include "Player.h"

Player::Player(const sf::Vector2i &displaySize) : dSize(displaySize), shape(sf::RectangleShape(sf::Vector2f(displaySize.x * 0.4f, 10.0f))), speed(3.0f)
{
    shape.setPosition(sf::Vector2f((displaySize.x - shape.getSize().x) / 2, displaySize.y - shape.getSize().y));
}

int Player::CollisionCheck() const
{
    if (shape.getPosition().x + shape.getSize().x > dSize.x)
        return 1;

    if (shape.getPosition().x < 0)
        return 2;
    return 0;
}

void Player::MoveLeft()
{
    if (CollisionCheck() == 2)
        shape.setPosition(sf::Vector2f(0, shape.getPosition().y));
    else
        shape.move(sf::Vector2f(-speed, 0));
}

void Player::MoveRight()
{
    if (CollisionCheck() == 1)
        shape.setPosition(sf::Vector2f(dSize.x - shape.getSize().x, shape.getPosition().y));
    else
        shape.move(sf::Vector2f(speed, 0));
}

void Player::Draw(sf::RenderWindow &window) const
{
    window.draw(shape);
}

void Player::SetPos(int x)
{
    shape.setPosition(sf::Vector2f(x, shape.getPosition().y));
}

const sf::Vector2f &Player::GetPos() const
{
    return shape.getPosition();
}