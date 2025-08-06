#ifndef STARTPAGE_HPP
#define STARTPAGE_HPP

#include<SFML/Graphics.hpp>
#include "pages.hpp"
#include <vector> 

class StartPage : public Page {
private:
    sf::Font font;
    sf::Text startBtn, quitBtn;
    std::vector<sf::CircleShape> objects;

    void initUI();
    bool isClicked(const sf::Text& btn, sf::Vector2f mousePos);

public:
    StartPage();
    void handleEvent(sf::Event& event, sf::RenderWindow& window, float dt) override;
    void update(float dt) override {}
    void draw(sf::RenderWindow& window) override;
};
#endif // STARTPAGE_HPP
