#include "Quadrado.hpp"



Quadrado::Quadrado(){ 
    nome = "quadrado";
    isSelected = false;
    ponto1 = Ponto();
    ponto2 = Ponto();
    ponto3 = Ponto();
    ponto4 = Ponto();

    translate = Ponto();

    cor = Color();
    cor2 = Color();
    cor3 = Color();
    cor4 = Color();
}

void Quadrado::setQuadrado(vector<GLfloat> pontos){
    if (pontos.size() != 12){
        cout << "tamanho errado do vetor" << endl;
        return;
    }
    ponto1.setPonto(pontos[0],pontos[1],pontos[2]);
    ponto2.setPonto(pontos[3],pontos[4],pontos[5]);
    ponto3.setPonto(pontos[6],pontos[7],pontos[8]);
    ponto4.setPonto(pontos[9],pontos[10],pontos[11]);
}

void Quadrado::setCores(vector<GLfloat> pontos){
    if (pontos.size() == 3){
        cor.setColor(pontos[0],pontos[1],pontos[2]);
        cor2.setColor(pontos[0],pontos[1],pontos[2]);
        cor3.setColor(pontos[0],pontos[1],pontos[2]);
        cor4.setColor(pontos[0],pontos[1],pontos[2]);
        return;
    }
    if(pontos.size() == 12){
    cor.setColor(pontos[0],pontos[1],pontos[2]);
    cor2.setColor(pontos[3],pontos[4],pontos[5]);
    cor3.setColor(pontos[6],pontos[7],pontos[8]);
    cor4.setColor(pontos[9],pontos[10],pontos[11]);
    return;
    }
}

void Quadrado::printer(){
    cout<< "ponto 1:" << endl;
    ponto1.printer();

    cout<< "ponto 2:" << endl;
    ponto2.printer();

    cout<< "ponto 3:" << endl;
    ponto3.printer();

    cout << "ponto 4:" << endl;
    ponto4.printer();
}

void Quadrado::render(){
    Ponto p1 = ponto1 + translate;
    Ponto p2 = ponto2 + translate;
    Ponto p3 = ponto3 + translate;
    Ponto p4 = ponto4 + translate;
glPushMatrix();
if(isSelected){
    glBegin(GL_QUADS);
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3f(p1.pontoX, p1.pontoY, p1.pontoZ);
        glVertex3f(p2.pontoX, p2.pontoY, p2.pontoZ);
        glVertex3f(p3.pontoX, p3.pontoY, p3.pontoZ);
        glVertex3f(p4.pontoX, p4.pontoY, p4.pontoZ);
    glEnd();
}else{
    glBegin(GL_QUADS);
        glColor3f(cor.corR,cor.corG,cor.corB);
        glVertex3f(p1.pontoX, p1.pontoY, p1.pontoZ);
        glColor3f(cor2.corR,cor2.corG,cor2.corB);
        glVertex3f(p2.pontoX, p2.pontoY, p2.pontoZ);
        glColor3f(cor3.corR,cor3.corG,cor3.corB);
        glVertex3f(p3.pontoX, p3.pontoY, p3.pontoZ);
        glColor3f(cor4.corR,cor4.corG,cor4.corB);
        glVertex3f(p4.pontoX, p4.pontoY, p4.pontoZ);
    glEnd();
}

glPushMatrix();
}

vector<float> Quadrado::getColor(){
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

    cores.push_back(cor4.corR);
    cores.push_back(cor4.corG);
    cores.push_back(cor4.corB);
    
    return cores;
}