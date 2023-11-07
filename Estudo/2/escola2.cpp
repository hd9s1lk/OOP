#include <iostream>
#include "escola.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){

    Turma turma1(25, "A", Professor("Iracema", 48, "Matemática"));
    Turma turma2(22, "B", Professor("Iracema", 28, "Estudo do Meio"));

    turma2.MaisAlunos(turma1);


    system("pause");
    return 0;
}