#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "hitbox.hpp"
#include "config.hpp"

// player.hpp (only showing relevant changes)
class Player : public Hitbox {
public:
    Player(const sf::Vector2f& pos);

    void handleInput();
    void update(float dt);
    void draw(sf::RenderWindow& window) override;

    void setPosition(const sf::Vector2f& pos) override;
    sf::FloatRect getBounds() const override;
    bool isColliding(const Hitbox& other) const override;

    int getHealth() const;
    bool isGrounded() const;
    void setGrounded(bool val);

private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    bool grounded;
    int health;

    int jumpsLeft;
    static constexpr int maxJumps = config::maxJumps; 

};


#endif // PLAYER_HPP
