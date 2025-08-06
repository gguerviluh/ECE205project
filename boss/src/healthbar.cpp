#include "healthbar.hpp"

Healthbar::Healthbar(int* const health, const sf::Vector2f& pos) :health(health), maxHealth(*health), pos(pos) {
	printf("in healthbar constructor\n");
	backgroundBar.setSize(sf::Vector2f(config::healthbarWidth + 10, config::healthbarHeight +10));
	backgroundBar.setFillColor(sf::Color(128, 128,128));
	backgroundBar.setPosition(pos);

	frontBar.setSize(sf::Vector2f(config::healthbarWidth, config::healthbarHeight));
	frontBar.setFillColor(sf::Color::Red);
	frontBar.setPosition(pos);
	printf("%f %f", frontBar.getSize().x, backgroundBar.getSize().x);
}

void Healthbar::update() {
	frontBar.setSize(sf::Vector2f(((static_cast<float>(*health)/maxHealth) * maxWidth), maxHeight));
	frontBar.setPosition(pos);
}

void Healthbar::setPosition(const sf::Vector2f& pos) {
 	frontBar.setPosition(pos);
	backgroundBar.setPosition(pos);
}

void Healthbar::draw(sf::RenderWindow& window) {
	window.draw(backgroundBar);
	window.draw(frontBar);
}
