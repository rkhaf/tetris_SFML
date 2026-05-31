#include <SFML/Graphics.hpp>
#include <iostream>
#include "../headers/Entity.hpp"

Entity::Entity(int x, int y){
    // m_block=bentuk;
    m_block.assign(x, std::vector<int>(y, 0));
    m_x=x;
    m_y=y;

}
void Entity::update(){

}

void Entity::spawn(){
    m_block[1][0]=1;
    m_block[1][2]=1;
    m_block[1][1]=1;
    m_block[0][1]=1;
    m_block[2][1]=1;
    // std::cout<<"sukses"<<std::endl;
}
