#include <iostream>
#include <fstream>
#include <vector>
#include "equipa.h"

using namespace std;

int main(int argc, char* argv[]){


    vector<Funcionario*> Lista;

    bool running = true;
    int op;
    
    while(running){
        cout << "Bem Vindo ao Menu Principal" << endl;
        cout << "\t 1- Ler ficheiro" << endl;
        cout << "\t 2- Calcular Ordenados" << endl;
        cout << "\t 3- Pesquisar por Funcionario" << endl;
        cout << "\t 4- Guardar um Software Engineer" << endl;
        cout << "\t 5- Guardar um Chefe" << endl;
         cout << "\t 6- Criar um Chefe/Engenheiro" << endl;
        cout << "\t 7- Sair" << endl;


        switch(op){
            case 0:
                exit(0);
            case 1:
                LerFicheiro(Lista);
                break;
            case 2:
                CalcularOrdenados(Lista);
                break;
            case 3:
                PesquisarFuncionario(Lista);
                break;
            case 4:
                GuardarSoftwareEnginner(Lista);
                break;
            case 5:
                GuardarChefe(Lista);
                break;
            case 6:
                CriarFuncionario(Lista);
                break;
        }
        
    }

    system("pause");
    return 0;
}


void LerFicheiro(vector<Funcionario*> &Lista){
    ifstream ifile;
    ifile.open("Equipa3.txt");

    if(!ifile.is_open()){
        exit(-1);
    }
    
    do{
        string str;
        getline(ifile,str,',');

        if(str == "C" || str == "c"){
            Chefe* ch = new Chefe();
            ch->ReadFile(ifile);
            Lista.push_back(ch);
        } else if (str == "S" || str == "S") {
            SoftwareEnginner *soft = new SoftwareEnginner();
            soft->ReadFile(ifile);
            Lista.push_back(soft);
        }
    }
    while(ifile.peek() != EOF);

    cout << "Ficheiro lido com sucesso" << endl;

    ifile.close();
}

void CalcularOrdenados(vector<Funcionario*> Lista){

    for(int i=0; i<Lista.size(); i++){
        cout << Lista[i]->getName() << endl;
        cout << Lista[i]->Calcula_Ordenado() << endl; 
    }

    cout << endl;
}

void PesquisarFuncionario(vector<Funcionario*> Lista){
    string nome;
    cout << "Insira o nome do funcionario que deseja pesquisar: " << endl;
    cin >> nome;

    for(int i=0; i<Lista.size(); i++){
        if(nome == Lista[i]->getName()){
            if(SoftwareEnginner* soft = dynamic_cast<SoftwareEnginner*>(Lista[i])){
                soft->Show();
            }
            if(Chefe* ch = dynamic_cast<Chefe*>(Lista[i])){
                ch->Show();
            }

            return;
        }      
        
    }

    cout << "Nao foi encontrado" << endl;
}


void GuardarSoftwareEnginner(vector<Funcionario*> Lista){
    ofstream ofile;
    ofile.open("EngenheiroSoftware.txt");

    if(!ofile.is_open()){
        exit(-1);
    }

    for(int i=0; i<Lista.size(); i++){
        if(SoftwareEnginner* soft = dynamic_cast<SoftwareEnginner*>(Lista[i])){
            soft->SaveFile(ofile);
            ofile << endl;
        }
    }
 
    cout << "Ficheiro guardado com sucesso" << endl;

    ofile.close();
}

void GuardarChefe(vector<Funcionario*> Lista){
    ofstream ofile;
    ofile.open("Chefes.txt");

    if(!ofile.is_open()){
        exit(-1);
    }

    for(int i=0; i<Lista.size(); i++){
        if (Chefe* ch = dynamic_cast<Chefe*>(Lista[i])){
            ch->SaveFile(ofile);
            ofile << endl;
        }
    }

    cout << "Ficheiro guardado com sucesso" << endl;

    ofile.close();
}

void CriarFuncionario(vector<Funcionario*> Lista){

    string str;
    cin.clear();
    fflush(stdin);

    cout << "Deseja adicionar Chefe(C) ou Engenheiro (S)?" << endl;
    getline(cin,str,',');

    if(str == "C" || str == "c"){
        Chefe* ch = new Chefe();
        ch->ReadAll();
        Lista.push_back(ch);
    } else if (str == "S" || str == "s"){
        SoftwareEnginner * soft = new SoftwareEnginner();
        soft->ReadAll();
        Lista.push_back(soft);
    }

    cout << endl;

    cin.clear();
    fflush(stdin);


}