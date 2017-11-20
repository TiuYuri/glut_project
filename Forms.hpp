#pragma once
#include <string>
#include "Ponto.hpp"
#include "Color.hpp"

using namespace std;

class Forms
{
    public:
        string nome;
        Ponto translate;
        Color cor;
        bool isSelected;

    virtual void printer();
    virtual void render();
    virtual void setCores(vector<GLfloat> cores);
    virtual void setTranslate(Ponto p);
    virtual void move(float x, float y, float z);
    virtual vector<float> getColor();
};