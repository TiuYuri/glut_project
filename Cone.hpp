#pragma once
#include <iostream>
#include "Forms.hpp"
#include "Ponto.hpp"
#include "Color.hpp"
#include <GL/glut.h>
#include <vector>

class Cone : public Forms
{
public:
    GLdouble base;
    GLdouble altura;
    GLint cortes;
    GLint pilha;
    bool isSolid;
    
    Cone();
    void setCone(GLdouble b, GLdouble a, GLint c, GLint p);
    void setIsSolid(bool state);
    vector<float> getColor();
    void printer();
    void render();
};