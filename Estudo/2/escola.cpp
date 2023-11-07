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

    prof1.SaveFile(sf);
    prof2.SaveFile(sf);
    sf.close();

    rf.open("Escola.txt");
    if(!rf){
        cout << "Erro!" << endl;
        exit(1);
    }

    prof1.ReadFile(rf);
    prof2.ReadFile(rf);
    rf.close();

    string str = "Escola.txt";

    cout << "Nome do ficheiro: " << endl;
    cin >> str;

    sf.open(str.c_str());
    if(sf){
        prof1.SaveFile(sf);
        prof2.SaveFile(sf);
        cout << "Ficheiro " << str << "criado com sucesso" << endl;
    } else {
        cout << "Erro" << endl;
    }

    Professor p[3];

    int size;
    int i;

    ifstream ifile;
    ifile.open("Escola.txt");
    if (ifile){
        while(ifile.peek() != EOF){
            p[size].ReadFile(ifile);
            ifile.get();
            size++;
            cout << "While: " << endl;
        }
        ifile.close();
    } else {
        cout << "Erro" << endl;
    }

    for(i=0; i<size; i++){
        p[i].Show();
    }


    system("pause");
    return 0;
}