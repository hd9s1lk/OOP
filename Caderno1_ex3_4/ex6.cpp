#include <iostream>
#include <fstream>
#include "ex.h"
#include <vector>
#include <list>


using namespace std;

int main(int argc, char* argv[]){

    vector<Funcionario*> Lista;

    int op;

    while(true){
        cout << "Bem Vindo ao Menu Inicial" << endl;
        cout << "\t 1- Ler Ficheiro" << endl;
        cout << "\t 2- Calcular Ordenado" << endl;
        cout << "\t 3- Pesquisar Funcionario pelo Numero" << endl;
        cout << "\t 4- Alterar Ordenado de um funcionario" << endl;
        cout << "\t 5- Criar novo Funcionario" << endl;
        cout << "\t 6- Apresentar Funcionarios que trabalham por turnos" << endl;
        cout << "\t 7- Eliminar um funcionario" << endl;
        cout << "\t 8- Guardar um Administrador" << endl;
        cout << "Escolha uma Opção:" << endl;

        cin >> op;


        if(op==0){
            exit(1);
        }
        if(op==1){
            LerFicheiro(Lista);
        }
        if(op==2){
            CalculaOrdenadosVetor(Lista);
        }
        if(op==3){
            PesquisaFuncionario(Lista);
        }
        if(op==4){
            ChangeOrd(Lista);
        }
        if(op==5){
            CriarFuncionario(Lista);
        }
        if(op==6){
            ApresentaTurnos(Lista);
        }
        if(op==7){
            EliminarFuncionario(Lista);
        }
        if(op==8){
            GuardarAdm(Lista);
        }

    }
    system("pause");
    return 0;
}

void LerFicheiro(vector<Funcionario*> &Lista){
    ifstream ifile;
    ifile.open("Funcionarios.txt");

    if(!ifile.is_open()){
        exit(-1);
    }

    do {
        string str;
        getline(ifile, str, ':');

        if (str == "O"){
            Operario *op = new Operario();
            op->ReadFile(ifile);
            Lista.push_back(op);
        } else if (str == "A"){
            Administrativo *adm = new Administrativo();
            adm->ReadFile(ifile);
            Lista.push_back(adm);
        }
    }
    while(ifile.peek() != EOF);

    cout << "Foram lidos " << Lista.size() << "funcionarios para a lista" << endl;

    ifile.close();
}

void CalculaOrdenadosVetor(vector<Funcionario*> &Lista){
            cout << "Lista de Funcionarios: " << endl;

            for (int i=0; i<Lista.size(); i++){
                cout << Lista[i]->getNum_func() << "\t";
                cout << Lista[i]->getNome() << "\t";
                cout << Lista[i]->Calcula_Ordenado() << "\t";
            }
            cout << endl << endl;
        }

void PesquisaFuncionario(vector<Funcionario*> &Lista){
            cout << "Pesquisa pelo Funcionario " << endl;

            int num;
            cout << "Insira o numero do Funcionario: " << endl;
            cin >> num;

            for (int i=0; i<Lista.size(); i++){
                if(Lista[i]->getNum_func() == num){
                    Lista[i]->Show();
                    return;
                } else {
                    cout << "O funcionario nao foi encontrado" << endl;
                }
            } 
                
        }

void ChangeOrd(vector<Funcionario*> &Lista){
            int num;
            cout << "Insira o numero de Funcionario:" << endl;
            cin >> num;

            for (int i=0; i<Lista.size(); i++){
                if(Lista[i]->getNum_func() == num){
                    Lista[i]->getOrdBase();
                    int salario;
                    cout << "Insira o novo salario para este funcionario: " << endl;
                    cin >> salario;
                    Lista[i]->setOrdBase(salario);
                    return;
                } else {
                    cout << "O funcionario nao foi encontrado" << endl;
                }
            } 
                
        }

void CriarFuncionario(vector<Funcionario*> &Lista){
            cout << "Criar um Funcionario " << endl;

            string str;
            cin.clear();
            fflush(stdin);

            cout << "Deseja Inserir: Administrador(A) ou Operario(O)?" << endl;
            getline(cin,str,'/');

            if(str == "O" || str == "o"){
                Operario *op = new Operario();
                op->ReadAll();
                Lista.push_back(op);
            } else if(str == "A" || str == "a"){
                Administrativo *adm = new Administrativo;
                adm->ReadAll();
                Lista.push_back(adm);
            }

            cout << endl;

            cin.clear();
            fflush(stdin);
        }

void ApresentaTurnos(vector<Funcionario*> &Lista){
            cout << "Lista dos Operarios que trabalham em turnos: " << endl;

            for (int i=0; i<Lista.size(); i++){
                if(Operario *op = dynamic_cast<Operario*>(Lista[i])){
                    if(op->getF_turno()){
                        cout << op->getNum_func() << "/" << op->getNome() << endl;
                    }
                }
            }
            cout << endl;
        }

void EliminarFuncionario(vector<Funcionario*> &Lista){
            int num;
            cout << "Insira o numero de Funcionario:" << endl;
            cin >> num;

            for (int i=0; i<Lista.size(); i++){
                if(Lista[i]->getNum_func() == num){
                    Lista.erase(Lista.begin() + i);
                    
                    cout << "O funcionario " << num << "foi eliminado" << endl;
                } else {
                    cout << "O funcionario nao foi encontrado" << endl;
                }
            } 
                
        }

void GuardarAdm(vector<Funcionario*> &Lista){

            ofstream file;
            file.open("Administrativos.txt");

            if (!file.is_open()){
                exit(-1);
            }

            for(int i =0; i<Lista.size(); i++){
                if(Administrativo *adm = dynamic_cast<Administrativo*>(Lista[i])){
                    adm->SaveFile(file);
                    file << endl;
                }
            }

            cout << "Ficheiro guardado com sucesso" << endl;
            file.close();
        }

void GuardarO(vector<Funcionario*> &Lista){

            ofstream file;
            file.open("Operarios.txt");

            if (!file.is_open()){
                exit(-1);
            }

            for(int i =0; i<Lista.size(); i++){
                if(Operario *op = dynamic_cast<Operario*>(Lista[i])){
                    op->SaveFile(file);
                    file << endl;
                }
            }

            cout << "Ficheiro guardado com sucesso" << endl;
            file.close();
        }

