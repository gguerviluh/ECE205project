#ifndef PAGES_HPP
#define PAGES_HPP
#include <SFML/Graphics.hpp>

class AppManager; // Forward declaration

class Page {
public:
    virtual void handleEvent(sf::Event& event, sf::RenderWindow& window, float dt) = 0;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual ~Page() = default;
};

#endif // PAGES_HPP
