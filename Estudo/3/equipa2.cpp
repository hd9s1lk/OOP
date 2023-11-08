#include <iostream>
#include "equipa.h"

using namespace std;

int main(int argc, char* argv[]){

    Funcionario func1("Henrique", 20, 3, Empresa("Vila Seca Festividades", "Vila Real", 8));
    Funcionario func2("Manuela", 23, 6, Empresa("Foot Funny", "Porto", 15));


    ifstream in;
    ofstream out;

    out.open("Equipa2.txt");
    if(!out){
        cout << "Erro" << endl;
        exit(1);
    }

    func1.SaveFile(out);
    func2.SaveFile(out);
    out.close();

    in.open("Equipa2.txt");
    if(!in){
        cout << "Erro" << endl;
        exit(1);
    }

    func1.ReadFile(in);
    func2.ReadFile(in);
    in.close();


    system("pause");
    return 0;
}