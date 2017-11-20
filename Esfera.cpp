#include "Esfera.hpp"

Esfera::Esfera(){ 
    nome = "esfera";
    raio = 1;
    cortes = 10;
    pilha = 10;
    translate = Ponto();
    isSolid = true;

    cor = Color();
}

void Esfera::setEsfera(GLdouble raio, GLint cortes, GLint pilha){
    raio = raio;
    cortes = cortes;
    pilha = pilha;
}

void Esfera::setIsSolid(bool state){
    isSolid = state;
}

void Esfera::printer(){
    cout<< "raio: "<< raio << endl;

    cout<< "cortes: "<< cortes << endl;

    cout<< "pilha: "<< pilha << endl;

    cout<< "cor:" << endl;
    cor.printer();

    cout<< "translate: " << endl;
    translate.printer();
}

void Esfera::render(){
    glPushMatrix();
    glTranslatef(translate.pontoX, translate.pontoY, translate.pontoZ);
    glColor3f(cor.corR,cor.corG,cor.corB);
    if(isSolid){
        glutSolidSphere(raio, cortes, pilha);
    } else{
        glutWireSphere(raio, cortes, pilha);
    }
    
    glPopMatrix();
}

vector<float> Esfera::getColor(){
    vector<float> cores;
    cores.push_back(cor.corR);
    cores.push_back(cor.corG);
    cores.push_back(cor.corB);
    
    return cores;
}