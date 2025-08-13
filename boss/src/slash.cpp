#include <SFML/Graphics.hpp> 
#include "slash.hpp"
#include "config.hpp"

Slash::Slash(float width, float height, sf::Color color, float rotationSpeed) :
width(width), height(height), color(color), rotationSpeed(rotationSpeed), facingRight(true), currentRotation(0.f), newRotation(0.f){ 
	hitboxShape.setSize(sf::Vector2f(width, height));
	hitboxShape.setFillColor(sf::Color(0,0,0,0));
	hitboxShape.setPosition(sf::Vector2f(0.f, 0.f));
}
void Slash::activate(const sf::Vector2f& playerPos, bool facingRight) {
        this->playerPos = playerPos;
        this->facingRight = facingRight;
	if (facingRight) {
		hitboxShape.setPosition(playerPos.x + config::playerWidth, playerPos.y);
		hitboxShape.setFillColor(color);
		active = true;
	}
	else if (!facingRight) {
		hitboxShape.setPosition(playerPos.x - width ,playerPos.y);
		hitboxShape.setFillColor(color);
		active = true;
	}
}

void Slash::update(float dt) {
	if (active and facingRight) {
		currentRotation = hitboxShape.getRotation();
		hitboxShape.setRotation(0.f);
		hitboxShape.setOrigin({0.f,0.f});
		hitboxShape.setPosition(playerPos.x + config::playerWidth, playerPos.y);
		hitboxShape.setOrigin({0.f, hitboxShape.getSize().y});
		hitboxShape.setRotation(currentRotation);
		newRotation = currentRotation + rotationSpeed * dt;
		if (newRotation >= 90.f) { 
			hitboxShape.setRotation(90.f);
			active = false;
		}
		else {
			hitboxShape.setRotation(newRotation);
		}
	}
	if (active and !facingRight) {
		currentRotation  = hitboxShape.getRotation();
		hitboxShape.setRotation(0.f);
		hitboxShape.setOrigin({0.f,0.f});
		hitboxShape.setPosition(playerPos.x + config::playerWidth, playerPos.y);
		hitboxShape.setOrigin({hitboxShape.getSize().x, hitboxShape.getSize().y});
		hitboxShape.setRotation(currentRotation);
		newRotation = currentRotation - rotationSpeed * dt;
		if (newRotation <= -90.f) {
                        hitboxShape.setRotation(-90);
                        active = false;
		}
		else { 
			hitboxShape.setRotation(newRotation);
		}
	}
	if(!active) {
		hitboxShape.setRotation(0.f);
		hitboxShape.setOrigin({0.f, 0.f});
	}
}
void Slash::draw(sf::RenderWindow& window) { 
	if (active) { 
		window.draw(hitboxShape);
	}
}

void Slash::setPosition(const sf::Vector2f& pos) { 
	hitboxShape.setPosition(pos);
}
sf::FloatRect Slash::getBounds() const { 
	return hitboxShape.getGlobalBounds();
}
bool Slash::isColliding(const Hitbox& other) const { 
	return getBounds().intersects(other.getBounds());
}

