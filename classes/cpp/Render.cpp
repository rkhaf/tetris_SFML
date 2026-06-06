#include "../headers/Render.hpp"
#include <iostream>
#include "../headers/Engine.hpp"

Render::Render(sf::Vector2u windowSize, int limitFramerate, SceneManager* sceneManager, Engine* engine)
    :
    m_engine(engine)
    // m_sceneManager(sceneManager)
    {
    m_window.create(sf::VideoMode(windowSize),"mainPanel");
    m_window.clear(sf::Color::Black);
    m_window.setFramerateLimit(limitFramerate);
}

void Render::init(){

    for(const auto& scene : m_engine->m_sceneManager->m_currentScene){
        std::cout<<"test"<<std::endl;
        if (scene != nullptr) {
            std::cout<<"kumpulanRectSize: "<<scene->m_kumpulanRect.size()<<std::endl;
            if(scene->m_kumpulanRect.size()>0){
                for(const auto& komponen : scene->m_kumpulanRect){

                    auto temp = std::make_unique<sf::RectangleShape>(sf::Vector2f(komponen.second.m_size));

                    temp->setFillColor(komponen.second.m_warnaFill);
                    temp->setOutlineColor(komponen.second.m_warnaOutline);
                    temp->setOutlineThickness(komponen.second.m_outlineThickness);
                    temp->setPosition(komponen.second.m_posisi);
                    
                    m_komponenScene.push_back(std::move(temp));
                }
            }
            if(scene->m_kumpulanTeks.size()>0){
                for(const auto& komponen : scene->m_kumpulanTeks){

                    // auto temp = std::make_unique<sf::RectangleShape>(sf::Vector2f(komponen.second.m_size));
                    auto temp = std::make_unique<sf::Text>(m_engine->m_font, komponen.second.m_teks, komponen.second.m_sizeKarakter);

                    // temp->setFillColor(komponen.second.m_warnaFill);
                    // temp->setOutlineColor(komponen.second.m_warnaOutline);
                    // temp->setOutlineThickness(komponen.second.m_outlineThickness);
                    temp->setPosition(komponen.second.m_posisi);
                    
                    m_komponenScene.push_back(std::move(temp));
                }
            }
        }else{
            std::cout<<"scenenya null"<<std::endl;
        }
    }
}

void Render::start(){
    // std::cout<<"size array scene: "<<m_engine->m_kumpulanScene.size()<<std::endl;
    while (m_window.isOpen()) {
        m_window.clear(sf::Color::Black);

        for(const auto& komponen : m_komponenScene){
            m_window.draw(*komponen);
            // std::cout<<"found"<<std::endl;
        }

        //nnti masuk ke modul input
        while (const std::optional event = m_window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                m_window.close();
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::Space) {
                }
                if (keyPressed->code == sf::Keyboard::Key::Escape) {
                    m_window.close();
                }
            }
        }
        m_window.display();
    }
}

void Render::visualize(std::vector<sf::Drawable> komponenDrawable){

}