#pragma once
#include <SFML/Graphics.hpp>

class Arrow : public sf::ConvexShape{
    public:
        Arrow(bool isRight, sf::Color fillColor, sf::Color outlineColor){
            this->setPointCount(3);

            if (isRight) {

                this->setPoint(0, sf::Vector2f(0.f, 0.f));    // Cermin dari (20, 0)
                this->setPoint(1, sf::Vector2f(20.f, 10.f));  // Cermin dari (0, 10) -> Jadi Ujung Panah
                this->setPoint(2, sf::Vector2f(0.f, 20.f));   // Cermin dari (20, 20)
                
                // PERHATIKAN BAGIAN INI GAN!
                this->setOrigin(sf::Vector2f(0.f, -11.f));

                // this->setPoint(0, sf::Vector2f(0.f, 0.f));
                // this->setPoint(1, sf::Vector2f(20.f, 10.f));
                // this->setPoint(2, sf::Vector2f(0.f, 20.f));

                this->setOrigin(sf::Vector2f(-25.f, -11.f));
            } else { // Arrow Kiri
                this->setPoint(0, sf::Vector2f(20.f, 0.f));
                this->setPoint(1, sf::Vector2f(0.f, 10.f));
                this->setPoint(2, sf::Vector2f(20.f, 20.f));
                // this->setOrigin(sf::Vector2f(0.f, -11.f));
                this->setOrigin(sf::Vector2f(20.f, -11.f));
            }

            this->setFillColor(fillColor);
            this->setOutlineColor(outlineColor);
        }
};