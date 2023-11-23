#include <iostream>
#include <fstream>

using namespace std;

class Universidade{
    private:
        string Nome, Local;
        int Ano_Inauguracao;
    public:
        Universidade(){

        }

        ~Universidade(){

        };

        Universidade(string nome, string local, int ano){
            Nome = nome;
            Local = local;
            Ano_Inauguracao = ano;
        }

        inline void setNome(string nome){
            Nome = nome;
        }

        inline string getNome(){
            return Nome;
        }

        inline void setLocal(string local){
            Local = local;
        }

        inline string getLocal(){
            return Local;
        }

        inline void setAno(int ano){
            Ano_Inauguracao = ano;
        }

        inline int getAno(){
            return Ano_Inauguracao;
        }

        void Show(){
            cout << "Nome: " << getNome() << "/" << "Local: " << getLocal() << "Ano de Inauguração: " << getAno() << endl;
        }

        void Update(){
            char aux[100];
            int temp;

            cout << "Insira um novo nome: " << endl;
            cin >> aux;
            setNome(aux);
            cout << "Insira um novo local: " << endl;
            cin >> aux;
            setLocal(aux);
            cout << "Insira um novo ano de inauguração: " << endl;
            cin >> temp;
            setAno(temp);
        }

        void Igual(Universidade u1){
            if(u1.Nome == getNome() && u1.Local == getLocal() && u1.Ano_Inauguracao == getAno()){
                cout << "Sao as mesmas universidades" << endl;
            } else {
                cout << "Sao universidades diferentes" << endl;
            }
        }

        friend bool operator==(Universidade &u1, Universidade &u2){
            if (u1.Nome == u2.Nome && u1.Local == u2.Local && u1.Ano_Inauguracao == u2.Ano_Inauguracao){
                cout << "São iguais" << endl;
                return true;
            } else {
                return false;
            }
        }

        friend bool operator!=(Universidade &u1, Universidade &u2){
            if (u1.Nome == u2.Nome && u1.Local == u2.Local && u1.Ano_Inauguracao == u2.Ano_Inauguracao){
                cout << "São iguais" << endl;
                return false;
            } else {
                return true;
            }
        }

        friend ostream& operator<<(ostream& out, Universidade &u1){
            out << "Nome: " << u1.Nome << endl;
            out << "Local: " << u1.Local << endl;
            out << "Ano de Inauguração: " << u1.Ano_Inauguracao << endl;

            return out;
        }

        friend istream& operator>> (istream& in, Universidade &u1){
            
            cout << "Insira um nome: " << endl;
            in >> u1.Nome;

            cout << "Insira um Local: " << endl;
            in >> u1.Local;

            cout << "Insira um ano de inauguração: " << endl;
            in >> u1.Ano_Inauguracao;

            return in;
        }

        void SaveFile(ofstream& out){
            out << "Nome: " << getNome() << "/" << "Local: " << getLocal() << "Ano de Inauguração: " << getAno() << endl;
        }

        void ReadFile(ifstream& in){
            string line;

            while(getline(in,line,',')){
                cout << line << endl;
            }
        }
        
};


class Curso: public Universidade {
    private:
        string Name;
        int Vagas;
        Universidade U;
    public:
        Curso(){

        }

        ~Curso(){

        };

        Curso(string name, int vagas, Universidade u){
            Name = name;
            Vagas = vagas;
            U = u;
        }

        inline void setName(string name){
            Name = name;
        }

        inline string getName(){
            return Name;
        }

        inline void setVagas(int vagas){
            Vagas = vagas;
        }

        inline int getVagas(){
            return Vagas;
        }

        inline void setUniversidade(Universidade u){
            U = u;
        }

        inline Universidade getUniversidade(){
            return U;
        }

        void Show(){
            U.Show();

            cout << "Nome do curso: " << getName() << "/" << "Numero de vagas: " << getVagas() << endl; 
        }

        void Update(){
            U.Update();
            char aux[100];
            int temp;

            cout << "Insira um novo curso: " << endl;
            cin >> aux;
            setName(aux);
            cout << "Insira as vagas do curso" << endl;
            cin >> temp;
            setVagas(temp);

        }

        friend bool operator==(Curso &c1, Curso &c2){
            if(c1.Name == c2.Name && c1.Vagas == c2.Vagas && c1.U == c2.U){
                cout << "São iguais" << endl;
                return true;
            } else {
                return false;
            }
        }

        friend bool operator!=(Curso &c1, Curso &c2){
            if(c1.Name == c2.Name && c1.Vagas == c2.Vagas && c1.U == c2.U){
                cout << "São iguais" << endl;
                return false;
            } else {
                return true;
            }
        }

        friend ostream& operator<< (ostream& out, Curso c1){
            out << "Nome do curso: " << c1.Name << endl;
            out << "Vagas: " << c1.Vagas << endl;
            out << "Universidade: " << c1.U << endl;

            return out;
        }

        friend istream& operator>> (istream& in, Curso c1){
            cout << "Insira o nome do curso: " << endl;
            in >> c1.Name;

            cout << "Insira as vagas: " << endl;
            in >> c1.Vagas;

            cout << "Insira a universidade: " << endl;
            in >> c1.U;

            return in;
        }

        void SaveFile(ofstream& out){
            U.SaveFile(out);
            out << "Nome do curso: " << getName() << "/" << "Numero de vagas: " << getVagas() << "/" << endl;

        }

        void ReadFile(ifstream& in){
            U.ReadFile(in);

            string line;

            while(getline(in,line,',')){
                cout << line << endl;
            }

        }

        virtual int AnoNascimento();

};

class Professor: public Curso{
    private:
        string _Name;
        int Idade;
        Curso C;
    public:
        Professor(){

        }

        ~Professor(){

        };

        Professor(string _name, int idade, Curso c){
            _Name = _name;
            Idade = idade;
            C = c;
        }

        inline void set_Name(string _name){
            _Name = _name;
        }

        inline string get_Name(){
            return _Name;
        }

        inline void setIdade(int idade){
            Idade = idade;
        }

        inline int getIdade(){
            return Idade;
        }

        inline void setCurso(Curso c){
            C = c;
        }

        inline Curso getCurso(){
            return C;
        }

        void Show(){
            C.Show();

            cout << "Professor: " << get_Name() << endl;
            cout << "Idade: " << getIdade() << endl;
        }

        void Update(){
            C.Update();

            char aux[100];
            int temp;

            cout << "Insere o nome do professor: " << endl;
            cin >> aux;
            set_Name(aux);

            cout << "Insere a sua idade: " << endl;
            cin >> temp;
            setIdade(temp);

        }

        friend bool operator==(Professor& p1, Professor& p2){
            if (p1._Name == p2._Name && p1.Idade == p2.Idade && p1.C == p2.C){
                cout << "São iguais" << endl;
                return true;
            } else {
                return false;
            }
        }

        friend bool operator!=(Professor& p1, Professor& p2){
            if (p1._Name == p2._Name && p1.Idade == p2.Idade && p1.C == p2.C){
                cout << "São iguais" << endl;
                return false;
            } else {
                return true;
            }
        }

        friend ostream& operator<< (ostream& out, Professor p1){
            out << "Nome do Professor: " << p1._Name << endl;
            out << "Idade: " << p1.Idade << endl;
            out << "Curso: " << p1.C << endl;

            return out;
        }

        friend istream& operator>> (istream& in, Professor p1){
            cout << "Insira o nome do professor: " << endl;
            in >> p1._Name;

            cout << "Insira a idade: " << endl;
            in >> p1.Idade;

            cout << "Insira o curso" << endl;
            in >> p1.C;

            return in;
        }

        void SaveFile(ofstream& out){
            C.SaveFile(out);
            out << "Professor: " << get_Name() << endl;
            out << "Idade: " << getIdade() << endl;
            out << "Curso: " << getCurso() << endl;
        }

        void ReadFile(ifstream& in){
            C.ReadFile(in);

            string line;

            while(getline(in,line,'s')){
                cout << line << endl;
            }
        }

        int AnoNascimento(){
            int num;
            cout << "Insira o ano em que nasceu: " << endl;
            cin >> num;
            cout << num;
            return num;
        }

};

class Aluno: public Curso{
    private:
        string _Nome;
        int AnoEntrada, idade;
        Curso C;
    public:
        Aluno(){

        }

        ~Aluno(){

        };

        Aluno(string _nome, int anoentrada, int _idade, Curso c){
            _Nome = _nome;
            AnoEntrada = anoentrada;
            idade = _idade;
            C = c;
        }

        inline void set_Nome(string _nome){
            _Nome = _nome;
        }

        inline string get_Nome(){
            return _Nome;
        }

        inline void set_Idade(int _idade){
            idade = _idade;
        }

        inline int get_Idade(){
            return idade;
        }

        inline void setAnoEntrada(int anoentrada){
            AnoEntrada = anoentrada;
        }

        inline int getAnoEntrada(){
            return AnoEntrada;
        }

        inline void set_Curso(Curso c){
            C = c;
        }

        inline Curso get_Curso(){
            return C;
        }

        void Show(){
            C.Show();

            cout << "Nome do aluno: " << get_Nome() << endl;
            cout << "Idade: " << get_Idade() << endl;
            cout << "Ano em que entrou " << getAnoEntrada() << endl;
            cout << "Curso: " << get_Curso() << endl;           
        }

        void Update(){
            C.Update();

            char aux[100];
            int temp;
            cout << "Insira o nome do aluno: " << endl;
            cin >> aux;
            set_Nome(aux);
            cout << "Insira a idade do aluno: " << endl;
            cin >> temp;
            set_Idade(temp);
            cout << "Insira o ano de entrada do aluno: " << endl;
            cin >> temp;
            setAnoEntrada(temp);            
            
        }

        friend ostream& operator<< (ostream& out, Aluno a){
            out << "Nome do aluno: " << a._Nome << endl;
            out << "Idade: " << a.idade << endl;
            out << "Ano de entrada: " << a.AnoEntrada << endl;

            return out;
        }

        friend istream& operator>> (istream& in, Aluno a){

            cout << "Insira o nome do aluno: " << endl;
            in >> a._Nome;
            cout << "Insira a idade do aluno: " << endl;
            in >> a.idade;
            cout << "Insira o ano de entrada: " << endl;
            in >> a.AnoEntrada;
            cout << "Insira o curso do aluno: " << endl;
            in >> a.C;

            return in;
        }

        void SaveFile(ofstream& out){
            C.SaveFile(out);

            out << "Nome do aluno: "<< get_Nome() << endl;
            out << "Idade: " << get_Idade() << endl;
            out << "Ano de entrada: " << getAnoEntrada() << endl;
            out << "Curso: " << get_Curso() << endl;
        }

        void ReadFile(ifstream& in){
            C.ReadFile(in);

            string line;

            while(getline(in,line,',')){
                cout << line << endl;
            }
        }

        int AnoNascimento(){
            int num;
            cout << "Insira o ano em que nasceu: " << endl;
            cin >> num;
            cout << num;
            return num; 
        }


};


