//
// Created by nverl on 20/04/2024.
//

#ifndef CULVERT_S_MAN_ARMA_H
#define CULVERT_S_MAN_ARMA_H


class Arma {
    explicit Arma(int f=5);

public:
    void setForza(int f){
        forza = f;
    }
    int getForza()const{
        return forza;
    }

protected:
    int forza;


};


#endif //CULVERT_S_MAN_ARMA_H
