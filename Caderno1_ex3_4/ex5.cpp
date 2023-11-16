#include <iostream>
#include "ex.h"
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    Funcionario funcionario1(25023, "Pintura", Pessoa("Joca Gaio", "Rua da direita n 2", Data(20,9,1987)));
    Funcionario funcionario2(25024, "Comercial", Pessoa("Ana Rola", "Rua da direita n 3", Data(4,2,1990)));

    funcionario1.Show();
    funcionario2.Show();

    ofstream ofile;
    string str = "funcionarios.txt";

    if(ofile){
        funcionario1.SaveFile(ofile);
        funcionario2.SaveFile(ofile);
        ofile.close();
        cout << "O ficheiro " << str << "foi criado" << endl;
    } else {
        cout << "Erro" << endl;
        exit(1);
    }

    ifstream ifile;
    ifile.open(str.c_str());

    Funcionario funcionario[4];

    if(ifile){
        int i=0;

        while(ifile.peek() != EOF){
            funcionario[i].ReadFile(ifile);
            i++;
        }
        ifile.close();
        cout << "Ficheiro: " << str << "criado com sucesso";
    } else{
        cout << "Erro" << endl;
        exit(1);
    }

    funcionario->BubbleSort(funcionario,2);

    cout << "Vetor ordenado!" << endl;
    int contador = 2;
    for (int i=0; i<contador; i++){
        cout << funcionario[i] << endl;
    }



    system("pause");
    return 0;
}