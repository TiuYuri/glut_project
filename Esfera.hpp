#pragma once
#include <iostream>
#include "Forms.hpp"
#include "Ponto.hpp"
#include "Color.hpp"
#include <GL/glut.h>
#include <vector>

class Esfera : public Forms
{
public:
    GLdouble raio;
    GLint cortes;
    GLint pilha;
    bool isSolid;
    Esfera();
    void setEsfera(GLdouble raio, GLint cortes, GLint pilha);
    void setIsSolid(bool state);
    vector<float> getColor();
    void printer();
    void render();
};