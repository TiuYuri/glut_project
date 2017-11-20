#include "cubo.hpp"

Cubo::Cubo(){ 
    nome = "cubo";
    isSelected = false;
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
    
    if(isSelected){
        glColor3f(1.0f,0.0f,1.0f);
    }else{
        glColor3f(cor.corR,cor.corG,cor.corB);
    }

    if(isSolid){
        glutSolidCube(tamanho);
    } else{
        glutWireCube(tamanho);
    }
    
    glPopMatrix();
}