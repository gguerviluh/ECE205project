#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "config.hpp"
#include "boss.hpp"
#include "healthbar.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(config::windowWidth, config::windowHeight), "Platformer Boss Fight");
    window.setFramerateLimit(60);

    Player player(sf::Vector2f(100, config::groundY - config::playerHeight));
    Healthbar playerHealth(player.getHealthPtr(), sf::Vector2f(0, 100));

    Boss boss(sf::Vector2f(1800, config::groundY -config::bossHeight));
    Healthbar bossHealth(boss.getHealthPtr(), sf::Vector2f(800, 0));
    sf::Clock clock;
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.handleInput();
        player.update(dt);
	boss.update(dt);

	playerHealth.update();
	bossHealth.update();

        window.clear(sf::Color::Black);

        // Draw ground
        sf::RectangleShape ground(sf::Vector2f(config::windowWidth, 10));
        ground.setPosition(0, config::groundY);
        ground.setFillColor(sf::Color::Green);
        window.draw(ground);

        // Draw player
        player.draw(window);
	playerHealth.draw(window);

	//Draw boss
	boss.draw(window);
	bossHealth.draw(window);

        window.display();
    }
    return 0;
}
