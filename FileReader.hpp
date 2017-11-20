#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>     /* atof */
#include <string.h>

#include "Triangulo.hpp"
#include "Esfera.hpp"
#include "Quadrado.hpp"
#include "cubo.hpp"
#include "Cone.hpp"
#include "Forms.hpp"
using namespace std;

#define FILE_NAME "load_file.txt"



class FileReader
{
public:
        vector<Forms*> objetos;

        FileReader();
        vector<Forms*> readFile();
        vector<string> split(const string& s, char delimiter);
        bool is_number(const string& s);
        void readTriangle(vector<string> tokens);
        void readSphere(vector<string> tokens);
        void readSquare(vector<string> tokens);
        void readCube(vector<string> tokens);
        void readCone(vector<string> tokens);
};