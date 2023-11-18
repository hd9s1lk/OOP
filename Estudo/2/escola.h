#include <iostream>
#include <fstream>

using namespace std;

class Professor {
    private:
        string Nome;
        string UC;
        int Idade;
    public:
        Professor() {

        }

        Professor(string nome, int idade, string uc){
            Nome = nome;
            Idade = idade;
            UC = uc;
            
        }

        inline void setNome(string nome){
            Nome = nome;
        }

        inline string getNome(){
            return Nome;
        }

        inline void setIdade(int idade){
            Idade = idade;
        }

        inline int getIdade(){
            return Idade;
        }

        inline void setUC(string uc){
            UC = uc;
        }

        inline string getUC(){
            return UC;
        }

        void Show(){
            cout << "Professor(a): " << getNome() << "/" << getIdade() << "/" << getUC() << endl; 
        }

        void Update(){
            int temp;
            string temp2;

            cout << "Insira um novo Nome: " << endl;
            cin >> temp2;
            setNome(temp2);

            cout << "Insira uma nova Idade: " << endl;
            cin >> temp;
            setIdade(temp);

            cout << "Insira a UC: " << endl;
            cin >> temp2;
            setUC(temp2);

        }

        void MaisVelho(Professor p1){
            if (p1.Idade > getIdade()){
                cout << "O primeiro professor e mais velho" << endl;
            } else {
                cout << "O segundo professor e mais velho" << endl;
            }
        }

        friend bool operator== (Professor p1, Professor p2){
            if (p1.Nome == p2.Nome && p1.Idade == p2.Idade && p1.UC == p2.UC){
                return true;
            } else {
                return false;
            }
        }

        friend bool operator!= (Professor p1, Professor p2){
            if (p1.Nome == p2.Nome && p1.Idade == p2.Idade && p1.UC == p2.UC){
                return false;
            } else {
                return true;
            }
        }

        friend ostream& operator<< (ostream& sf, Professor& p1){
            sf << "Nome: " << p1.Nome << endl;
            sf << "Idade: " << p1.Idade << endl;
            sf << "UC: " << p1.UC << endl;

            return sf;
        }

        friend istream& operator>> (istream& rf, Professor& p1){
            cout << "Insira o Nome: " << endl;
            rf >> p1.Nome;

            cout << "Insira a idade: " << endl;
            rf >> p1.Idade;

            cout << "Insira a UC: " << endl;
            rf >> p1.UC;

            return rf;
        }

        void SaveFIle(ofstream& sf){
            sf << "Nome: " << getNome() << "/" << getIdade() << "/" << getUC() << endl;
        }

        void ReadFile(ifstream& rf){
            string line;

            while(getline(rf,line)){
                cout << line << endl;
            }
        }


};
        