#include "player.hpp"

Player::Player(const sf::Vector2f& pos) : slash(config::playerSlashWidth, config::playerSlashHeight, sf::Color::White, config::playerSlashRotSpeed), grounded(false), health(600), jumpsLeft(maxJumps), facingRight(true){
    shape.setSize(sf::Vector2f(config::playerWidth, config::playerHeight));
    shape.setFillColor(sf::Color::Red);
    setPosition(pos);
    velocity = sf::Vector2f(0.f, 0.f);
}

void Player::handleInput() {
    float vx = 0.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) vx -= config::playerSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) vx += config::playerSpeed;
    velocity.x = vx;

    // Double Jump: allow up to maxJumps, only if jump key was *just* pressed
    static bool jumpHeld = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (!jumpHeld && jumpsLeft > 0) {
            velocity.y = -config::jumpStrength;
            grounded = false;
            jumpsLeft--;
        }
        jumpHeld = true;
    } else {
        jumpHeld = false;
    }
    // Slash activation
    static bool slashHeld = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
        if (!slashHeld && !slash.isActive()) {
            slash.activate(shape.getPosition(), facingRight);
        }
        slashHeld = true;
    } else {
        slashHeld = false;
    }
}

void Player::update(float dt) {
    if (!grounded) velocity.y += config::gravity * dt;
    shape.move(velocity * dt);

    if (shape.getPosition().y + shape.getSize().y >= config::groundY) {
        shape.setPosition(shape.getPosition().x, config::groundY - shape.getSize().y);
        velocity.y = 0.f;
        grounded = true;
        jumpsLeft = maxJumps; // Reset double jump on landing!
    } else {
        grounded = false;
    }
    slash.update(dt);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
    slash.draw(window);
}

void Player::setPosition(const sf::Vector2f& pos) {
    shape.setPosition(pos);
}

sf::FloatRect Player::getBounds() const {
    return shape.getGlobalBounds();
}

bool Player::isColliding(const Hitbox& other) const {
    return getBounds().intersects(other.getBounds());
}

void Player::takeDamage(int damage) {
       	health -= damage;
	if (health < 0) {
		health = 0;
	}
}
int Player::getHealth() const { return health; }
bool Player::isGrounded() const { return grounded; }
void Player::setGrounded(bool val) { grounded = val; }
int*  Player::getHealthPtr() { return &health;}

