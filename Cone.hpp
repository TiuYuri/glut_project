#pragma once
#include "Forms.hpp"

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
    void printer();
    void render();
};