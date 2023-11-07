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

        void SaveFile(ofstream& sf){
            sf << "Nome: " << getNome() << "/" << getIdade() << "/" << getUC() << endl;
        }

        void ReadFile(ifstream& rf){
            string line;

            while(getline(rf,line)){
                cout << line << endl;
            }
        }


};

class Turma: public Professor {
    private:
        int NAlunos;
        string LetraTurma;
        Professor professor;

    public:
        Turma() {

        }

        Turma(int nalunos, string letraturma, Professor _professor){
            NAlunos = nalunos;
            LetraTurma = letraturma;
            professor = _professor;
        }

        inline void setNAlunos(int nalunos){
            NAlunos = nalunos;
        }

        inline int getNAlunos(){
            return NAlunos;
        }

        inline void setLetraTurma(string letraturma){
            LetraTurma = letraturma;
        }

        inline string getLetraTurma(){
            return LetraTurma;
        }

        inline void setProfessor(Professor _professor){
            professor = _professor;
        }

        inline Professor getProfessor(){
            return professor;
        }

        void Show(){
            professor.Show();
            cout << "Numero de Alunos: " << getNAlunos() <<endl;
            cout << "Turma: " << getLetraTurma() << endl;
        }

        void Update(){
            int temp;
            string temp2;

            cout << "Insira um novo numero de alunos: " << endl;
            cin >> temp;
            setNAlunos(temp);

            cout << "Insira a letra da turma: " << endl;
            cin >> temp2;
            setLetraTurma(temp2);

        }

        void MaisAlunos(Turma t1){
            if (t1.NAlunos > getNAlunos()){
                cout << "A primeira turma tem mais alunos" << endl;
            } else {
                cout << "A segunda turma tem mais alunos" << endl;
            }
        }

        friend bool operator== (Turma t1, Turma t2){
            if (t1.NAlunos == t2.NAlunos && t1.LetraTurma == t2.LetraTurma){
                cout << "As turmas são as mesmas" << endl;
                return true;
            } else {
                return false;
            }
        }

        friend bool operator!= (Turma t1, Turma t2){
            if (t1.NAlunos == t2.NAlunos && t1.LetraTurma == t2.LetraTurma){
                cout << "As turmas são as mesmas" << endl;
                return false;
            } else {
                return true;
            }
        }

        friend ostream& operator<< (ostream& sf, Turma& t1){
            sf << "Numero de alunos: " << t1.NAlunos << endl;
            sf << "Letra da Turma: " << t1.LetraTurma << endl;

            return sf;
        }

        friend istream& operator>> (istream& rf, Turma& t1){
            int temp;
            char aux[100];

            cout << "Insira o numero de alunos: " << endl;
            cin >> temp;
            t1.NAlunos = temp;
            cout << "Insira a letra da turma: " << endl;
            rf.getline(aux, sizeof aux);
            t1.LetraTurma = aux;

            return rf; 
        }

        void SaveFile(ofstream& sf){
            sf << "Numero de alunos: " << getNAlunos() << endl;
            sf << "Letra da Turma: " << getLetraTurma() << endl;

        }

        void ReadFile(ifstream& rf){
            string line;
               
            getline(rf, line, ',');
            NAlunos = stoi(line);

            getline(rf, line, ',');
            NAlunos = stoi(line);
        }


};



        