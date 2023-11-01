#include <iostream>

using namespace std;

class AbstractEmployee {
    virtual void Promotion() = 0;
};

class Employee:AbstractEmployee {
    private: 
            string Name;
            string Company;
            int Age;
            float Nota;
    public:

        void setName(string name){    //set do nome
            Name = name;
        }
        string getName(){           //get do nome
            return Name;
        }

        void setCompany(string company){    //set da empresa
            Company = company;
        }
        string getCompany(){            //get da empresa
            return Company;
        }

        void setAge(int age){    //set da idade
            Age = age;
        }
        int getAge(){           //get da idade
            return Age;
        }

        float setNota(float nota){    //set da nota
            Nota = nota;
        }

        float getNota(){                //get da nota
            return Nota;
        }

        void NotaFinal() {
            if (Nota>= 9.5 && Nota <= 20) {
                cout << "Aprovado - Parabens!"  << endl;
            } else {
                cout << "Reprovado - vais a epoca especial" << endl;
            }
        }


        void Introduce() {
            cout << "Nome: " << Name << endl;
            cout << "Empresa: " << Company << endl;
            cout << "Idade: " << Age << endl;
        }
        Employee(string name, string company, int age, float nota) {  //constructor
            Name = name;
            Company = company;
            Age = age;
            Nota = nota;

        }

        void Promotion() {
            if(Age > 30) {
                cout << Name << " estas promovido. Parabens" << endl;
            } else {
                cout << Name << " Continua a trabalhar nos ganhos" << endl;
            }
        }

        void jogo() {
            cout << Name << " esta a jogar poker no trabalho ://" << endl;
        }
            
};

class Developer: public Employee {  //public para aceder às funções de Employee, não às variáveis
    public:
        string FavProgLanguage;
        Developer(string name, string company, int age, float nota, string favproglanguage)
            :Employee(name, company, age, nota) {
                FavProgLanguage = favproglanguage;
        }

        void FixBug() {
            cout << getName() << " arranjou o bug a usar " << FavProgLanguage << endl;
        }

        virtual void jogo() {
            cout << getName() << " esta a trabalhar pesado yeah buddyyyy ://" << endl;  //polimorfismo a mesma função mas numa classe diferente com um resultado diferente
        }

};  //para criares diferentes ramos, simplesmente copiar este modelo, criar um professor, futebolista, jogador, whatever

