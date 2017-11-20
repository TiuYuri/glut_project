#pragma once
#include "Forms.hpp"

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
    void printer();
    void render();
};