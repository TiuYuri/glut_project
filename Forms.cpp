#include "Forms.hpp"
#include <iostream>

void Forms::printer(){
    cout << "rip printer" << endl;
    return;
}

void Forms::render(){
    return;
}

void Forms::setCores(vector<GLfloat> pontos){
        cor.setColor(pontos[0],pontos[1],pontos[2]);
        return;
}

void Forms::setTranslate(Ponto p){
    translate.setPonto(p.pontoX, p.pontoY,p.pontoZ);
}

void Forms::move(float x, float y, float z){
    translate.setPonto(x + translate.pontoX, y + translate.pontoY,z + translate.pontoZ);
};

vector<float> Forms::getColor(){
    vector<float> vazio;
    return vazio;
}