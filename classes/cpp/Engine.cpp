// #include <SFML/Graphics.hpp>
#include "../headers/Engine.hpp"
#include <iostream>
// #include "SceneManager.hpp"

Engine::Engine(sf::Vector2u size, std::string name, Scene* gameScene) : m_gameScene(gameScene) {
    m_panelName = name;
    m_frameRate = 60;
    m_size=size;
    // m_sceneManager=sceneManager;
    
    // sf::RenderWindow m_window(sf::VideoMode(size),name);
    m_window.create(sf::VideoMode(size),m_panelName);
    m_window.setFramerateLimit(60);

    if(!m_font.openFromFile("assets/ds_digital/DS-DIGI.TTF")){
        std::cout<<"gagal"<<std::endl;
    }
    m_gameScene->m_interval=&m_interval;
    m_gameScene->m_font=&m_font;
    m_gameScene->m_window = &m_window;

}

void Engine::update(float dt) {
    // Logika update scene kamu
}

void Engine::draw() {
    // Karena sudah punya pointer m_window, kita bisa langsung panggil di sini
    // Ingat, pakai -> bukan titik (.)
    // m_window->draw(player); 
}

void Engine::run(){
    m_gameScene->start();
    // construct text with (string, Font&)
    // sf::Text m_title("rkhaf", m_font);
    // m_title.setPosition({20.0f,10.0f});

    while (m_window.isOpen()) {
        while (const std::optional event = m_window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                m_window.close();
            }
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::A) {
                    m_gameScene->geser("kiri");
                }
                if (keyPressed->code == sf::Keyboard::Key::D) {
                    m_gameScene->geser("kanan");
                }
                if (keyPressed->code == sf::Keyboard::Key::S) {
                    m_gameScene->geser("bawah");
                }
                if (keyPressed->code == sf::Keyboard::Key::Escape) {
                    m_window.close();
                }
            }
        }
        m_window.clear(sf::Color::Black);
        m_gameScene->update();
        // m_window.draw(m_title);
        m_window.display();
    }

}

sf::RenderWindow* Engine::getWindow(){
    return &m_window;
}