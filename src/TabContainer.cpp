#include "../include/TabContainer.hpp"

TabContainer::TabContainer(sf::Font& font, tabContainerStruct* tabContainerStruct, sf::Vector2f pivot)
:
m_font(&font),
m_tabContainerReference(tabContainerStruct),
m_pivot(pivot)
{
    generate();
}

void TabContainer::click(){
    // if(m_kumpulanLambda.size()>0){
    //     m_kumpulanLambda[m_currentHovered]();
    // }
}

void TabContainer::geser(Kontrol key){
    switch (key){
        case (Kontrol::kiri):
            if(m_currentHovered.x>0){
                m_currentHovered.x--;
            }
            break;
        case (Kontrol::kanan):
            if(m_currentHovered.x<m_tabContainerReference->m_opsi.size()-1){
                m_currentHovered.x++;
            }
            break;
        case (Kontrol::atas):
            if(m_tabContainerReference->m_input.find(m_tabContainerReference->m_opsi[m_currentHovered.x]) != m_tabContainerReference->m_input.end()){
                if(m_currentHovered.y>0){
                    m_currentHovered.y--;
                }
            }else{
                m_currentHovered.y = 0;
            }
            break;
        case (Kontrol::bawah):
            if(m_tabContainerReference->m_input.find(m_tabContainerReference->m_opsi[m_currentHovered.x]) != m_tabContainerReference->m_input.end()){
                if(m_currentHovered.y<m_tabContainerReference->m_input.find(m_tabContainerReference->m_opsi[m_currentHovered.x])->second.size()-1){
                    m_currentHovered.y++;
                }
            }else{
                m_currentHovered.y = 0;
            }
            break;
    }
    updateVisual();
}

void TabContainer::generate(){
    if(UISettings::getButtonSizeSmall().x>=UISettings::getButtonSizeSmall().y*2){m_characterSize=UISettings::getButtonSizeSmall().y;}
    else{m_characterSize=UISettings::getButtonSizeSmall().x/2;}

    for(const auto& label : m_tabContainerReference->m_opsi){
        auto newText = std::make_unique<sf::Text>(*m_font, label, m_characterSize);
        auto newRect = std::make_unique<sf::RectangleShape>(UISettings::getButtonSizeSmall());

        sf::FloatRect boundNewText = newText->getLocalBounds();

        newText->setOrigin(sf::Vector2f(boundNewText.position.x + (boundNewText.size.x / 2), boundNewText.position.y + (boundNewText.size.y / 2)));
        newRect->setOrigin(sf::Vector2f(newRect->getSize().x/2.0f, newRect->getSize().y/2.0f));

        newRect->setFillColor(sf::Color::Black);
        newRect->setOutlineColor(sf::Color::White);
        newRect->setOutlineThickness(3.0f);
        newText->setFillColor(sf::Color::White);

        newRect->setSize(UISettings::getButtonSizeSmall());

        // if(m_opsiTeks.size()<=1){
        //     newText->setPosition(sf::Vector2f(m_pivot.x * 1, m_pivot.y));
        // }else{
        //     newText->setPosition(sf::Vector2f(m_pivot.x * m_opsiTeks.size(), m_pivot.y));
        // }
        // newText->setPosition(sf::Vector2f(m_pivot.x * + (m_opsiTeks.size() + 1), m_pivot.y));
        // std::cout << "tes: " << m_pivot.x << std::endl;
        // std::cout << "TES2: " << newText->getPosition().x << std::endl;
        
        newRect->setPosition(sf::Vector2f((m_pivot.x + newRect->getSize().x / 2.0f) + (newRect->getSize().x * (m_opsiBg.size())), m_pivot.y + (newRect->getSize().y / 2.0f)));
        newText->setPosition(newRect->getPosition());

        m_opsiTeks.push_back(std::move(newText));
        m_opsiBg.push_back(std::move(newRect));
    }

        std::cout << "sebelum" << std::endl;
        if(m_tabContainerReference->m_input.size()>0){
            for(const auto& [nama, vectorVariant] : m_tabContainerReference->m_input){
                std::cout << "iterated: " << nama << std::endl;
                if(std::find(m_tabContainerReference->m_opsi.begin(), m_tabContainerReference->m_opsi.end(), nama) != m_tabContainerReference->m_opsi.end()){
                    // std::cout << "ada: " << nama << std::endl;
                    for(const auto& dataVariant : vectorVariant){
                        if(std::holds_alternative<sliderStruct>(dataVariant)){ //ngefilter sliderStruct
                            auto& slider = std::get<sliderStruct>(dataVariant);
                            auto newTextSubOpsi = std::make_unique<sf::Text>(*m_font, slider.m_label);
                            
                            // std::cout << m_opsiBg.back().get()->getSize().x << ", " << m_opsiBg.back().get()->getSize().y << std::endl;
                            if(m_subOpsiTeks.find(nama)!=m_subOpsiTeks.end()){
                                newTextSubOpsi->setPosition(sf::Vector2f(m_pivot.x * 5, m_pivot.y + (m_opsiBg.back().get()->getSize().y * (m_subOpsiTeks.find(nama)->second.size() + 1))));
                                // std::cout << m_subOpsiTeks.find(nama)->second.size() << std::endl;
                                // std::cout << "iff: " << slider.m_label << std::endl;
                            }else{
                                std::cout << "elss: " << slider.m_label << std::endl;
                                newTextSubOpsi->setPosition(sf::Vector2f(m_pivot.x * 5, m_pivot.y + m_opsiBg.back().get()->getSize().y));
                                // newTextSubOpsi->setPosition(sf::Vector2f(m_pivot.x, m_pivot.y + m_opsiBg.back().get()->getSize().y));
                            }
                            newTextSubOpsi->setFillColor(sf::Color::White);
                            newTextSubOpsi->setCharacterSize(m_characterSize);
                            
                            // if(m_subOpsiTeks.find(nama)!=m_subOpsiTeks.end()){
                                
                            m_subOpsiTeks[nama].push_back(std::move(newTextSubOpsi));
                            // }
                            // m_subOpsiTeks.push_back(std::move(newTextSubOpsi));
    
                        }
                    }
                }else{
                    // std::cout << "gkada: " << nama << std::endl;
                }
            }
        }

        // m_opsiTeks.push_back(std::move(newText));
        // m_opsiBg.push_back(std::move(newRect));
        updateVisual();
    }
    // updateVisual();
// }

int TabContainer::getSize(){
    if(m_opsiBg.size()!=m_opsiTeks.size()){
        return -1;
    }
    return m_opsiBg.size();
    // return 0;
}

void TabContainer::updateVisual(){

    if(getSize()<0){throw;}

    else{
        for(int i=0; i<getSize(); i++){
            m_opsiBg[i]->setFillColor(globalColors::panelFill2);
            m_opsiBg[i]->setOutlineColor(globalColors::panelOutline);
        }
        m_opsiBg[m_currentHovered.x]->setOutlineColor(globalColors::panelOutline);
        m_opsiBg[m_currentHovered.x]->setFillColor(globalColors::buttonHovered);
        auto test = m_opsiTeks[m_currentHovered.x].get()->getString().toAnsiString();
        if(m_subOpsiTeks.find(test) != m_subOpsiTeks.end()){
            // std::cout << "true" << test << std::endl;
            for(const auto& uniqptr : m_subOpsiTeks.find(test)->second){
                uniqptr.get()->setFillColor(sf::Color::White);
            }
            m_subOpsiTeks.find(test)->second[m_currentHovered.y].get()->setFillColor(sf::Color::Green);
        }
        // else{
        //     std::cout << "fals" << test << std::endl;
        // }
    }

    // else{
    //     for(int i=0 ; i<getSize() ; i++){
    //         m_kumpulanBg[i]->setFillColor(globalColors::panelFill2);
    //         m_kumpulanBg[i]->setOutlineColor(globalColors::panelOutline);
    //     }
    //     m_kumpulanBg[m_currentHovered]->setOutlineColor(globalColors::panelOutline);
    //     m_kumpulanBg[m_currentHovered]->setFillColor(globalColors::buttonHovered);
    // }
}

std::vector<std::unique_ptr<sf::Text>>& TabContainer::getKumpulanTeks(){
    return m_opsiTeks;
}
std::vector<std::unique_ptr<sf::RectangleShape>>& TabContainer::getKumpulanBg(){
    return m_opsiBg;
}
std::unordered_map<std::string, std::vector<std::unique_ptr<sf::Text>>>& TabContainer::getKumpulanSubOpsiTeks(){
    return m_subOpsiTeks;
}
sf::Vector2i& TabContainer::getCurrentHovered(){
    return m_currentHovered;
}

void TabContainer::resetContainer(){
    for(int i=0 ; i<getSize() ; i++){
        // delete m_kumpulanBg[i];
        // delete m_kumpulanTeks[i];
        // m_kumpulanLambda.clear();
        m_lambdaSubopsi.clear();
    }
}

// void TombolContainer::drawToWindow(){

// }