#include <list>
#include <iostream>
#include "ex.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]){

    int op;
    vector<Funcionario*> Lista;

    Gestor_Func gestor;
    gestor.ReadFile();

    Operario *op = new Operario(25050, "Pintura", "Zeca", "Rua A n9", Data(1,1,1985), 1100, 15, false);
    gestor.AdicionarFuncionario(op);

    Administrativo *adm = new Administrativo(25051, "RecHumanos", "Adrusila Lopes", "Rua E n6", Data(6,6, 1996), 900, 0);
    gestor.AdicionarFuncionario(adm);

    gestor.ShowFunc();

    gestor.RemoverFuncionario(10000);

    gestor.SaveFile();
    
    system("pause");
    return 0;
}