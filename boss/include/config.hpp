#ifndef CONFIG_HPP
#define CONFIG_HPP

namespace config {
    // Window
    constexpr unsigned int windowWidth = 1920;
    constexpr unsigned int windowHeight = 1080;

    // Physics / Gameplay
    constexpr float groundY = 800.0f;
    constexpr float gravity = 1600.0f;
    constexpr float jumpStrength = 800.0f;
    constexpr float playerSpeed = 200.0f;
    constexpr int maxJumps = 2;
    // Boss physics
    constexpr float bossJumpStrength = 400.0f;
    constexpr float bossSpeed = 100.0f;
    constexpr int bossMaxJumps = 1;

    // Player size
    constexpr float playerWidth = 50.0f;
    constexpr float playerHeight = 80.0f;
    
    // Boss size
    constexpr float bossWidth = 100.0f;
    constexpr float bossHeight = 160.0f;

    //Healthbar sizing
    constexpr float healthbarWidth = 400.0f;
    constexpr float healthbarHeight = 10.0f;
    
    //Slash attack info
    constexpr float playerSlashWidth = 15.0f;
    constexpr float playerSlashHeight = 70.0f;
    constexpr float playerSlashRotSpeed = 90.f;
    constexpr int playerSlashDmg = 50;
    
    constexpr float bossSlashWidth = 40.0f;
    constexpr float bossSlashHeight = 60.0f;
    constexpr float bossSlashRotSpeed = 90.f;
}

#endif // CONFIG_HPP
