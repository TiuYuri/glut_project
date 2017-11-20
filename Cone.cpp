#include "Cone.hpp"

Cone::Cone(){ 
    nome = "cone";
    isSelected = false;
    isSolid = true;
    base = 1;
    altura = 1;
    cortes = 4;
    pilha = 4;

    translate = Ponto();
    cor = Color();
}

void Cone::setCone(GLdouble b, GLdouble a, GLint c, GLint p){
    base = b;
    altura = a;
    cortes = c;
    pilha = p;
}

void Cone::setIsSolid(bool state){
    isSolid = state;
}

void Cone::printer(){
    cout<< "cor:" << endl;
    cor.printer();

    cout<< "translate: " << endl;
    translate.printer();
}

void Cone::render(){
    glPushMatrix();
    glTranslatef(translate.pontoX, translate.pontoY, translate.pontoZ);

    if(isSelected){
        glColor3f(1.0f,0.0f,1.0f);
    }else{
        glColor3f(cor.corR,cor.corG,cor.corB);
    }
    
    if(isSolid){
        glutSolidCone(base, altura, cortes, pilha);
    } else{
        glutWireCone(base, altura, cortes, pilha);
    }
    
    glPopMatrix();
}