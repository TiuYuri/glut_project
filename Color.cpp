#include "Color.hpp"

Color::Color(){ 
    GLfloat a = 1;
    corR = a;
    corG = a;
    corB = a;
}

void Color::setColor(GLfloat r, GLfloat g, GLfloat b){
    corR = r;
    corG = g;
    corB = b;
}

void Color::printer(){
    cout << "r: " << corR << ",";
    cout << " g: " << corG << ",";
    cout << " b: " << corB << endl;
}

vector<float> Color::getColor(){
    vector<float> cores; 
    cores.push_back(corR);
    cores.push_back(corG);
    cores.push_back(corB);
}
