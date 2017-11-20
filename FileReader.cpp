#include "FileReader.hpp"

FileReader::FileReader(){

}

vector<string> FileReader::split(const string& s, char delimiter){
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

bool FileReader::is_number(const string& s)
{
    return( strspn( s.c_str(), "-.0123456789" ) == s.size() );
}

void FileReader::readTriangle(vector<string> tokens){
    tokens.erase(tokens.begin());
    vector<GLfloat> pontos;
    for(int i = 1; i < 10; i++){
        pontos.push_back(stof(tokens[0]));
        tokens.erase(tokens.begin());
    }

    Triangulo *trianguloide = new Triangulo();
    trianguloide->setTriangulo(pontos);

    while (!tokens.empty()){
        if(tokens[0] == "cor"){
            vector<GLfloat> cores;
            tokens.erase(tokens.begin());
            if(tokens.size() >= 9 && is_number(tokens[3])){
                for(int i = 0; i < 9; i++){
                    cores.push_back(stof(tokens[0]));
                    tokens.erase(tokens.begin());
                }
            } else{
                for(int i = 0; i < 3; i++){
                    cores.push_back(stof(tokens[0]));
                    tokens.erase(tokens.begin());
                }
            }
            trianguloide->setCores(cores);
            continue;
        }
        if(tokens[0] == "translate"){
            tokens.erase(tokens.begin());

            Ponto p = Ponto();
            p.pontoX = stof(tokens[0]);
            tokens.erase(tokens.begin());

            p.pontoY = stof(tokens[0]);
            tokens.erase(tokens.begin());

            p.pontoZ = stof(tokens[0]);
            tokens.erase(tokens.begin());
            

            trianguloide->setTranslate(p);
        }

    }
    objetos.push_back(trianguloide);
}

//-----------------------------------------------------

void FileReader::readSphere(vector<string> tokens){
    tokens.erase(tokens.begin());
    
    GLdouble raio = stod(tokens[0]);
    tokens.erase(tokens.begin());

    GLint cortes = stoi(tokens[0]);
    tokens.erase(tokens.begin());

    GLint pilha = stoi(tokens[0]);
    tokens.erase(tokens.begin());

    Esfera *sphere = new Esfera();
    sphere->setEsfera(raio, cortes, pilha);

    while(!tokens.empty()){
        if(tokens[0] == "cor"){
            tokens.erase(tokens.begin());
            vector<GLfloat> cores;
            for(int i = 0; i < 3; i++){
                
                cores.push_back(atof(tokens[0].c_str()));
                tokens.erase(tokens.begin());
            }
            sphere->setCores(cores);
        }

        if(tokens[0] == "translate"){
            tokens.erase(tokens.begin());

            Ponto p = Ponto();
            p.pontoX = stof(tokens[0]);
            tokens.erase(tokens.begin());

            p.pontoY = stof(tokens[0]);
            tokens.erase(tokens.begin());

            p.pontoZ = stof(tokens[0]);
            tokens.erase(tokens.begin());
            

            sphere->setTranslate(p); 
        }

        if(tokens[0] == "wired"){
            tokens.erase(tokens.begin());
            sphere->setIsSolid(false); 
            continue;
        }
    }
    objetos.push_back(sphere);
}

//---------------------------------------

void FileReader::readCone(vector<string> tokens){
    tokens.erase(tokens.begin()); 
    
    GLdouble base = stod(tokens[0]);
    tokens.erase(tokens.begin());

    GLdouble altura = stod(tokens[0]);
    tokens.erase(tokens.begin());

    GLint cortes = stoi(tokens[0]);
    tokens.erase(tokens.begin());

    GLint pilha = stoi(tokens[0]);
    tokens.erase(tokens.begin());

    Cone *cone = new Cone();
    cone->setCone(base, altura, cortes, pilha);

    while(!tokens.empty()){
        if(tokens[0] == "cor"){
            tokens.erase(tokens.begin());
            vector<GLfloat> cores;
            for(int i = 0; i < 3; i++){
                
                cores.push_back(atof(tokens[0].c_str()));
                tokens.erase(tokens.begin());
            }
            cone->setCores(cores);
        }

        if(tokens[0] == "translate"){
            tokens.erase(tokens.begin());

            Ponto p = Ponto();
            p.pontoX = stof(tokens[0]);
            tokens.erase(tokens.begin());

            p.pontoY = stof(tokens[0]);
            tokens.erase(tokens.begin());

            p.pontoZ = stof(tokens[0]);
            tokens.erase(tokens.begin());
            

            cone->setTranslate(p); 
        }

        if(tokens[0] == "wired"){
            tokens.erase(tokens.begin());
            cone->setIsSolid(false); 
            continue;
        }
    }
    objetos.push_back(cone);
}

//-------------------------------

void FileReader::readSquare(vector<string> tokens){
    tokens.erase(tokens.begin());
    vector<GLfloat> pontos;
    for(int i = 1; i < 13; i++){
        pontos.push_back(stof(tokens[0]));
        tokens.erase(tokens.begin());
    }

    Quadrado *square = new Quadrado(); 
    square->setQuadrado(pontos);

    while (!tokens.empty()){
        if(tokens[0] == "cor"){
            vector<GLfloat> cores;
            tokens.erase(tokens.begin());
            if(tokens.size() >= 12 && is_number(tokens[3])){
                for(int i = 0; i < 12; i++){
                    cores.push_back(stof(tokens[0]));
                    tokens.erase(tokens.begin());
                }
            } else{
                for(int i = 0; i < 3; i++){
                    cores.push_back(stof(tokens[0]));
                    tokens.erase(tokens.begin());
                }
            }
            cores.size();
            square->setCores(cores);
            continue;
        }
        if(tokens[0] == "translate"){
            tokens.erase(tokens.begin());

            Ponto p = Ponto();
            p.pontoX = stof(tokens[0]);
            tokens.erase(tokens.begin());

            p.pontoY = stof(tokens[0]);
            tokens.erase(tokens.begin());

            p.pontoZ = stof(tokens[0]);
            tokens.erase(tokens.begin());
            

            square->setTranslate(p);
            continue;
        }

    }
    objetos.push_back(square);
}

//----------------------------------------

void FileReader::readCube(vector<string> tokens){
    tokens.erase(tokens.begin());
    
    GLdouble tam = stod(tokens[0]);
    tokens.erase(tokens.begin());

    Cubo *cube = new Cubo();
    cube->setCubo(tam);

    while(!tokens.empty()){
        if(tokens[0] == "cor"){
            tokens.erase(tokens.begin());
            vector<GLfloat> cores;
            for(int i = 0; i < 3; i++){
                
                cores.push_back(atof(tokens[0].c_str()));
                tokens.erase(tokens.begin());
            }
            cube->setCores(cores);
            continue;
        }

        if(tokens[0] == "translate"){
            tokens.erase(tokens.begin());

            Ponto p = Ponto();
            p.pontoX = stof(tokens[0]);
            tokens.erase(tokens.begin());

            p.pontoY = stof(tokens[0]);
            tokens.erase(tokens.begin());

            p.pontoZ = stof(tokens[0]);
            tokens.erase(tokens.begin());
            

            cube->setTranslate(p);
            continue;
        }

        if(tokens[0] == "wired"){
            tokens.erase(tokens.begin());
            cube->setIsSolid(false);
            continue;
        }
    }
    objetos.push_back(cube);
}


vector<Forms*> FileReader::readFile(){
	ifstream myfile;
    myfile.open (FILE_NAME);
    

    string str;
	while (getline(myfile, str)) {
        vector<string> tokens = split(str, ' ');

        if(tokens.size() != 0 ){
            if (tokens[0] == "triangulo"){
                readTriangle(tokens);
                continue;
            }
            if(tokens[0] == "esfera"){
                readSphere(tokens);
                continue;
            }
            if(tokens[0] == "quadrado"){
                readSquare(tokens);
                continue;
            }
            if(tokens[0] == "cubo"){
                readCube(tokens);
                continue;
            }
            if(tokens[0] == "cone"){
                readCone(tokens);
                continue;
            }

            else
                cout << "deu merda" << endl;
        }
    }
    return objetos;
}