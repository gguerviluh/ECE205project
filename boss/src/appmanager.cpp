#include "appmanager.hpp"
#include "startpage.hpp"

AppManager::AppManager() : window(sf::VideoMode(1920, 1080), "boss demo") {
   currentPage = std::make_unique<StartPage>();
}

AppManager& AppManager::getInstance() {
    static AppManager instance;
    return instance;
}

void AppManager::run() {
    sf::Clock clock;
    while (window.isOpen()) {
	dt = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            currentPage->handleEvent(event, window, dt);
        }

        currentPage->update(dt);

        window.clear(sf::Color::Black);
        currentPage->draw(window);
        window.display();
    }
}

void AppManager::changePage(std::unique_ptr<Page> newPage) {
    currentPage = std::move(newPage);
}

sf::RenderWindow& AppManager::getWindow() {
    return window;
 }
