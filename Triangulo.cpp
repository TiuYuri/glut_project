#include "Triangulo.hpp"



Triangulo::Triangulo(){ 
    nome = "triangulo";
    ponto1 = Ponto();
    ponto2 = Ponto();
    ponto3 = Ponto();

    translate = Ponto();

    cor = Color();
    cor2 = Color();
    cor3 = Color();
}

void Triangulo::setTriangulo(vector<GLfloat> pontos){
    if (pontos.size() != 9){
        cout << "tamanho errado do vetor" << endl;
        return;
    }
    ponto1.setPonto(pontos[0],pontos[1],pontos[2]);
    ponto2.setPonto(pontos[3],pontos[4],pontos[5]);
    ponto3.setPonto(pontos[6],pontos[7],pontos[8]);
}

void Triangulo::setCores(vector<GLfloat> pontos){
    if (pontos.size() == 3){
        cor.setColor(pontos[0],pontos[1],pontos[2]);
        cor2.setColor(pontos[0],pontos[1],pontos[2]);
        cor3.setColor(pontos[0],pontos[1],pontos[2]);
        return;
    }
    if(pontos.size() == 9){
    cor.setColor(pontos[0],pontos[1],pontos[2]);
    cor2.setColor(pontos[3],pontos[4],pontos[5]);
    cor3.setColor(pontos[6],pontos[7],pontos[8]);
    return;
    }
}

void Triangulo::printer(){
    cout<< "ponto 1:" << endl;
    ponto1.printer();

    cout<< "ponto 2:" << endl;
    ponto2.printer();

    cout<< "ponto 3:" << endl;
    ponto3.printer();

    cout<< "cor 1:" << endl;
    cor.printer();

    cout<< "cor 2:" << endl;
    cor2.printer();

    cout<< "cor 3:" << endl;
    cor3.printer();
}

void Triangulo::render(){
    Ponto p1 = ponto1 + translate;
    Ponto p2 = ponto2 + translate;
    Ponto p3 = ponto3 + translate;

glPushMatrix();
glBegin(GL_TRIANGLES);
    glColor3f(cor.corR,cor.corG,cor.corB);
    glVertex3f(p1.pontoX, p1.pontoY, p1.pontoZ);
    glColor3f(cor2.corR,cor2.corG,cor2.corB);
    glVertex3f(p2.pontoX, p2.pontoY, p2.pontoZ);
    glColor3f(cor3.corR,cor3.corG,cor3.corB);
    glVertex3f(p3.pontoX, p3.pontoY, p3.pontoZ);
glEnd();
glPopMatrix();
}

vector<float> Triangulo::getColor(){
    vector<float> cores;
    cores.push_back(cor.corR);
    cores.push_back(cor.corG);
    cores.push_back(cor.corB);

    cores.push_back(cor2.corR);
    cores.push_back(cor2.corG);
    cores.push_back(cor2.corB);

    cores.push_back(cor3.corR);
    cores.push_back(cor3.corG);
    cores.push_back(cor3.corB);
    return cores;
}