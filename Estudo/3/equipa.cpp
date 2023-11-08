#include <iostream>
#include "equipa.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){

    Empresa emp1("Vila Seca Festividades", "Vila Real", 8);
    Empresa emp2("Foot Funny", "Porto", 15);


    emp1.Show();
    emp1.Igual(emp2);

    ifstream in;
    ofstream out;

    out.open("Equipa.txt");
    if(!out){
        cout << "Erro" << endl;
        exit(1);
    }

    emp1.SaveFile(out);
    emp2.SaveFile(out);

    out.close();

    in.open("Equipa.txt");
    if(!in){
        cout << "Erro" << endl;
        exit(1);
    }

    emp1.ReadFile(in);
    emp2.ReadFile(in);
    in.close();

    

    system("pause");
    return 0;
}