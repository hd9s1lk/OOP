#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "uni.h" 

using namespace std;

void LerFicheiro(vector<Curso*> &Lista);
void PesquisarCurso(vector<Curso*> &Lista);
void AlterarCurso(vector<Curso*> &Lista);
void GuardarAluno(vector<Curso*> &Lista);
void GuardarProfessor(vector<Curso*> &Lista);


int main(int argc, char*argv[]){

    vector<Curso*> Lista;

    bool running = true;

    int op;

    while(running){
        cout << "Bem Vindo ao Menu Principal" << endl;
        cout << "\t 1. Ler Ficheiro" << endl;
        cout << "\t 2. Pesquisar Info Curso" << endl;
        cout << "\t 3. Guardar Aluno" << endl;
        cout << "\t 4. Guardar Professor" << endl;
        cout << "\t 5. Alterar Curso" << endl;
        cout << "Escolha uma opção: " << endl;
        cin >> op;


        switch(op){
            case 0:
                exit(0);
            case 1:
                LerFicheiro(Lista);
                break;
            case 2:
                PesquisarCurso(Lista);
                break;
            case 3:
                GuardarAluno(Lista);
                break;
            case 4:
                GuardarProfessor(Lista);
                break;
            case 5:
                AlterarCurso(Lista);
                break;

        }
    }


    system("pause");
    return 0;
}


void LerFicheiro(vector<Curso*> &Lista){
    ifstream ifile;
    ifile.open("Universidade.txt");

    if(!ifile.is_open()){
        exit(-1);
    }

    do{
        string str;
        getline(ifile,str,',');

        if(str == "P" || str == "p"){
            Professor* p = new Professor();
            p->ReadFile(ifile);
            Lista.push_back(p);
        } else if (str == "A" || str == "a"){
            Aluno* a = new Aluno();
            a->ReadFile(ifile);
            Lista.push_back(a);
        }
    } 
    while(ifile.peek() != EOF);

    cout << "O ficheiro foi lido com sucesso" << endl;

    ifile.close();
}

void PesquisarCurso(vector<Curso*> &Lista){
    string nome;
    cout << "Insira o curso que deseja pesquisar: " << endl;
    cin >> nome;

    for(int i=0; i<Lista.size(); i++){
        if(nome == Lista[i]->getName()){
            Lista[i]->Show();
        } else {
            cout << "O curso não foi encontrado" << endl;
        }
    }
}

void AlterarCurso(vector<Curso*> &Lista){
    string nome;
    cout << "Insira o nome do curso: " << endl;
    cin >> nome;

    for(int i=0; i<Lista.size(); i++){
        if(nome == Lista[i]->getName()){
            string Fnome;
            cout << "Insira o nome correto: " << endl;
            cin >> Fnome;
            Lista[i]->setName(Fnome);
            cout << "Curso alterado com sucesso" << endl;
        } else {
            cout << "Curso não encontrado" << endl;
        }
    }
}


void GuardarAluno(vector<Curso*> &Lista){
    ofstream ofile;
    ofile.open("Universidade.txt");

    if(!ofile.is_open()){
        exit(-1);
    }


    for(int i=0; i<Lista.size(); i++){
        if(Aluno* a = dynamic_cast<Aluno*>(Lista[i])){
            a->SaveFile(ofile);
            ofile << endl;
        }
    }

    cout << "Ficheiro guardado com sucesso" << endl;
    ofile.close();
}

void GuardarProfessor(vector<Curso*> &Lista){
    ofstream ofile;
    ofile.open("Universidade.txt");

    if(!ofile.is_open()){
        exit(-1);
    }


    for(int i=0; i<Lista.size(); i++){
        if(Professor* p = dynamic_cast<Professor*>(Lista[i])){
            p->SaveFile(ofile);
            ofile << endl;
        }
    }

    cout << "Ficheiro guardado com sucesso" << endl;
    ofile.close();
}

