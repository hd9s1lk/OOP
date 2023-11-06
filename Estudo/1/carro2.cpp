#include <iostream>
#include <fstream>
#include "carro.h"

using namespace std;

int main(int argc, char* argv[]){

    Passageiro passenger1("Henrique", 20, Carro("Kia", 100, 2023));
    
    ifstream rf;
    ofstream sf;

    sf.open("Garagem.txt");
    if(!sf){
        cout << "Erro!" << endl;
        exit(1);
    }

    passenger1.SaveFile(sf);
    sf.close();

    rf.open("Garagem.txt");
    if(!rf) {
        cout << "Erro!" << endl;
        exit(1);
    }

    passenger1.ReadFile(rf);
    rf.close();


   ofstream ler;
   string str = "Garagem.txt";

   cout << "Nome do ficheiro: " << endl;
   cin >> str;

   ler.open(str.c_str());
   if(ler){
    passenger1.SaveFile(ler);
    ler.close();
    cout << "Ficheiro " << str << "Criado!" << endl;
   } else {
    cout << "Erro" << endl;
   }


   Carro c[3];

   int size = 0;
   int i=0;
   ifstream ifile;
   ifile.open("Garagem.txt");
   if (ifile){
    while(ifile.peek() != EOF){
        c[size].ReadFile(ifile);
        ifile.get();
        size++;
        cout << "While";
    }

    ifile.close();
   } else {
    cout << "Erro";
   }


   for (i=0; i<size; i++){
    if (c[i].getAno() < 2000){
        c[i].Show();
        cout << "O carro e antigo!" << endl;    
    } else if (c[i].getMarca() == "Ferrari"){    
        cout << "E maquina" << endl;
    } else {
        cout << "Erro" << endl;
    }
   }


    system("pause");
    return 0;
}