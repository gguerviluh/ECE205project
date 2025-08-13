#ifndef SLASH_HPP
#define SLASH_HPP

#include <SFML/Graphics.hpp>
#include "attack.hpp"
#include "config.hpp"

class Slash : public Attack {
public:
	Slash(float width, float height, sf::Color color, float rotationSpeed);

	void activate(const sf::Vector2f& playersPos, bool facingRight) override;
	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;

	void setPosition(const sf::Vector2f& pos) override;
	sf::FloatRect getBounds() const override;
	bool isColliding(const Hitbox& other) const override;

private:
        float width;
        float height;
        sf::Color color;
        float rotationSpeed;
        bool facingRight;
        sf::Vector2f playerPos;
        float currentRotation;
	float newRotation;
};

#endif // SLASH_HPP
