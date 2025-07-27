#ifndef HEALTHBAR_HPP
#define HEALTHBAR_HPP

#include<SFML/Graphics.hpp>
#include "config.hpp"

class Healthbar {
public:
	//int* const prevents pointer from being changed, value can still be changed 
	Healthbar(int* const health, const sf::Vector2f& pos);
	void draw(sf::RenderWindow& window);
private:
	int* health;
	int maxHealth;
	static constexpr float maxWidth = config::healthbarWidth;
	static constexpr float maxHeight = config::healthbarHeight;

	sf::RectangleShape backgroundBar;
	sf::RectangleShape frontBar;
	sf::Vector2f pos;
};

#endif // HEALTHBAR_HPP
