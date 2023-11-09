#include <iostream>
#include "ex.h"
#include <cstring>
#include <string>
#include <fstream>


using namespace std;

int main(int argc, char * argv[]){
    Pessoa pessoa1("Joni Culatra", "Rua da direita n2", Data(20,9,1987));
    Pessoa pessoa2("Joni Rato", "Rua da direita n3", Data(4,2,1990));

    ofstream ofile;
    string str = "pessoas.txt";
    cout << "Nome do ficheiro para guardar dados: " << endl;
    cin >> str;
    

    ofile.open(str.c_str());

    if(ofile){
        pessoa1.SaveFile(ofile);
        pessoa2.SaveFile(ofile);
        ofile.close();
        cout << "Info guardada com sucesso ";

    }


    Pessoa p[3];
    int size = 0, i;

    ifstream ifile;
    ifile.open("pessoas.txt");
    if(ifile) {
        while (ifile.peek() != EOF ){
            p[size].ReadFileVector(ifile);
            ifile.get();
            size++;
            cout << "while";
        }

        ifile.close();
        cout << "Ficheiro lido com sucesso." << endl;
    } else {
        cout << "Erro." << endl;
    }

    cout << "Nome: Joni Cultra" << endl << endl;
    for (i=0; i<size; i++){
        if(p[i].getNome() == "Joni Culatra"){
            p[i].Show();
        }
    }

    system("pause");
    return 0;
}