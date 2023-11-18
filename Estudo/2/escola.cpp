#include <iostream>
#include "escola.h"

using namespace std;

int main(int argc, char* argv[]){

    Professor prof1("Iracema", 48, "Matematica");
    Professor prof2("Joao", 52, "Compiladores");
    
    prof1.MaisVelho(prof2);

    ifstream rf;
    ofstream sf;

    sf.open("Escola.txt");
    if(!sf){
        cout << "Erro!" << endl;
        exit(1);
    }

    prof1.SaveFIle(sf);
    prof2.SaveFIle(sf);
    sf.close();

    rf.open("Escola.txt");
    if(!rf){
        cout << "Erro!" << endl;
        exit(1);
    }

    prof1.ReadFile(rf);
    prof2.ReadFile(rf);
    rf.close();


    system("pause");
    return 0;
}