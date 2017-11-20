#pragma once
#include <GL/glut.h>
#include <iostream>
#include <vector>

using namespace std;

class Color
{
    public:
        GLfloat corR;
        GLfloat corG;
        GLfloat corB;
        
        Color();
        void setColor(GLfloat x, GLfloat y, GLfloat z);
        vector<float> getColor();
        void printer();
    }; 