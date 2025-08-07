#include "bosspage.hpp"
#include "appmanager.hpp"
#include "startpage.hpp"
#include <iostream>

Page2::Page2() :
    ground(sf::Vector2f(config::windowWidth, 10)),
    boss(sf::Vector2f(1800.f, config::groundY - config::bossHeight)),
    bossHealth(boss.getHealthPtr(), sf::Vector2f(760,803)),
    player(sf::Vector2f(100, config::groundY - config::playerHeight)),
    playerHealth(player.getHealthPtr(), sf::Vector2f(100,3))
    {
    ground.setPosition(0 , config::groundY);
    ground.setFillColor(sf::Color::Green);
    font.loadFromFile("arial.ttf");
    
    backBtn.setFont(font);
    backBtn.setString("Back");
    backBtn.setCharacterSize(24);
    backBtn.setFillColor(sf::Color::Red);
    backBtn.setPosition(100, 800);
}

bool Page2::isClicked(const sf::Text& btn, sf::Vector2f pos) {
    return btn.getGlobalBounds().contains(pos);
}

void Page2::handleEvent(sf::Event& event, sf::RenderWindow& window, float dt) {
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left) {
        auto mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
        if (isClicked(backBtn, mousePos)) {
            AppManager::getInstance().changePage(std::make_unique<StartPage>());
        }
    }
    if (player.isColliding(boss)) {
	    player.takeDamage(5);
	    std::cout << "damage taken"<< std::endl;
	}
}
void Page2::draw(sf::RenderWindow& window) {
    window.draw(ground);
    for (auto& panel : panels) {
        window.draw(panel);
    }
    window.draw(backBtn);

    bossHealth.draw(window);
    boss.draw(window);
    
    playerHealth.draw(window);
    player.draw(window);
}
void Page2::update(float dt) {
    boss.update(dt);
    player.handleInput();
    player.update(dt);

    playerHealth.update();
    bossHealth.update();
}
