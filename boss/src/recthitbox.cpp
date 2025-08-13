#include <SFML/Graphics.hpp>
#include "hitbox.hpp"
class RectangleHitbox : public Hitbox {
public:
	RectangleHitbox(const sf::Vector2f& size) {
        shape.setSize(size);
        shape.setFillColor(sf::Color(255, 0, 0, 100)); // semi-transparent for debug
    }

    void draw(sf::RenderWindow& window) override {
        window.draw(shape);
    }

    void setPosition(const sf::Vector2f& pos) override {
        shape.setPosition(pos);
    }

    sf::FloatRect getBounds() const override {
        return shape.getGlobalBounds();
    }

    bool isColliding(const Hitbox& other) const override {
        return getBounds().intersects(other.getBounds());
    }

private:
    sf::RectangleShape shape;
};

