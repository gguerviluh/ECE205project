#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "config.hpp"
#include "boss.hpp"
#include "healthbar.hpp"
#include <vector> 
#include "appmanager.hpp"
#include "startpage.hpp"
#include "bosspage.hpp"

int main() {
	AppManager::getInstance().run();
	
    return 0;
}
