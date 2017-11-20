#include "Ponto.hpp"

        Ponto::Ponto(){ 
            GLfloat a = 0;
            pontoX = a;
            pontoY = a;
            pontoZ = a;
        }

        void Ponto::setPonto(GLfloat x, GLfloat y, GLfloat z){
            pontoX = x;
            pontoY = y;
            pontoZ = z;
        }

        void Ponto::printer(){
            cout << "x: " << pontoX << ",";
            cout << " y: " << pontoY << ",";
            cout << " z: " << pontoZ << endl;
        }
    
