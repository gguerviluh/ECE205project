#ifndef HITBOX_HPP
#define HITBOX_HPP

#include <SFML/Graphics.hpp>

class Hitbox {
public:
    virtual ~Hitbox() {}
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void setPosition(const sf::Vector2f& pos) = 0;
    virtual sf::FloatRect getBounds() const = 0;
    virtual bool isColliding(const Hitbox& other) const = 0;
};

#endif // HITBOX_HPP
