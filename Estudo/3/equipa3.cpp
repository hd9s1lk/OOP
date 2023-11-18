#include <iostream>
#include <fstream>
#include <vector>
#include "equipa.h"

using namespace std;

int main(int argc, char* argv[]){


    vector<Funcionario*> Lista;

    bool running = true;
    int op;
    
    while(running){
        cout << "Bem Vindo ao Menu Principal" << endl;
        cout << "\t 1- Ler ficheiro" << endl;
        
    }

    system("pause");
    return 0;
}


void LerFicheiro(vector<Funcionario*> &Lista){
    ifstream ifile;
    ifile.open("Equipa3.txt");

    if(!ifile.is_open()){
        exit(-1);
    }
    
}