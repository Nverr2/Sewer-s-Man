//
// Created by nverl on 20/04/2024.
//

#include <iostream>
#include "menu.h"
#include "Player.h"

menu::menu() {
    window = new sf::RenderWindow(sf::VideoMode(900, 680), "Sewer's_Man",sf::Style::Close);
    window->setFramerateLimit(30);
    currentState = 0;

    bgTexture.loadFromFile("../assets/bg.jpg");     //bg settings
    background.setTexture(bgTexture);
    background.setScale(1.8,1.9);

    start.loadFromFile("../assets/start.png");  //start btn settings
    startBtn.setTexture(start);
    startBtn.setPosition(360,344);
    startBtn.setScale(1.7,1.7);

    title.loadFromFile("../assets/title.png");      //title settings
    titolo.setTexture(title);
    titolo.setPosition(190,110);
    titolo.setScale(0.5,0.5);

    Player *pg = new Player();                                  //player settings
    playertexture.loadFromFile("../assets/PG1.png");
    player.setTexture(playertexture);
    player.setPosition(360,360);
    player.setScale(1.2,1.2);

}

void menu::manageEvent() {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){    //movimento a destra
        if (player.getPosition().x + 80 < 900){

            player.move(5,0);


        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){    //movimento a sinistra
        if (player.getPosition().x > 0){

            player.move(-5,0);

        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){    //movimento in su
        if (player.getPosition().y > 0){

            player.move(0,-5);

        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){    //movimento in giu
        if (player.getPosition().y + 100 < 680){

            player.move(0,5);

        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){    //inventario o simile
        //window->draw();
    }

    static bool lock_click;
    sf::Event event;
    while (window->pollEvent(event)) {
        switch (event.type) {
            case (sf::Event::MouseButtonPressed):
                if (event.mouseButton.button == sf::Mouse::Left && lock_click != true){
                    sf::Vector2i position = sf::Mouse::getPosition(*window);
                    std::cout << "Mouse x: " << position.x << "\tMouse y: " << position.y;
                    if(startBtn.getGlobalBounds().contains(position.x, position.y)){
                    std::cout <<"\nfunge";
                    currentState = 1;
                    }
                    lock_click = true;  //to stp the loop;

                }
                break;

            case sf::Event::Closed:
                window->close();
                break;

            default:
                break;
        }
    }
}
void menu::run() {
    while (window->isOpen()) {
        manageEvent();
        renderHUD();
    }
}

void menu::renderHUD() {

    window->clear(sf::Color::Black);

    switch (currentState) {
        case 0:  //std::cout <<"sei finito nel case 0";
                window->draw(background);  //background
                window->draw(startBtn);   //start button
                window->draw(titolo);   //titolo


            break;
        case 1:  //std::cout <<"sei finito nel case 1";
                //background.setTexture();
                window->draw(background);
                window->draw(player);

            break;
        case 2:

            break;
        default:    std::cout <<"sei finito nel default";

            break;
    }
    window->display();

}



