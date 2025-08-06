#ifndef BOSSPAGE_HPP
#define BOSSPAGE_HPP

#include "pages.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "boss.hpp"
#include "healthbar.hpp"
#include "config.hpp"
class Page2 : public Page {
private:
    sf::Font font;
    sf::Text backBtn;
    std::vector<sf::RectangleShape> panels;

    bool isClicked(const sf::Text& btn, sf::Vector2f mousePos);
    
    sf::RectangleShape ground;
    Boss boss;
    Healthbar bossHealth;
    Player player;
    Healthbar playerHealth;

public:
    Page2();
    void handleEvent(sf::Event& event, sf::RenderWindow& window, float dt) override;
    void update(float dt) override{}
    void draw(sf::RenderWindow& window) override;
};
#endif // BOSSPAGE_HPP
