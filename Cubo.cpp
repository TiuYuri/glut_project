#include "cubo.hpp"

Cubo::Cubo(){ 
    nome = "cubo";
    isSolid = true;
    tamanho = 1;

    translate = Ponto();
    cor = Color();
}

void Cubo::setCubo(GLdouble tam){
    tamanho = tam;
}

void Cubo::setIsSolid(bool state){
    isSolid = state;
}

void Cubo::printer(){
    cout<< "tamanho: "<< tamanho << endl;

    cout<< "cor:" << endl;
    cor.printer();

    cout<< "translate: " << endl;
    translate.printer();
}

void Cubo::render(){
    glPushMatrix();
    glTranslatef(translate.pontoX, translate.pontoY, translate.pontoZ);
    glColor3f(cor.corR,cor.corG,cor.corB);
    if(isSolid){
        glutSolidCube(tamanho);
    } else{
        glutWireCube(tamanho);
    }
    
    glPopMatrix();
}

vector<float> Cubo::getColor(){
    vector<float> cores;
    cores.push_back(cor.corR);
    cores.push_back(cor.corG);
    cores.push_back(cor.corB);
    
    return cores;
}