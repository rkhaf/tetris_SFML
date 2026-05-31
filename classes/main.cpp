#include <SFML/Graphics.hpp>
#include <iostream>
#include "headers/Engine.hpp"
// #include "headers/SceneManager.hpp"
// #include "headers/Scene_mainMenu.hpp"

float delta=0.0f;


int main() {
    // sf::RenderWindow window(sf::VideoMode({800, 600}), "Plane");
    Scene gameScene("arena1",{12,22});
    Engine engine(sf::Vector2u({800,600}),"PlaneWar", &gameScene);

    gameScene.m_window=engine.getWindow();
    // gameScene.start();

    // std::cout<<std::string(gameScene.m_nama)<<std::endl;
    // std::cout<<std::to_string(gameScene.m_ukuranMatriks.x);
    // std::cout<<std::to_string(gameScene.m_ukuranMatriks.y)<<std::endl;
    engine.run();
    return 0;
}