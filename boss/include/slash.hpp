#ifndef SLASH_HPP
#define SLASH_HPP

#include <SFML/Graphics.hpp>
#include "attack.hpp"
#include "config.hpp"

class Slash : public Attack {
public:
	Slash(float width, float height, sf::Color color, float rotationSpeed);

	void activate(const sf::Vector2f* playersPos, bool facingRight) override;
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
        float currentRotation;
	float newRotation;
	const sf::Vector2f* playerPosPtr = nullptr;
};

#endif // SLASH_HPP
