#include <iostream>
#include "oop.h"

using namespace std;

int main(int argc, char *argv){

    Employee emplyoee1 = Employee("Henrique", "Barcelona", 20, 13);
    cout << emplyoee1.getNota() << endl;
    emplyoee1.NotaFinal();
    cout << emplyoee1.getAge() << endl;
    emplyoee1.Promotion();

    Developer d = Developer("Henrique", "Barcelona", 20, 13, "Python");
    d.FixBug();
    d.Promotion();

    emplyoee1.jogo();
    d.jogo();

    Employee* e1 = &d;
    e1->jogo();


    system("pause");
    return 0;
}