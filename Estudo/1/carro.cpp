#include <iostream>
#include "carro.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    
    Carro carro1("Mazda", 350, 1987);
    Carro carro2("Nissan GTR", 457, 1993);
    
    

    ifstream rf;
    ofstream sf;

    sf.open("Garagem.txt");
    if(!sf){
        cout << "Erro!" << endl;
        exit(1);
    }

    carro1.SaveFile(sf);
    carro2.SaveFile(sf);
    sf.close();

    rf.open("Garagem.txt");
    if(!rf) {
        cout << "Erro!" << endl;
        exit(1);
    }
    
    carro1.ReadFile(rf);
    carro2.ReadFile(rf);
    rf.close();



    system("pause");
    return 0;
}