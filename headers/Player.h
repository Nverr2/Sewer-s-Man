//
// Created by nverl on 20/04/2024.
//

#ifndef CULVERT_S_MAN_PLAYER_H
#define CULVERT_S_MAN_PLAYER_H

#include <string>
#include "Arma.h"

using namespace std;


class Player {


public:
    explicit  Player(float hp=50, int attack=5, int def=5);

    void setHP(float hp){
        HP = hp;
    }
    float getHP() const{
        return HP;
    }
    void setAttack(int a){
        attack=a;
    }
    int getAttack() const{
        return attack;
    }
    void setDefense(int d){
        defense=d;
    }
    int getDefense() const{
        return defense;
    }
    void setPosx (int x){
        posx=x;
    }
    int getPosx() const{
        return posx;
    }
    void setPosy (int y){
        posy=y;
    }
    int getPosy() const{
        return posy;
    }
    void setArma(Arma *a){
        arma=a;
    }
    Arma* getArma(){
        return arma;
    }




private:
    float HP;
    string name;
    int attack;
    int defense;
    int posx;
    int posy;
    Arma *arma;
};


#endif //CULVERT_S_MAN_PLAYER_H
