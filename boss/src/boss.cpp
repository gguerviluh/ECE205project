#include "boss.hpp"

Boss::Boss(const sf::Vector2f& pos) : grounded(false), health(10000), jumpsLeft(maxJumps) {
    shape.setSize(sf::Vector2f(config::bossWidth, config::bossHeight));
    shape.setFillColor(sf::Color::Blue);
    setPosition(pos);
    velocity = sf::Vector2f(0.f, 0.f);
}

void Boss::jump() {
    if (jumpsLeft > 0) {
        velocity.y = -config::bossJumpStrength;
        grounded = false;
        --jumpsLeft;
    }
}

void Boss::update(float dt) {
	if (!grounded) velocity.y += config::gravity * dt;
	shape.move(velocity * dt);

	if(shape.getPosition().y + shape.getSize().y >= config::groundY) {
		shape.setPosition(shape.getPosition().x, config::groundY - shape.getSize().y);		
		velocity.y = 0.f;
		grounded = true;
		jumpsLeft = maxJumps;
	}else{ 
		grounded = false;
	}
}

void Boss::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

void Boss::setPosition(const sf::Vector2f& pos) {
	shape.setPosition(pos);
}

sf::FloatRect Boss::getBounds() const {
    return shape.getGlobalBounds();
}

bool Boss::isColliding(const Hitbox& other) const {
    return getBounds().intersects(other.getBounds());
}

int Boss::getHealth() const { return health; }
bool Boss::isGrounded() const { return grounded; }
void Boss::setGrounded(bool val) { grounded = val; }
