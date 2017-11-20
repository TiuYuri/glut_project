#pragma once
#include <iostream>
#include "Forms.hpp"
#include "Ponto.hpp"
#include "Color.hpp"
#include <GL/glut.h>
#include <vector>

class Cubo : public Forms
{
public:
    GLdouble tamanho;
    bool isSolid;

    Cubo();
    void setCubo(GLdouble tam);
    void setIsSolid(bool state);
    vector<float> getColor();
    void printer();
    void render();
};