#pragma once
#include <GL/glut.h>
#include <iostream>

using namespace std;

class Ponto
{
    public:
        GLfloat pontoX;
        GLfloat pontoY;
        GLfloat pontoZ;
        
        Ponto();
        void setPonto(GLfloat x, GLfloat y, GLfloat z);
        void printer();

        friend Ponto operator + (const Ponto& a, const Ponto& b) {
            
            auto p = Ponto();
            p.setPonto(
                            a.pontoX + b.pontoX,
                            a.pontoY + b.pontoY,
                            a.pontoZ + b.pontoZ);
            return p;}
};