#include <iostream>
#include <list>
#include "GestorN.h"

using namespace std;

int main(int argc, char* argv[]){
    GestorN gestorNumeros;

    gestorNumeros.InserirNumero(3);
    gestorNumeros.InserirNumero(7);
    gestorNumeros.InserirNumero(8);
    gestorNumeros.InserirNumero(12);

    gestorNumeros.Listar();

    int numProcura = 8;

    cout << "O numero " << numProcura << " esta na posicao " << gestorNumeros.ObterPos(numProcura);

    cout << "Fim do programa" << endl;

    system("pause");
    return 0;
}