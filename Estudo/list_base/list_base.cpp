#include <iostream>
#include <list>
#include "list_base.h"

using namespace std;

int main(int argc, char* argv[]){
    Gestor lista;

    lista.InserirNumero(1);
    lista.InserirNumero(4);
    lista.Listar();

    system("pause");
    return 0;
}