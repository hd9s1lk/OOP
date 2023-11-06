#include <iostream>
#include "ex.h"

using namespace std;

int main(int argc, char* argv[]){

    Data data1(1,3,2003);
    Data data2(2,5,2003);

    data1.Show();


    data2.Igual(data1);


    //Abrir e ler ficheiro

    ofstream of;
    ifstream rf;

    of.open("data.txt");
    if(!of){
        cout << "Erro" << endl;
        exit(1);
    }

    data1.SaveFile(of);
    of.close();

    rf.open("data.txt");
    if(!rf){
        cout << "Erro" << endl;
        exit(1);
    }

    data1.ReadFile(rf);
    rf.close();


    system("pause");
    return 0;


}