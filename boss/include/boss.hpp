#ifndef BOSS_HPP
#define BOSS_HPP

#include<SFML/Graphics.hpp>
#include "hitbox.hpp"
#include "config.hpp"
#include "attack.hpp"
#include "slash.hpp"

class Boss : public Hitbox {
public:
    Boss(const sf::Vector2f& pos);

    void jump();
    void update(float dt);
    void draw(sf::RenderWindow& window) override;

    void setPosition(const sf::Vector2f& pos) override;
    sf::FloatRect getBounds() const override;
    bool isColliding(const Hitbox& other) const override;

    int getHealth() const;
    bool isGrounded() const;
    void setGrounded(bool val);
    int* getHealthPtr();
    void takeDamage(int damage);

private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    bool grounded;
    int health;

    int jumpsLeft;
    static constexpr int maxJumps = config::bossMaxJumps;  

};

#endif // BOSS_HPP
