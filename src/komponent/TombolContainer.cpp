#include "../../include/komponent/TombolContainer.hpp"

TombolContainer::TombolContainer(sf::Font& font)
:
m_font(&font)
{
    // *m_font = font;
}

TombolContainer::~TombolContainer(){
    
}

void TombolContainer::click(){
    std::cout<<"selected: "<<m_currentHovered<<std::endl;
}

void TombolContainer::geser(char key){

    if(key=='d'){
        if(m_currentHovered>0){
            m_currentHovered--;
        }
    }else if(key=='a'){
        if(m_currentHovered<getSize()-1){
            m_currentHovered++;
        }
    }
    updateVisual();
}

void TombolContainer::generate(sf::Vector2f posisiTombol, sf::Vector2f sizeTombol, const std::string& teks){
    if(sizeTombol.x>=sizeTombol.y*2){m_characterSize=sizeTombol.y;}
    else{m_characterSize=sizeTombol.x/2;}

    sf::Text* tempText = new sf::Text(*m_font, teks, m_characterSize);
    sf::RectangleShape* tempRect = new sf::RectangleShape(sizeTombol);

    sf::FloatRect boundTempText = tempText->getLocalBounds();

    tempText->setOrigin(sf::Vector2f(boundTempText.position.x + (boundTempText.size.x / 2), boundTempText.position.y + (boundTempText.size.y / 2)));
    // tempRect->setOrigin(sf::Vector2f(boundTempRect.position.x + (boundTempRect.size.x / 2), boundTempRect.position.y - (boundTempRect.size.y / 2)));
    tempRect->setOrigin(sf::Vector2f(tempRect->getSize().x/2.0f, tempRect->getSize().y/2.0f));

    
    tempRect->setFillColor(m_buttonBg);
    tempRect->setPosition(posisiTombol);
    // tempText->setCharacterSize(m_characterSize);

    // tempText->setCharacterSize(64);
    tempText->setFillColor(m_textColor);
    
    // tempText->setPosition(sf::Vector2f(tempRect->getPosition().x, tempRect->getPosition().y));
    tempText->setPosition(tempRect->getPosition());

    // boundsVisual->setPosition(sf::Vector2f(tempText->getPosition().x + bounds.size.x/2, tempText->getPosition().y + bounds.size.y));

    m_kumpulanTeks.push_back(std::move(tempText));
    m_kumpulanBg.push_back(std::move(tempRect));
    // m_kumpulanBg.push_back(std::move(boundsVisual));

    // std::cout<<"ukuran kumpulanTeks: "<<m_kumpulanTeks.size()<<std::endl;
    updateVisual();
}

int TombolContainer::getSize(){
    if(m_kumpulanBg.size()!=m_kumpulanTeks.size()){
        std::cout<<"[TombolContainer] jumlah element bg sma teks gasama, cb cek lagi"<<std::endl;
        return -1;
    }
    return m_kumpulanBg.size();
}

void TombolContainer::updateVisual(){
    // std::cout<<"selected: "<<m_currentHovered<<std::endl;
    if(getSize()<0){throw;}
    else{
        for(int i=0 ; i<getSize() ; i++){
            m_kumpulanBg[i]->setFillColor(sf::Color::Black);
        }
        m_kumpulanBg[m_currentHovered]->setFillColor(sf::Color::Green);
    }
}

std::vector<sf::Text*>& TombolContainer::getKumpulanTeks(){
    return m_kumpulanTeks;
}
std::vector<sf::RectangleShape*>& TombolContainer::getKumpulanBg(){
    return m_kumpulanBg;
}