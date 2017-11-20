#pragma once
#include "Forms.hpp"

class Cubo : public Forms
{
public:
    GLdouble tamanho;
    bool isSolid;

    Cubo();
    void setCubo(GLdouble tam);
    void setIsSolid(bool state);
    void printer();
    void render();
};