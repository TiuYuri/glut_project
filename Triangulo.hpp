#pragma once
#include <iostream>
#include "Forms.hpp"
#include "Ponto.hpp"
#include "Color.hpp"
#include <GL/glut.h>
#include <vector>

class Triangulo : public Forms
{
public:
    Ponto ponto1;
    Ponto ponto2;
    Ponto ponto3;

    Color cor2;
    Color cor3;
 

    Triangulo();
    void setTriangulo(vector<GLfloat> pontos);
    void setCores(vector<GLfloat> cores);
    vector<float> getColor();
    void printer();
    void render();
};