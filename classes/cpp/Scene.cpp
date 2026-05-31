#include "../headers/Scene.hpp"
#include "../headers/Entity.hpp"
#include <iostream>
#include <string>
#include <cstring>


//Scene(std::string nama,sf::Vector2i ukuran)
Scene::Scene(std::string nama,sf::Vector2i ukuran){
    m_skor=0;
    m_nama=nama;
    m_ukuranMatriks=ukuran;
    m_arenaSolid.assign(m_ukuranMatriks.x, std::vector<int>(m_ukuranMatriks.y, 0));
    m_arena=m_arenaSolid;
    m_margin=24.0f;
    m_ketinggianBlock=0;
    m_interval_timeout=1;

    m_blok_kosong=0;
    m_blok_solid=1;
    m_blok_controlled=2;
    m_blok_debug=3;
}

void Scene::start(){
    if(m_window!=nullptr){
        m_pivotMatriks={m_margin, m_margin};
        // m_pivotMatriks={0.0f, 0.0f};

        //setup panel
        panel.setFillColor(sf::Color::Black);
        panel.setOutlineColor(sf::Color::White);
        panel.setOutlineThickness(1.0f);

        //setup panel buat preview
        panelPreview.setFillColor(sf::Color::Black);
        panelPreview.setOutlineColor(sf::Color::White);
        panelPreview.setOutlineThickness(1.0f);

        //ngecreate komponen teks
        sf::Text* m_text_skor = new sf::Text(*m_font,"skor",32);
        sf::Text* m_text_next = new sf::Text(*m_font,"next:",32);

        m_text_skor->setFillColor(sf::Color::White);
        m_text_next->setFillColor(sf::Color::White);

        
        //nyimpen komponen teks kedalem pointer himpunan
        m_kumpulanTeks["skor"]=m_text_skor;
        m_kumpulanTeks["next"]=m_text_next;
        
        // m_kumpulanTeks["next"]->setString("Next: ");
        // m_kumpulanTeks["next"]->setPosition({panelPreview.getPosition().x, panelPreview.getPosition().y - (m_margin * 2)});

        m_boxVisual.setOutlineThickness(1.0f);
        spawn();
        m_interval->restart();

        m_boxVisual.setSize({23, 23});
        pivotBlock.x=static_cast<int>(m_arenaSolid.size()/2);
        m_arenaSolid[m_arenaSolid.size()/2][m_arenaSolid[0].size()/2]=m_blok_solid;


        // std::pair<int, int> posNor({0, -2});
        // // std::pair<int, int> posMtx({1, 2});
        // sf::Vector2i posPivMtx({2, 1});
        // std::cout<<"hasil n->m: "<<normalKeMatriks(posNor,&posPivMtx).first<<", "<<normalKeMatriks(posNor,&posPivMtx).second<<std::endl;
        // std::cout<<"hasil: m->n: "<<matriksKeNormal(posMtx,&posPivMtx).first<<", "<<matriksKeNormal(posMtx,&posPivMtx).second<<std::endl;
    }
}

bool Scene::cekValidBaris(int baris){
    for(int kolom=0 ; kolom<m_arenaSolid.size() ; kolom++){
        // std::cout<<"baris: "<<baris<<", kolom:"<<kolom<<std::endl;
        if(m_arenaSolid[kolom][baris]==m_blok_kosong || m_arenaSolid[kolom][baris]==m_blok_controlled){
            return false;
        }
    }
    return true;
}
void Scene::clearBaris(int baris){
    for(int kolom=0 ; kolom<m_arenaSolid.size() ; kolom++){
        // std::cout<<"baris: "<<baris<<", kolom:"<<kolom<<std::endl;
        // float savedInterval=m_interval->getElapsedTime().asMilliseconds();
        // m_arenaSolid[kolom][baris]=m_blok_controlled;
        // if(m_interval->getElapsedTime().asMilliseconds()>=m_interval->getElapsedTime().asMilliseconds() * 2){
        // }
        m_arenaSolid[kolom][baris]=m_blok_kosong;
    }
}

void Scene::update(){
    //btw ngerender matriks arena
    for(int baris=0; baris<m_ukuranMatriks.x;baris++){
        for(int kolom=0; kolom<m_ukuranMatriks.y;kolom++){
            if(m_arenaSolid[baris][kolom]==m_blok_kosong){
                m_boxVisual.setFillColor(sf::Color::Black);
            }else if(m_arenaSolid[baris][kolom]==m_blok_solid){
                m_boxVisual.setFillColor(sf::Color::Green);
            }else if(m_arenaSolid[baris][kolom]==m_blok_controlled){
                m_boxVisual.setFillColor(sf::Color::Yellow);
            }else if(m_arenaSolid[baris][kolom]==m_blok_debug){
                m_boxVisual.setFillColor(sf::Color::Red);
            }else{
                m_boxVisual.setFillColor(sf::Color::Cyan);
            }
            if(cekValidBaris(kolom)){
                clearBaris(kolom);
            }
            // m_arenaSolid[m_currentBlock[0].size()-1][pivotBlock.x - (m_currentBlock->size() / 2)]=3;
            m_boxVisual.setOutlineColor(sf::Color::White);
            m_boxVisual.setPosition({m_pivotMatriks.x + (baris * (m_boxVisual.getSize().x + 2)), m_pivotMatriks.y + (kolom * (m_boxVisual.getSize().y + 2))});
            m_window->draw(m_boxVisual);
            
        }
    }



    //ngeset size & posisi tiap komponen panel
    panel.setPosition({((m_boxVisual.getSize().x + 3) * m_ukuranMatriks.x) + m_margin + m_pivotMatriks.x, m_margin});
    panel.setSize({m_window->getSize().x - ((m_boxVisual.getSize().x + 3) * m_ukuranMatriks.x + (m_margin * 2) + m_pivotMatriks.x), m_window->getSize().y-(m_margin * 2)});

    panelPreview.setPosition({panel.getPosition().x + m_margin, panel.getSize().y / 2});
    panelPreview.setSize({panel.getSize().x - (m_margin * 2), panel.getSize().y / 2});

    //ngeset teks & posisi tiap komponen teks
    m_kumpulanTeks["skor"]->setString("Total Skor: "+std::to_string(m_skor));
    m_kumpulanTeks["skor"]->setPosition({panel.getPosition().x + (m_margin / 2), panel.getPosition().y});

    // m_kumpulanTeks["next"]->setString("Interval: "+std::to_string(m_interval->getElapsedTime().asSeconds()));
    m_kumpulanTeks["next"]->setString("Next: ");
    m_kumpulanTeks["next"]->setPosition({panelPreview.getPosition().x, panelPreview.getPosition().y - (m_margin * 2)});

    //ngerender panel
    m_window->draw(panel);
    m_window->draw(panelPreview);

    //btw ngerender previewBlock
    if(m_currentBlock->size()>0){
        m_pivotPreview= new sf::Vector2f({panelPreview.getPosition().x + panelPreview.getSize().x / 2.5f, panelPreview.getPosition().y + panelPreview.getSize().y / 2.5f});
        for(int baris=0; baris<m_currentBlock->size();baris++){
            for(int kolom=0; kolom<m_currentBlock[0].size();kolom++){
                if((*m_currentBlock)[baris][kolom]==0){
                    m_boxVisual.setFillColor(sf::Color::Black);
                    m_boxVisual.setOutlineColor(sf::Color::White);
                }else if((*m_currentBlock)[baris][kolom]==1){
                    m_boxVisual.setFillColor(sf::Color::Blue);
                    m_boxVisual.setOutlineColor(sf::Color::Black);
                }
                else{
                    m_boxVisual.setFillColor(sf::Color::Yellow);
                    m_boxVisual.setOutlineColor(sf::Color::White);
                }
                m_boxVisual.setPosition({m_pivotPreview->x + (baris * (m_boxVisual.getSize().x + 2)), m_pivotPreview->y + (kolom * (m_boxVisual.getSize().y + 2))});
                m_window->draw(m_boxVisual);
                
            }
        }
    }

    //ngecek klo intervalnya udh timeout maka jatuhin block sekitar 1 baris kebawah
    if(m_interval->getElapsedTime().asSeconds()>m_interval_timeout){
        m_interval->restart();
        jatuh();
    }


    m_window->draw(*m_kumpulanTeks["skor"]);
    m_window->draw(*m_kumpulanTeks["next"]);

}

void Scene::updatePosisiBlock(){
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

void Scene::place(){
    //reset posisi block & nambahin point ke m_blockPlaced
    m_ketinggianBlock=0;
    m_blockPlaced++;
}

void Scene::jatuh(){
    //refresh posisi block & ngecek validitas tiap anggota block dibawahnya
    pivotBlock.y=m_ketinggianBlock;
    if(cekGeser("bawah")){
        m_ketinggianBlock++;
        m_interval->restart();
    }
    else{
        place();
    }
    updatePosisiBlock();
}

std::pair<int, int> Scene::normalKeMatriks(std::pair<int, int> normalKordinat, sf::Vector2i* pivotMatriks){
    return {pivotMatriks->x+normalKordinat.second, pivotMatriks->y+normalKordinat.first};
}

std::pair<int, int> Scene::matriksKeNormal(std::pair<int, int> matriksKordinat, std::pair<int, int> pivotMatriks){
    return {matriksKordinat.second-pivotMatriks.second, matriksKordinat.first-pivotMatriks.first};
}

bool Scene::cekGeser(const char arah[5]){
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

void Scene::geser(const char arah[5]){
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

void Scene::spawn(){
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