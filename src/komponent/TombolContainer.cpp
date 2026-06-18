#include "../../include/komponent/TombolContainer.hpp"

TombolContainer::TombolContainer(sf::Font& font)
:
m_font(&font)
{
    // *m_font = font;
    // std::cout << "[TombolContainer : " << this << "] : unit dibuat" << std::endl;
}

void TombolContainer::click(){
    // std::cout<<"selected: "<<m_currentHovered<<std::endl;
    // std::cout << "[TombolContainer : " << this << "] : clicked" << std::endl;
    if(m_kumpulanLambda.size()>0){
        m_kumpulanLambda[m_currentHovered]();
    }
}

void TombolContainer::geser(Kontrol key){
    // std::cout << "[TombolContainer : " << this << "] : geser" << std::endl;
    // std::cout << this << "curr hovered: "<< m_currentHovered << std::endl;
    if(key==Kontrol::kiri){
        if(m_currentHovered>0){
            m_currentHovered--;
        }
    }else if(key==Kontrol::kanan){
        if(m_currentHovered<getSize()-1){
            m_currentHovered++;
        }
    }
    updateVisual();
}

void TombolContainer::generate(sf::Vector2f posisiTombol, sf::Vector2f sizeTombol, const std::string& teks, std::function<void()> action){
    // std::cout << "[TombolContainer : " << this << "] : generated" << std::endl;
    if(sizeTombol.x>=sizeTombol.y*2){m_characterSize=sizeTombol.y;}
    else{m_characterSize=sizeTombol.x/2;}

    // sf::Text* tempText = new sf::Text(*m_font, teks, m_characterSize);
    auto tempText = std::make_unique<sf::Text>(*m_font, teks, m_characterSize);

    // sf::RectangleShape* tempRect = new sf::RectangleShape(sizeTombol);
    auto tempRect = std::make_unique<sf::RectangleShape>(sizeTombol);

    sf::FloatRect boundTempText = tempText->getLocalBounds();

    tempText->setOrigin(sf::Vector2f(boundTempText.position.x + (boundTempText.size.x / 2), boundTempText.position.y + (boundTempText.size.y / 2)));
    // tempRect->setOrigin(sf::Vector2f(boundTempRect.position.x + (boundTempRect.size.x / 2), boundTempRect.position.y - (boundTempRect.size.y / 2)));
    tempRect->setOrigin(sf::Vector2f(tempRect->getSize().x/2.0f, tempRect->getSize().y/2.0f));

    
    tempRect->setFillColor(m_buttonBg);
    tempRect->setPosition(posisiTombol);
    tempRect->setOutlineThickness(m_bgOutlineThickness);
    // tempText->setCharacterSize(m_characterSize);

    // tempText->setCharacterSize(64);
    tempText->setFillColor(m_textColor);
    
    // tempText->setPosition(sf::Vector2f(tempRect->getPosition().x, tempRect->getPosition().y));
    tempText->setPosition(tempRect->getPosition());

    // boundsVisual->setPosition(sf::Vector2f(tempText->getPosition().x + bounds.size.x/2, tempText->getPosition().y + bounds.size.y));

    m_kumpulanTeks.push_back(std::move(tempText));
    m_kumpulanBg.push_back(std::move(tempRect));
    m_kumpulanLambda.push_back(std::move(action));

    // m_kumpulanBg.push_back(std::move(boundsVisual));

    // std::cout<<"ukuran kumpulanTeks: "<<m_kumpulanTeks.size()<<std::endl;
    updateVisual();
}

int TombolContainer::getSize(){
    if(m_kumpulanBg.size()!=m_kumpulanTeks.size()){
        // std::cout<<"[TombolContainer] jumlah element bg sma teks gasama, cb cek lagi"<<std::endl;
        return -1;
    }
    return m_kumpulanBg.size();
}

void TombolContainer::updateVisual(){
    // std::cout<<"selected: "<<m_currentHovered<<std::endl;
    if(getSize()<0){throw;}
    else{
        for(int i=0 ; i<getSize() ; i++){
            m_kumpulanBg[i]->setFillColor(globalColors::panelFill2);
            m_kumpulanBg[i]->setOutlineColor(globalColors::panelOutline);
        }
        m_kumpulanBg[m_currentHovered]->setOutlineColor(globalColors::panelOutline);
        m_kumpulanBg[m_currentHovered]->setFillColor(globalColors::buttonHovered);
    }
    // std::cout << "[TombolContainer] : " << m_currentHovered << std::endl;
}

std::vector<std::unique_ptr<sf::Text>>& TombolContainer::getKumpulanTeks(){
    return m_kumpulanTeks;
}
std::vector<std::unique_ptr<sf::RectangleShape>>& TombolContainer::getKumpulanBg(){
    return m_kumpulanBg;
}

void TombolContainer::resetContainer(){
    for(int i=0 ; i<getSize() ; i++){
        // delete m_kumpulanBg[i];
        // delete m_kumpulanTeks[i];
        m_kumpulanLambda.clear();
    }
}

// void TombolContainer::drawToWindow(){

// }