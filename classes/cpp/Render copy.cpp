#include "../headers/Render.hpp"
#include "../headers/Engine.hpp"
#include <iostream>

Render::Render(){
    std::cout<<"test10"<<std::endl;
    m_boxVisual.setOutlineThickness(1.0f);
    m_boxVisual.setSize({23, 23});
    m_margin=24.0f;

    // if(engine->m_window!=nullptr)
    // if(m_window!=nullptr){
    m_pivotMatriksArena={m_margin, m_margin};
    // m_pivotMatriks={m_margin, m_margin};
    // m_pivotMatriks={0.0f, 0.0f};

    //ngecreate komponen teks
    sf::Text* m_text_skor = new sf::Text(engine->m_font,"skor",32);
    sf::Text* m_text_next = new sf::Text(engine->m_font,"next:",32);

    m_text_skor->setFillColor(sf::Color::White);
    m_text_next->setFillColor(sf::Color::White);

    std::cout<<"test11"<<std::endl;
    //ngecreate komponen panel
    sf::RectangleShape* m_mainPanel = new sf::RectangleShape;
    sf::RectangleShape* m_previewPanel = new sf::RectangleShape;
    // sf::Text* m_text_skor = new sf::Text(*m_font,"skor",32);
    // sf::Text* m_text_next = new sf::Text(*m_font,"next:",32);

    //setup panel
    m_mainPanel->setFillColor(sf::Color::Black);
    m_mainPanel->setOutlineColor(sf::Color::White);
    // panel.setOutlineColor(sf::Color::White);
    m_mainPanel->setOutlineThickness(1.0f);
    // panel.setOutlineThickness(1.0f);

    //setup panel buat preview
    m_previewPanel->setFillColor(sf::Color::Black);
    m_mainPanel->setOutlineColor(sf::Color::White);
    m_mainPanel->setOutlineThickness(1.0f);
    std::cout<<"test12"<<std::endl;

    // panelPreview.setFillColor(sf::Color::Black);
    // panelPreview.setOutlineColor(sf::Color::White);
    // panelPreview.setOutlineThickness(1.0f);

    
    //nyimpen komponen teks kedalem pointer himpunan
    m_kumpulanTeks["skor"]=m_text_skor;
    m_kumpulanTeks["next"]=m_text_next;
    std::cout<<"test12.1"<<std::endl;

    m_kumpulanPanel["mainPanel"]=m_mainPanel;
    m_kumpulanPanel["prevPanel"]=m_previewPanel;
    
    // m_kumpulanTeks["next"]->setString("Next: ");
    // m_kumpulanTeks["next"]->setPosition({panelPreview.getPosition().x, panelPreview.getPosition().y - (m_margin * 2)});

    // m_boxVisual.setOutlineThickness(1.0f);
    // engine->spawn();
    // spawn();
    // m_interval->restart();
    // engine->m_interval.restart();
    std::cout<<"test13"<<std::endl;

    // m_boxVisual.setSize({23, 23});
    // pivotBlock.x=static_cast<int>(m_arenaSolid.size()/2);
    // m_arenaSolid[m_arenaSolid.size()/2][m_arenaSolid[0].size()/2]=m_blok_solid;


    // std::pair<int, int> posNor({0, -2});
    // // std::pair<int, int> posMtx({1, 2});
    // sf::Vector2i posPivMtx({2, 1});
    // std::cout<<"hasil n->m: "<<normalKeMatriks(posNor,&posPivMtx).first<<", "<<normalKeMatriks(posNor,&posPivMtx).second<<std::endl;
    // std::cout<<"hasil: m->n: "<<matriksKeNormal(posMtx,&posPivMtx).first<<", "<<matriksKeNormal(posMtx,&posPivMtx).second<<std::endl;
}

void Render::updateVisual(){
    //render matriks arena
    for(int baris=0; baris<engine->m_arenaSolid.size();baris++){
        for(int kolom=0; kolom<engine->m_arenaSolid[0].size();kolom++){
            if(engine->m_arenaSolid[baris][kolom]==engine->m_blok_kosong){
                m_boxVisual.setFillColor(sf::Color::Black);

            }else if(engine->m_arenaSolid[baris][kolom]==engine->m_blok_solid){
                m_boxVisual.setFillColor(sf::Color::Green);

            }else if(engine->m_arenaSolid[baris][kolom]==engine->m_blok_controlled){
                m_boxVisual.setFillColor(sf::Color::Yellow);

            }else if(engine->m_arenaSolid[baris][kolom]==engine->m_blok_debug){
                m_boxVisual.setFillColor(sf::Color::Red);

            }else{
                m_boxVisual.setFillColor(sf::Color::Cyan);

            }
            if(engine->cekValidBaris(kolom)){
            // if(cekValidBaris(kolom)){
                engine->clearBaris(kolom);
                // clearBaris(kolom);
            }
            // m_arenaSolid[m_currentBlock[0].size()-1][pivotBlock.x - (m_currentBlock->size() / 2)]=3;
            m_boxVisual.setOutlineColor(sf::Color::White);
            m_boxVisual.setPosition({m_pivotMatriksArena.x + (baris * (m_boxVisual.getSize().x + 2)), m_pivotMatriksArena.y + (kolom * (m_boxVisual.getSize().y + 2))});
            // m_window->draw(m_boxVisual);
            engine->m_window.draw(m_boxVisual);
            
        }
    }

    //ngeset size & posisi tiap komponen panel
    
    m_kumpulanPanel["mainPanel"]->setPosition({((m_boxVisual.getSize().x + 3) * engine->m_arenaSolid.size()) + m_margin + m_pivotMatriksArena.x, m_margin});
    m_kumpulanPanel["prevPanel"]->setSize({engine->m_window.getSize().x - ((m_boxVisual.getSize().x + 3) * engine->m_arenaSolid.size() + (m_margin * 2) + m_pivotMatriksArena.x), engine->m_window.getSize().y - (m_margin * 2)});

    // panel.setPosition({((m_boxVisual.getSize().x + 3) * m_ukuranMatriks.x) + m_margin + m_pivotMatriks.x, m_margin});
    // panel.setSize({m_window->getSize().x - ((m_boxVisual.getSize().x + 3) * m_ukuranMatriks.x + (m_margin * 2) + m_pivotMatriks.x), m_window->getSize().y-(m_margin * 2)});

    m_kumpulanPanel["prevPanel"]->setPosition({m_kumpulanPanel["mainPanel"]->getPosition().x + m_margin, m_kumpulanPanel["mainPanel"]->getPosition().y / 2});
    m_kumpulanPanel["prevPanel"]->setSize({m_kumpulanPanel["mainPanel"]->getPosition().x - (m_margin * 2), m_kumpulanPanel["mainPanel"]->getPosition().y / 2});

    //render panel & teks
    engine->m_window.draw(*m_kumpulanPanel["mainPanel"]);
    engine->m_window.draw(*m_kumpulanPanel["prevPanel"]);

    engine->m_window.draw(*m_kumpulanTeks["skor"]);
    engine->m_window.draw(*m_kumpulanTeks["next"]);

    // panelPreview.setPosition({panel.getPosition().x + m_margin, panel.getSize().y / 2});
    // panelPreview.setSize({panel.getSize().x - (m_margin * 2), panel.getSize().y / 2});

    
    if(engine->m_currentBlock->size()>0){
        m_pivotPreview= new sf::Vector2f({m_kumpulanPanel["prePanel"]->getPosition().x + m_kumpulanPanel["prePanel"]->getSize().x / 2.5f, m_kumpulanPanel["prePanel"]->getPosition().y + m_kumpulanPanel["prePanel"]->getSize().y / 2.5f});
        for(int baris=0; baris<engine->m_currentBlock->size();baris++){
            for(int kolom=0; kolom<engine->m_currentBlock[0].size();kolom++){
                if((*engine->m_currentBlock)[baris][kolom]==0){
                    m_boxVisual.setFillColor(sf::Color::Black);
                    m_boxVisual.setOutlineColor(sf::Color::White);
                }else if((*engine->m_currentBlock)[baris][kolom]==1){
                    m_boxVisual.setFillColor(sf::Color::Blue);
                    m_boxVisual.setOutlineColor(sf::Color::Black);
                }
                else{
                    m_boxVisual.setFillColor(sf::Color::Yellow);
                    m_boxVisual.setOutlineColor(sf::Color::White);
                }
                m_boxVisual.setPosition({m_pivotPreview->x + (baris * (m_boxVisual.getSize().x + 2)), m_pivotPreview->y + (kolom * (m_boxVisual.getSize().y + 2))});
                // m_window->draw(m_boxVisual);
                engine->m_window.draw(m_boxVisual);
                
            }
        }
    }
}