#include <iostream>
#include <fstream>
#include "carro.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]){

    vector<Passageiro*> Lista;

    bool running = true;
    int op;

    while(running){
        cout << "Bem Vindo ao Menu Principal" << endl << endl;

        cout << "\t 1- Ler ficheiro" << endl;
        cout << "\t 1- Ler ficheiro" << endl;
        cout << "\t 1- Ler ficheiro" << endl;
        cout << "\t 1- Ler ficheiro" << endl;
        cout << "\t 1- Ler ficheiro" << endl;
        cout << "\t" <<endl;

    }

    switch(op){
        case 0:
            exit(-1);
            break;
        case 1:
            LerFicheiro(Lista);
            break;
        case 2:
            MostrarCarros(Lista);
            break;
        case 3:
            PesquisaPelaEquipa(Lista);
            break;
        case 4:
            PesquisarCarro(Lista);
            break;
        case 5:
            EliminarEquipa(Lista);
            break;
        case 6:
            GuardarCombustivel(Lista);
            break;
        case 7:
            GuardarPiloto(Lista);
            break;
    }

    system("pause");
    return 0;
}


void LerFicheiro(vector<Passageiro*> &Lista){
    ifstream ifile;
    ifile.open("Garagem2.txt");

    if(!ifile.is_open()){
        exit(-1);
    }
    do {
        string str;
        getline(ifile,str,',');

        if(str == "C" || str == "c"){
            Combustivel *c = new Combustivel();
            c->ReadFile(ifile);
            Lista.push_back(c);
        } else if (str == "P" || str == "p") {
            Piloto *p = new Piloto();
            p->ReadFile(ifile);
            Lista.push_back(p);
        }
    }
    while (ifile.peek() != EOF);

    cout << "Foram lidos " << Lista.size() << "elementos do ficheiro" << endl;

    ifile.close();
}

void MostrarCarros(vector<Passageiro*> &Lista){
    cout << "Lista de carros: " << endl;

    for(int i=0; i<Lista.size(); i++){
        cout << Lista[i]->getCarro() << endl;
    }

    cout << endl << endl;
}

void PesquisaPelaEquipa(vector<Passageiro*> &Lista){
    string equipa;
    cout << "Insira a Equipa que deseja procurar: " << endl;
    cin >> equipa;

    for(int i=0; i<Lista.size(); i++){
        if(equipa == Lista[i]->getEquipa()){
            Lista[i]->Show();
        } else {
            cout << "A equipa não existe" << endl;
        }
    }

}

void PesquisarCarro(vector<Passageiro*> &Lista){
    string carro;
    cout << "Insira um nome do carro: " << endl;
    cin >> carro;

    for(int i=0; i<Lista.size(); i++){
        if (carro = Lista[i]->getCarro()){
            cout << Lista[i]->getMarca() << "/" << Lista[i]->getHp() << "/" << Lista[i]->getAno() << endl;
        } else {
            cout << "Nao existe esse carro" << endl;
        }
    }
}

void EliminarEquipa(vector<Passageiro*> &Lista){
    string equipa;
    cout << "Insira a equipa que deseja eliminar: " << endl;
    cin >> equipa;

    for(int i=0; i<Lista.size(); i++){
        if (equipa == Lista[i]->getEquipa()){
            Lista.erase(Lista.begin() + i);

            cout << "A equipa " << equipa << "foi eliminada" << endl; 
        } else {
            cout << "A equipa nao foi encontrada" << endl;
        }
    }
}

void GuardarCombustivel(vector<Passageiro*> &Lista){
    ofstream ofile;
    ofile.open("Garagem2.txt");

    if(!ofile.is_open()){
        exit(-1);
    }

    for(int i=0; i<Lista.size(); i++){
        if(Combustivel* cb = dynamic_cast<Combustivel*>(Lista[i])){
            cb->SaveFile(ofile);
            ofile << endl;
        }
    }
    cout << "Ficheiro guardado com sucesso" << endl;
    ofile.close();
}

void GuardarPiloto(vector<Passageiro*> &Lista){
    ofstream ofile;
    ofile.open("Garagem2.txt");

    if(!ofile.is_open()){
        exit(-1);
    }

    for(int i=0; i<Lista.size(); i++){
        if(Piloto *p = dynamic_cast<Piloto*>(Lista[i])){
            p->SaveFile(ofile);
            ofile << endl;
        }
    }
    cout << "Ficheiro guardado com sucesso" << endl;
    ofile.close();
}



