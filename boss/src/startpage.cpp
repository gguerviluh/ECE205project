#include "startpage.hpp"
#include "appmanager.hpp"
#include "bosspage.hpp"

StartPage::StartPage() {
    font.loadFromFile("arial.ttf");

    startBtn.setFont(font);
    startBtn.setString("Start");
    startBtn.setCharacterSize(24);
    startBtn.setFillColor(sf::Color::Red);
    startBtn.setPosition(960, 800);

    quitBtn.setFont(font);
    quitBtn.setString("Quit");
    quitBtn.setCharacterSize(24);
    quitBtn.setFillColor(sf::Color::Red);
    quitBtn.setPosition(300, 800);

}

bool StartPage::isClicked(const sf::Text& btn, sf::Vector2f pos) {
    return btn.getGlobalBounds().contains(pos);
}

void StartPage::handleEvent(sf::Event& event, sf::RenderWindow& window, float dt) {
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left) {
        auto mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
        if (isClicked(startBtn, mousePos)) {
            AppManager::getInstance().changePage(std::make_unique<Page2>());
        }
        else if (isClicked(quitBtn, mousePos)) {
            AppManager::getInstance().getWindow().close();
        }
    }
}

void StartPage::draw(sf::RenderWindow& window) {
    for (auto& obj : objects) {
        window.draw(obj);
    }
    window.draw(startBtn);
    window.draw(quitBtn);
}
