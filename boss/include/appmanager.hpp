#ifndef APPMANAGER_HPP
#define APPMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class Page;

class AppManager {
private:
    sf::RenderWindow window;
    std::unique_ptr<Page> currentPage;
    float dt;
    sf::Clock clock;
    AppManager(); // Private constructor for Singleton

public:
    static AppManager& getInstance(); // Singleton access

    void run();
    void changePage(std::unique_ptr<Page> newPage);
    sf::RenderWindow& getWindow();
};
#endif // APPMANAGER_HPP
