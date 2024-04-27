//
// Created by nverl on 20/04/2024.
//

#ifndef CULVERT_S_MAN_MENU_H
#define CULVERT_S_MAN_MENU_H
#include "SFML/Graphics.hpp"


class menu {
public:
    menu();


    void run();
    void renderHUD();
    void manageEvent();
private:
    sf::RenderWindow* window;
    sf::Texture bgTexture;
    sf::Sprite background;
    sf::Texture start;
    sf::Sprite startBtn;
    sf::Texture title;
    sf::Sprite titolo;
    int currentState;
    sf::Texture playertexture;
    sf::Sprite player;

};


#endif //CULVERT_S_MAN_MENU_H
