// #include <SFML/Graphics.hpp>
#include "../headers/Engine.hpp"
#include <iostream>
#include <cstring>
// #include "SceneManager.hpp"

Engine::Engine(sf::Vector2u size, Scene* gameScene, Render* renderEngine, sf::Vector2i arenaSize) : m_gameScene(gameScene) {
    m_frameRate = 60;
    m_size=size;
    // m_sceneManager=sceneManager;
    
    // sf::RenderWindow m_window(sf::VideoMode(size),name);
    m_gameScene=gameScene;
    m_renderEngine=renderEngine;

    m_arenaSolid.assign(arenaSize.x, std::vector<int>(arenaSize.x, 0));
    m_window.create(sf::VideoMode(size),m_panelName);
    m_window.setFramerateLimit(60);

    if(!m_font.openFromFile("assets/ds_digital/DS-DIGI.TTF")){
        std::cout<<"gagal"<<std::endl;
    }

    m_ketinggianBlock=0;
    m_blok_kosong=0;
    m_blok_solid=1;
    m_blok_controlled=2;
    m_blok_debug=3;

    
    // m_gameScene->m_interval=&m_interval;
    // m_gameScene->m_font=&m_font;
    // m_gameScene->m_window = &m_window;
    
    pivotBlock.x=static_cast<int>(m_arenaSolid.size()/2);
    m_arenaSolid[m_arenaSolid.size()/2][m_arenaSolid[0].size()/2]=m_blok_solid;
}

void Engine::start(){

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
    // m_gameScene->start();
    // construct text with (string, Font&)
    // sf::Text m_title("rkhaf", m_font);
    // m_title.setPosition({20.0f,10.0f});

    std::cout<<"running"<<std::endl;

    
    // while (m_window.isOpen()) {
    //     while (const std::optional event = m_window.pollEvent()) {
    //         if (event->is<sf::Event::Closed>()) {
    //             m_window.close();
    //         }
    //         if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
    //             if (keyPressed->code == sf::Keyboard::Key::A) {
    //                 // m_gameScene->geser("kiri");
    //                 geser("kiri");
    //             }
    //             if (keyPressed->code == sf::Keyboard::Key::D) {
    //                 geser("kanan");
    //             }
    //             if (keyPressed->code == sf::Keyboard::Key::S) {
    //                 geser("bawah");
    //             }
    //             if (keyPressed->code == sf::Keyboard::Key::Escape) {
    //                 m_window.close();
    //             }
    //         }
    //     }

    //     if(m_interval.getElapsedTime().asSeconds()>m_interval_timeout){
    //         // m_interval->restart();
    //         m_interval.restart();
    //         jatuh();
    //     }
        
    //     // m_window.clear(sf::Color::Black);
    //     // m_gameScene->update();
    //     // m_window.draw(m_title);
    //     // m_window.display();
    // }

}

sf::RenderWindow* Engine::getWindow(){
    return &m_window;
}

bool Engine::cekValidBaris(int baris){
    for(int kolom=0 ; kolom<m_arenaSolid.size() ; kolom++){
        // std::cout<<"baris: "<<baris<<", kolom:"<<kolom<<std::endl;
        if(m_arenaSolid[kolom][baris]==m_blok_kosong || m_arenaSolid[kolom][baris]==m_blok_controlled){
            return false;
        }
    }
    return true;
}
void Engine::clearBaris(int baris){
    for(int kolom=0 ; kolom<m_arenaSolid.size() ; kolom++){
        // std::cout<<"baris: "<<baris<<", kolom:"<<kolom<<std::endl;
        // float savedInterval=m_interval->getElapsedTime().asMilliseconds();
        // m_arenaSolid[kolom][baris]=m_blok_controlled;
        // if(m_interval->getElapsedTime().asMilliseconds()>=m_interval->getElapsedTime().asMilliseconds() * 2){
        // }
        m_arenaSolid[kolom][baris]=m_blok_kosong;
    }
}

bool Engine::cekGeser(const char arah[5]){
    //ngecek & ngeeksekusi pergeseran block 
    if(strcmp(arah,"bawah")==0){
        for(const auto kordinat : m_normalizedCurrentBlock){
            // std::cout<<"arenaSize: "<<m_arenaSolid[0].size()<<", pos: "<<pivotBlock.y + kordinat.second<<std::endl;
            if(pivotBlock.y + kordinat.second >=0){
                if(pivotBlock.y + kordinat.second <m_arenaSolid[0].size()-1){
                    if(m_arenaSolid[pivotBlock.x + (kordinat.first)][pivotBlock.y + (kordinat.second)+1]==m_blok_solid){
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
    }else if(strcmp(arah,"kiri")==0){
        if(m_currentBlock->size()%2==1){
            if(pivotBlock.x - (m_currentBlock->size() / 2) >0){
                // pivotBlock.x-=1;
                for(const auto kordinat : m_normalizedCurrentBlock){
                    if(pivotBlock.y + kordinat.second >=0){
                        if(m_arenaSolid[pivotBlock.x + (kordinat.first)-1][pivotBlock.y + (kordinat.second)]==m_blok_solid){
                            return false;
                        }
                    }
                }
            }
            else{
                return false;
            }
        }
    }else if(strcmp(arah,"kanan")==0){
        if(m_currentBlock->size()%2==1){
            if(pivotBlock.x + (m_currentBlock->size() / 2) <m_arenaSolid.size()-1){
                // pivotBlock.x-=1;
                for(const auto kordinat : m_normalizedCurrentBlock){
                    if(pivotBlock.y + kordinat.second >=0){
                        if(m_arenaSolid[pivotBlock.x + (kordinat.first)+1][pivotBlock.y + (kordinat.second)]==m_blok_solid){
                            return false;
                        }
                    }
                }
            }
            else{
                return false;
            }
        }
    }
    return true;
}

void Engine::updatePosisiBlock(){
    //btw ngebersihin layar matriks
    for(int baris=0 ; baris<m_arenaSolid.size() ; baris++){
        // std::cout<<"baris: "<<baris<<std::endl;
        for(int kolom=0 ; kolom<m_arenaSolid[0].size() ; kolom++){
            if(m_arenaSolid[baris][kolom]!=m_blok_solid){
                m_arenaSolid[baris][kolom]=m_blok_kosong;
            }
        }
    }

    for(const auto kordinat : m_normalizedCurrentBlock){ //ngeiterasi posisi block yg udh normal
        if(pivotBlock.y + kordinat.second >=0){ //ngecek apkh elemen bloknya ngelewatin layar matriks atas
            if(cekGeser("bawah")){ //ngecek apkh dibawah ada solid, klo iya ganti seluruh anggota himpunan block jadi solid
                m_arenaSolid[pivotBlock.x + (kordinat.first)][pivotBlock.y + (kordinat.second)]=m_blok_controlled;
            }else{
                m_arenaSolid[pivotBlock.x + (kordinat.first)][pivotBlock.y + (kordinat.second)]=m_blok_solid;
                place();
            }
            // m_arenaSolid[pivotBlock.x + (kordinat.first)][pivotBlock.y + (kordinat.second)+1]=m_blok_debug;
        }
    }
}

void Engine::place(){
    //reset posisi block & nambahin point ke m_blockPlaced
    m_ketinggianBlock=0;
    m_blockPlaced++;
}

void Engine::jatuh(){
    //refresh posisi block & ngecek validitas tiap anggota block dibawahnya
    pivotBlock.y=m_ketinggianBlock;
    if(cekGeser("bawah")){
        m_ketinggianBlock++;
        // m_interval->restart();
        m_interval.restart();
    }
    else{
        place();
    }
    updatePosisiBlock();
}

std::pair<int, int> Engine::normalKeMatriks(std::pair<int, int> normalKordinat, sf::Vector2i* pivotMatriks){
    return {pivotMatriks->x+normalKordinat.second, pivotMatriks->y+normalKordinat.first};
}

std::pair<int, int> Engine::matriksKeNormal(std::pair<int, int> matriksKordinat, std::pair<int, int> pivotMatriks){
    return {matriksKordinat.second-pivotMatriks.second, matriksKordinat.first-pivotMatriks.first};
}


void Engine::geser(const char arah[5]){
    //ngecek & ngeeksekusi pergeseran block
    if(strcmp(arah,"bawah")==0){
        jatuh();

    }else if(strcmp(arah,"kiri")==0){
        if(cekGeser("kiri")){
            pivotBlock.x-=1;
        }

    }else if(strcmp(arah,"kanan")==0){
        if(cekGeser("kanan")){
            pivotBlock.x+=1;
        }
    }
    updatePosisiBlock();
}

void Engine::spawn(){
    //ngecreate block
    m_currentBlock=new std::vector<std::vector<int>>;
    m_currentBlock->assign(3,std::vector<int>(3,0));

    //masang pivotBlock
    if(((*m_currentBlock)[0].size()%2) == 0){
        pivot_currentBlock.y=m_currentBlock->size()/2+0.5f;
    }else{
        pivot_currentBlock.y=m_currentBlock->size()/2;
    }
    
    pivot_currentBlock.x=(*m_currentBlock)[0].size()-1;
    // ({m_currentBlock->size()/2+0.5f, (*m_currentBlock)[0].size()/2});
    
    // std::cout<<static_cast<int>(pivot_currentBlock.x)<<" - "<<static_cast<int>(pivot_currentBlock.y)<<std::endl;
    
    // m_normalizedCurrentBlock=new std::set<std::pair<int, int>>;
    // m_normalizedCurrentBlock=new std::vector<std::vector<int>>;

    // m_normalizedCurrentBlock->assign(3,std::vector<int>(2, 0));

    // m_currentBlock2->push_back({0,0});
    // m_currentBlock2->push_back({0,-1});
    // m_currentBlock2->push_back({-1,-1});
    // m_currentBlock2->push_back({1,-1});

    //ngebuat struktur block
    // (*m_currentBlock)[1][0]=1;
    // (*m_currentBlock)[1][2]=1;
    // (*m_currentBlock)[1][1]=1;
    // (*m_currentBlock)[0][1]=1;
    (*m_currentBlock)[0][2]=1;
    (*m_currentBlock)[1][2]=1;
    (*m_currentBlock)[2][2]=1;
    // (*m_currentBlock)[0][1]=1;
    // (*m_currentBlock)[2][1]=1;

    //konversi posisi matriks dari posisi world block ke posisi yg udah dinormalisasi menyesuaikan pivotBlock
    for(int i=0 ; i<m_currentBlock->size() ; i++){
        for(int j=0 ; j<(*m_currentBlock)[0].size() ; j++){
            if((*m_currentBlock)[i][j]==1){
                // if({i-pivot_currentBlock.y, j-pivot_currentBlock.x} in m_normalizedCurrentBlock)
                if(m_normalizedCurrentBlock.count({i-pivot_currentBlock.y, j-pivot_currentBlock.x})<1){
                    m_normalizedCurrentBlock.insert({i-pivot_currentBlock.y, j-pivot_currentBlock.x});
                }
                // m_normalizedCurrentBlock.in
                // m_normalizedCurrentBlock->push_back({i-pivot_currentBlock.y, j-pivot_currentBlock.x});
                // std::cout<<"test2"<<std::endl;
            }
            // else{
                // std::cout<<"-";
            // }
        }
        // std::cout<<std::endl;
    }
}