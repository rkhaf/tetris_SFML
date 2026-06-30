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
    if(key==Kontrol::atas){
        if(m_currentHovered.y>-1){
            m_currentHovered.y--;
        }
    }else if(key==Kontrol::bawah){
        if(m_tabContainerReference->m_input.find(m_tabContainerReference->m_opsi[m_currentHovered.x]) != m_tabContainerReference->m_input.end()){
            if(m_currentHovered.y < static_cast<int>(m_tabContainerReference->m_input.find(m_tabContainerReference->m_opsi[m_currentHovered.x])->second.size()-1)){
                m_currentHovered.y++;
            }
        }
    }

    if(m_currentHovered.y==-1){
        if(key==Kontrol::kiri){
            if(m_currentHovered.x>0){
                m_currentHovered.x--;
            }
        }else if(key==Kontrol::kanan){
            if(m_currentHovered.x<m_tabContainerReference->m_opsi.size()-1){
                m_currentHovered.x++;
            }
        }
    }else{
        // const auto& teksStringOpsiTerpilih = m_opsiTeks[m_currentHovered.x].get()->getString().toAnsiString();
        // const auto& teksStringOpsiTerpilih = m_opsiTeks[m_currentHovered.x].get()->getString().toAnsiString();
        // const auto& teksStringSubOpsiTerpilih = m_subOpsiTeks.find(teksStringOpsiTerpilih)->second[m_currentHovered.y].get()->getString().toAnsiString();
        // int index = 0;
        if(key==Kontrol::kiri){
            // index = 1;
            // auto uniqptr = &m_subOpsiInput[teksStringOpsiTerpilih][teksStringSubOpsiTerpilih][1];
            // if(auto* arrowObj = std::get_if<Arrow>(uniqptr.get())){
            //     arrowObj->setFillColor(sf::Color::Green);
            // }
            // auto& test = m_ArrowHolder[Kontrol::kiri];

            // m_ArrowHolder[Kontrol::kiri] = &m_subOpsiInput[teksStringOpsiTerpilih][teksStringSubOpsiTerpilih][1];
            // auto test2 = &m_subOpsiInput[teksStringOpsiTerpilih][teksStringSubOpsiTerpilih][1];

            // if(m_ArrowHolder.find(Kontrol::kiri) != m_ArrowHolder.end()){
            //     m_ArrowHolder
            // }
            modifySlider(key);
            // std::cout << "changeValueLeft" << std::endl;
            
        }else if(key==Kontrol::kanan){
            // auto& uniqptr = m_subOpsiInput[teksStringOpsiTerpilih][teksStringSubOpsiTerpilih][2];
            // if(auto* arrowObj = std::get_if<Arrow>(uniqptr.get())){
                //     arrowObj->setFillColor(sf::Color::Green);
                // }
                // index = 2;
                // auto& uniqptr = m_subOpsiInput[teksStringOpsiTerpilih][teksStringSubOpsiTerpilih][2];
                // if(m_ArrowHolder.find(Kontrol::kanan) != m_ArrowHolder.end()){
                    // }
            modifySlider(key);
            // std::cout << "changeValueRight" << std::endl;
        }

        // if(auto* arrowObj = std::get_if<Arrow>(uniqptr.get())){
        //     arrowObj->setFillColor(sf::Color::Green);
        // }
    }
    updateVisual();
}

void TabContainer::modifySlider(Kontrol arah){
    // std::cout << static_cast<int>(arah) << std::endl;
    const auto& teksStringOpsiTerpilih = m_opsiTeks[m_currentHovered.x].get()->getString().toAnsiString();
    const auto& teksStringSubOpsiTerpilih = m_subOpsiTeks.find(teksStringOpsiTerpilih)->second[m_currentHovered.y].get()->getString().toAnsiString();
    auto& uniqptr = m_subOpsiInput[teksStringOpsiTerpilih][teksStringSubOpsiTerpilih][0];

    if(teksStringSubOpsiTerpilih == "SFX Volume"){
        if(arah == Kontrol::kiri){
            Settings::setAudioVolumeSFX(Settings::getAudioVolumeSFX()-1);
        }else if(arah == Kontrol::kanan){
            Settings::setAudioVolumeSFX(Settings::getAudioVolumeSFX()+1);
        }
        if(auto* textObj = std::get_if<sf::Text>(uniqptr.get())){
            textObj->setString(std::to_string(static_cast<int>(Settings::getAudioVolumeSFX())));
        }
    }else if(teksStringSubOpsiTerpilih == "BGM Volume"){
        if(arah == Kontrol::kiri){
            Settings::setAudioVolumeBGM(Settings::getAudioVolumeBGM()-1);
        }else if(arah == Kontrol::kanan){
            Settings::setAudioVolumeBGM(Settings::getAudioVolumeBGM()+1);
        }
        if(auto* textObj = std::get_if<sf::Text>(uniqptr.get())){
            textObj->setString(std::to_string(static_cast<int>(Settings::getAudioVolumeBGM())));
        }
    }
    // std::cout << "SFX Volume : " << Settings::getAudioVolumeSFX() << std::endl;
    // std::cout << "BGM Volume : " << Settings::getAudioVolumeBGM() << std::endl;
    // std::cout << teksStringSubOpsiTerpilih << std::endl;


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

        // std::cout << "sebelum" << std::endl;
        if(m_tabContainerReference->m_input.size()>0){
            for(const auto& [nama, vectorVariant] : m_tabContainerReference->m_input){
                // std::cout << "iterated: " << nama << std::endl;
                if(std::find(m_tabContainerReference->m_opsi.begin(), m_tabContainerReference->m_opsi.end(), nama) != m_tabContainerReference->m_opsi.end()){
                    // std::cout << "ada: " << nama << std::endl;
                    for(const auto& dataVariant : vectorVariant){
                        if(std::holds_alternative<sliderStruct>(dataVariant)){ //ngefilter sliderStruct
                            auto& slider = std::get<sliderStruct>(dataVariant);
                            auto newTextSubOpsi = std::make_unique<sf::Text>(*m_font, slider.m_label);
                            // float sliderMinVal = slider.m_min;

                            Arrow leftArrow(false, globalColors::panelFill, globalColors::panelOutline);
                            Arrow rightArrow(true, globalColors::panelFill, globalColors::panelOutline);

                            leftArrow.setOutlineThickness(m_bgOutlineThickness);
                            rightArrow.setOutlineThickness(m_bgOutlineThickness);

                            sf::Text valueLabel(*m_font, std::to_string(static_cast<int>(slider.m_val)));
                            sf::FloatRect boundNewText = valueLabel.getLocalBounds();
                            // sf::Vector2f test = boundNewText.size;

                            // valueLabel.setOrigin(sf::Vector2f(boundNewText.position.x + (boundNewText.size.x / 2), boundNewText.position.y + (boundNewText.size.y / 2)));

                            // std::cout << m_opsiBg.back().get()->getSize().x << ", " << m_opsiBg.back().get()->getSize().y << std::endl;
                            if(m_subOpsiTeks.find(nama)!=m_subOpsiTeks.end()){
                                // std::cout << "iff: " << slider.m_label << std::endl;
                                // auto leftArrBounds = leftArrow.getGlobalBounds();
                                // auto leftArrBoundsSize = sf::Vector2f(leftArrBounds.size.x, leftArrBounds.size.y);
                                newTextSubOpsi->setPosition(sf::Vector2f(m_pivot.x * 5, m_pivot.y + (m_opsiBg.back().get()->getSize().y * (m_subOpsiTeks.find(nama)->second.size() + 1))));
                                valueLabel.setPosition(sf::Vector2f(360.0f, m_pivot.y + (m_opsiBg.back().get()->getSize().y * (m_subOpsiTeks.find(nama)->second.size() + 1))));
                                leftArrow.setPosition(sf::Vector2f(valueLabel.getPosition().x - m_subOpsiComponentGap, valueLabel.getPosition().y));
                                rightArrow.setPosition(sf::Vector2f(valueLabel.getPosition().x + m_subOpsiComponentGap, valueLabel.getPosition().y));
                                // leftArrow.setPosition(valueLabel.getPosition());
                                // rightArrow.setPosition(valueLabel.getPosition());
                                // rightArrow.setPosition(sf::Vector2f(valueLabel.getPosition().x + m_subOpsiComponentGap, valueLabel.getPosition().y));

                                // leftArrow.setOutlineColor(sf::Color::Green);
                                // std::cout << "leftArrowGetPos(): " << leftArrow.getPosition().x << ", " << leftArrow.getPosition().y << std::endl;
                                // std::cout << "leftArrowOutlineColor: Hijau" << std::endl;
                                // std::cout << "valueLabelGetPos(): " << valueLabel.getPosition().x << ", " << valueLabel.getPosition().y << std::endl;
                                // std::cout << m_subOpsiTeks.find(nama)->second.size() << std::endl;
                                // leftArrow.getGlobalBounds().size().x;
                                // (leftArrow.getGlobalBounds().size())
                            }else{
                                // std::cout << "elss: " << slider.m_label << std::endl;
                                newTextSubOpsi->setPosition(sf::Vector2f(m_pivot.x * 5, m_pivot.y + m_opsiBg.back().get()->getSize().y));
                                valueLabel.setPosition(sf::Vector2f(360.0f, m_pivot.y + m_opsiBg.back().get()->getSize().y));
                                
                                // leftArrow.setPosition(valueLabel.getPosition());
                                leftArrow.setPosition(sf::Vector2f(valueLabel.getPosition().x - m_subOpsiComponentGap, valueLabel.getPosition().y));
                                rightArrow.setPosition(sf::Vector2f(valueLabel.getPosition().x + m_subOpsiComponentGap, valueLabel.getPosition().y));
                                // leftArrow.setOutlineColor(sf::Color::Blue);
                                // std::cout << "leftArrowGetPos(): " << leftArrow.getPosition().x << ", " << leftArrow.getPosition().y << std::endl;
                                // std::cout << "leftArrowOutlineColor: Biru" << std::endl;
                                // std::cout << "valueLabelGetPos(): " << valueLabel.getPosition().x << ", " << valueLabel.getPosition().y << std::endl;
                                // newTextSubOpsi->setPosition(sf::Vector2f(m_pivot.x, m_pivot.y + m_opsiBg.back().get()->getSize().y));
                            }
                            // std::cout << "leftArrowGetPos(): " << leftArrow.getPosition().x << ", " << leftArrow.getPosition().y << std::endl;
                            // std::cout << "valueLabelGetPos(): " << valueLabel.getPosition().x << ", " << valueLabel.getPosition().y << std::endl;
                            // std::cout << "newTextSubOpsi.get()->getPosition(): " << newTextSubOpsi.get()->getPosition().x << ", " << newTextSubOpsi.get()->getPosition().y << std::endl;
                            // std::cout << "valueLabel.getPosition(): " << valueLabel.getPosition().x << ", " << valueLabel.getPosition().y << std::endl;

                            // std::cout << "newTextSubOpsi.get()->getOrigin(): " << newTextSubOpsi.get()->getOrigin().x << ", " << newTextSubOpsi.get()->getOrigin().y << std::endl;
                            // std::cout << "valueLabel.getOrigin(): " << valueLabel.getOrigin().x << ", " << valueLabel.getOrigin().y << std::endl;
                            
                            // valueLabel.setPosition(sf::Vector2f(50.0f, m_subOpsiTeks.find(nama)->second.back().get()->getPosition().y));
                            // sf::Text valueLabel(*m_font, slider.m_val);
                            valueLabel.setCharacterSize(m_characterSize);
                            valueLabel.setFillColor(sf::Color::White);

                            using MyVariant = std::variant<sliderStruct, Arrow, sf::Text, sf::RectangleShape>;

                            // m_subOpsiInput.find(nama)->second.push_back(std::make_unique<MyVariant>(valueLabel));

                            newTextSubOpsi->setFillColor(sf::Color::White);
                            newTextSubOpsi->setCharacterSize(m_characterSize);
                            
                            // if(m_subOpsiTeks.find(nama)!=m_subOpsiTeks.end()){
                                
                            m_subOpsiTeks[nama].push_back(std::move(newTextSubOpsi));
                            // m_subOpsiInput[nama]
                            const auto& subOpsiTeksTerakhir = m_subOpsiTeks.find(nama)->second.back().get()->getString().toAnsiString();
                            // m_subOpsiInput[nama][subOpsiTeksTerakhir]

                            m_subOpsiInput[nama][subOpsiTeksTerakhir].push_back(std::make_unique<MyVariant>(valueLabel));
                            m_subOpsiInput[nama][subOpsiTeksTerakhir].push_back(std::make_unique<MyVariant>(leftArrow));
                            m_subOpsiInput[nama][subOpsiTeksTerakhir].push_back(std::make_unique<MyVariant>(rightArrow));
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
        auto test = m_opsiTeks[m_currentHovered.x].get()->getString().toAnsiString();
        for(int i=0; i<getSize(); i++){
            m_opsiBg[i]->setFillColor(globalColors::panelFill2);
            m_opsiBg[i]->setOutlineColor(globalColors::panelOutline);
        }
        if(m_subOpsiTeks.find(test) != m_subOpsiTeks.end()){
            for(const auto& uniqptr : m_subOpsiTeks.find(test)->second){
                uniqptr.get()->setFillColor(sf::Color::White);
            }
        }
        for(const auto& [strOpsiTeks, vektor] : m_subOpsiInput){
            for(const auto& [strSubOpsiTeks, vektor2] : vektor){
                for(const auto& uniqptr : vektor2){
                    // if(uniqptr)
                    // if(auto* textObj = std::get_if<sf::Text>(uniqptr.get())){
                    //     textObj->setFillColor(sf::Color::White);
                    // // }else if(auto* teksObj = std::get_if<sf::Text>(uniqptr.get())){
                    // //     teksObj->setFillColor(sf::Color::White);
                    // //     if(m_subOpsiTeks.find(strOpsiTeks)->second[m_currentHovered.y].get()->getString().toAnsiString() == strSubOpsiTeks){
                    // //         teksObj->setFillColor(sf::Color::Green);
                    // //     }
                    // // }
                    // }
                    if(auto* arrowObj = std::get_if<Arrow>(uniqptr.get())){
                        arrowObj->setOutlineColor(globalColors::panelOutline);
                        // arrowObj->setFillColor(globalColors::panelFill);
                    }
                }
            }
        }

        if(m_currentHovered.y==-1){
            // for(int i=0; i<getSize(); i++){
            //     m_opsiBg[i]->setFillColor(globalColors::panelFill2);
            //     m_opsiBg[i]->setOutlineColor(globalColors::panelOutline);
            // }
            m_opsiBg[m_currentHovered.x]->setOutlineColor(globalColors::panelOutline);
            m_opsiBg[m_currentHovered.x]->setFillColor(globalColors::buttonHovered);
        }else{
            auto test = m_opsiTeks[m_currentHovered.x].get()->getString().toAnsiString();
            if(m_subOpsiTeks.find(test) != m_subOpsiTeks.end()){
                // std::cout << "true" << test << std::endl;
                // for(const auto& uniqptr : m_subOpsiTeks.find(test)->second){
                //     uniqptr.get()->setFillColor(sf::Color::White);
                // }
                m_subOpsiTeks.find(test)->second[m_currentHovered.y].get()->setFillColor(sf::Color::Green);

                // using MenuVariant = std::variant<Arrow, sf::Text>;
                if(m_currentHovered.x>-1){
                    const auto& teksStringSubOpsiTerpilih = m_subOpsiTeks.find(test)->second[m_currentHovered.y].get()->getString().toAnsiString();
                    const auto& teksStringOpsiTerpilih = m_opsiTeks[m_currentHovered.x].get()->getString().toAnsiString();

                    // auto& uniqptr = m_subOpsiInput[teksStringOpsiTerpilih][teksStringSubOpsiTerpilih][1];
                    auto& vektorSubOpsiInput = m_subOpsiInput[teksStringOpsiTerpilih][teksStringSubOpsiTerpilih];

                    for(const auto& komponen : vektorSubOpsiInput){
                        if(auto* arrowObj = std::get_if<Arrow>(komponen.get())){
                            arrowObj->setOutlineColor(sf::Color::Green);
                        }
                    }

                    // if(auto* textObj = std::get_if<sf::Text>(uniqptr.get())){
                    //     textObj->setFillColor(sf::Color::Green);
                    // // }else if(auto* teksObj = std::get_if<sf::Text>(uniqptr.get())){
                    // //     teksObj->setFillColor(sf::Color::White);
                    // //     if(m_subOpsiTeks.find(strOpsiTeks)->second[m_currentHovered.y].get()->getString().toAnsiString() == strSubOpsiTeks){
                    // //         teksObj->setFillColor(sf::Color::Green);
                    // //     }
                    // // }
                    // }
                    // if(auto* arrowObj = std::get_if<Arrow>(uniqptr.get())){
                    //     arrowObj->setOutlineColor(sf::Color::Green);
                    // }

                // for(const auto& [strOpsiTeks, vektor] : m_subOpsiInput){
                //     for(const auto& [strSubOpsiTeks, vektor2] : vektor){
                //         for(const auto& uniqptr : vektor2){
                //             // if(uniqptr)
                //             if(auto* arrowObj = std::get_if<Arrow>(uniqptr.get())){

                //             }else if(auto* teksObj = std::get_if<sf::Text>(uniqptr.get())){
                //                 teksObj->setFillColor(sf::Color::White);
                //                 if(m_subOpsiTeks.find(strOpsiTeks)->second[m_currentHovered.y].get()->getString().toAnsiString() == strSubOpsiTeks){
                //                     teksObj->setFillColor(sf::Color::Green);
                //                 }
                //             }
                //         }
                //     }
                // }
            }
        }
        // std::cout << m_currentHovered.x << ", " << m_currentHovered.y << std::endl;


        // for(int i=0; i<getSize(); i++){
        //     m_opsiBg[i]->setFillColor(globalColors::panelFill2);
        //     m_opsiBg[i]->setOutlineColor(globalColors::panelOutline);
        // }
        // m_opsiBg[m_currentHovered.x]->setOutlineColor(globalColors::panelOutline);
        // m_opsiBg[m_currentHovered.x]->setFillColor(globalColors::buttonHovered);
        // auto test = m_opsiTeks[m_currentHovered.x].get()->getString().toAnsiString();
        // if(m_subOpsiTeks.find(test) != m_subOpsiTeks.end()){
        //     // std::cout << "true" << test << std::endl;
        //     for(const auto& uniqptr : m_subOpsiTeks.find(test)->second){
        //         uniqptr.get()->setFillColor(sf::Color::White);
        //     }
        //     m_subOpsiTeks.find(test)->second[m_currentHovered.y+1].get()->setFillColor(sf::Color::Green);
        // }
        }
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
std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::unique_ptr<std::variant<sliderStruct, Arrow, sf::Text, sf::RectangleShape>>>>>& TabContainer::getKumpulanSubOpsiInput(){
    return m_subOpsiInput;
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