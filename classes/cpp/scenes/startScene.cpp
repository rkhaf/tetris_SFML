#include "../../headers/scenes/startScene.hpp"

startScene::startScene(){
    // std::cout<<test<<std::endl;
    sf::RectangleShape* panel = new sf::RectangleShape({50.0f, 50.0f});
    panel->setFillColor(sf::Color::Green);
    // panel.setSize({50.0f, 50.0f});
    // m_allKomponen.push_back(new sf::RectangleShape({50.0f, 50.0f}));
    // m_allKomponen[0]->setSize();
    m_allKomponen.push_back(panel);
}

startScene::~startScene(){

}

void startScene::createKomponen(){

}
std::vector<sf::Drawable*> startScene::getKomponen(){
    return m_allKomponen;
}
