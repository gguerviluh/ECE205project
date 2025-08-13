#ifndef ATTACK_HPP
#define ATTACK_HPP

#include "hitbox.hpp"
#include <SFML/Graphics.hpp>
#include "config.hpp"

class Attack : public Hitbox {
public:
    Attack() : active(false) {}
    virtual ~Attack() = 0;

    virtual void activate(const sf::Vector2f& playerPos, bool facingRight) = 0;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) override = 0;

    void setPosition(const sf::Vector2f& pos) override =0;
    sf::FloatRect getBounds() const override = 0;
    bool isColliding(const Hitbox& other) const override = 0;

    virtual bool isActive() const {return active;}
protected:
    sf::RectangleShape hitboxShape;
    bool active;
};
inline Attack::~Attack() {}

#endif // ATTACK_HPP

