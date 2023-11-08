#include <iostream>
#include <fstream>


using namespace std;

class Empresa {
    private:
        string Nome;
        string Local;
        int Empregados;

    public:
        Empresa(){

        }

        Empresa(string nome, string local, int empregados){
            Nome = nome;
            Local = local;
            Empregados = empregados;
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

        inline void setEmpregados(int empregados){
            Empregados = empregados;
        }

        inline int getEmpregados(){
            return Empregados;
        }

        void Show(){
            cout << "Nome da Empresa: " << getNome() << endl;
            cout << "Localidade: " << getLocal() << endl;
            cout << "Numero de Empregados: " << getEmpregados() << endl;

        }

        void Update(){
            int temp;
            string temp2;

            cout << "Insira um novo nome: " << endl;
            cin >> temp2;
            setNome(temp2);

            cout << "Insira um novo local: " << endl;
            cin >> temp2;
            setNome(temp2);

            cout << "Insira o numero de empregados: " << endl;
            cin >> temp;
            setEmpregados(temp);

        }

        void Igual(Empresa e1){
            if (e1.Nome == getNome() && e1.Local == getLocal() && e1.Empregados == getEmpregados()){
                cout << "Estas empresas são iguais" << endl;
            } else {
                cout << "Estas empresas sao diferentes" << endl;
            }
        }

        friend bool operator== (Empresa e1, Empresa e2){
            if(e1.Nome == e2.Nome && e1.Local == e2.Local && e1.Empregados == e2.Empregados){
                cout << "As empresas são iguais" << endl;
                return true;
            } else {
                cout << "As empresas são diferentes" << endl;
                return false;
            }
        }

        friend bool operator!= (Empresa e1, Empresa e2){
            if(e1.Nome == e2.Nome && e1.Local == e2.Local && e1.Empregados == e2.Empregados){
                cout << "As empresas sao iguais" << endl;
                return false;
            } else {
                cout << "As empresas sao diferentes" << endl;
                return true;
            }
        }

        friend ostream& operator<< (ostream& out, Empresa& e1){
            cout << "Nome: " << e1.Nome << endl;
            cout << "Local: " << e1.Local << endl;
            cout << "Numero Empregados: " << e1.Empregados << endl;

            return out;
        }

        friend istream& operator>> (istream& in, Empresa& e1){

            cout << "Insira um novo Nome: " << endl;
            in >> e1.Nome;

            cout << "Insira um novo local: " << endl;
            in >> e1.Local;

            cout << "Insira o numero de empregados: " << endl;
            in >> e1.Empregados;

            return in;

        }

        void SaveFile(ofstream& out){
            out << getNome() << "/" << getLocal() << "/" << getEmpregados() << endl;
        }

        void ReadFile(ifstream& in){
            string line;

            while(getline(in,line)){
                cout << line << endl;
            }

        }


};

class Funcionario: public Empresa {
    private: 
        string Name;
        int Idade, AnoEXP;
        Empresa empresa;
    public:
        Funcionario(){

        }

        Funcionario(string name, int idade, int anoexp, Empresa _empresa){
            Name = name;
            Idade = idade;
            AnoEXP = anoexp;
            empresa = _empresa;
        }

        inline void setName(string name){
            Name = name;
        }

        inline string getName(){
            return Name;
        }

        inline void setIdade(int idade){
            Idade = idade;
        }

        inline int getIdade(){
            return Idade;
        }

        inline void setAnoEXP(int anoexp){
            AnoEXP = anoexp;
        }

        inline int getAnoEXP(){
            return AnoEXP;
        }

        inline void setEmpresa(Empresa _empresa){
            empresa = _empresa;
        }

        inline Empresa getEmpresa(){
            return empresa;
        }

        void Show(){
            cout << "Nome do Funcionario: " << getName() << endl;
            cout << "Idade: " << getIdade() << endl;
            cout << "Ano(s) de Experiência: " << getAnoEXP() << endl;
            empresa.Show();
        }

        void Update(){
            string temp;
            int temp2;

            cout << "Insira um novo Nome: " << endl;
            cin >> temp;
            setName(temp);

            cout << "Insira uma idade: " << endl;
            cin >> temp2;
            setIdade(temp2);

            cout << "Insira os anos de experiência: " << endl;
            cin >> temp2;
            setAnoEXP(temp2);

            empresa.Update();
        }

        void Diferente(Funcionario f1){
            if(f1.Name != this->Name && f1.Idade != this->Idade && f1.AnoEXP != this->AnoEXP && f1.empresa != this->empresa){
                cout << "Funcionarios diferentes" << endl;
            } else {
                cout << "Funcionarios iguais" << endl;
            }
        }

        friend bool operator==(Funcionario f1, Funcionario f2){
            if (f1.Name == f2.Name && f1.Idade == f2.Idade && f1.AnoEXP == f2.AnoEXP && f1.empresa == f2.empresa){
                cout << "Estes funcionarios sao iguais" << endl;
                return true;
            } else {
                return false;
            }
        }

        friend bool operator!=(Funcionario f1, Funcionario f2){
            if (f1.Name == f2.Name && f1.Idade == f2.Idade && f1.AnoEXP == f2.AnoEXP && f1.empresa == f2.empresa){
                cout << "Estes funcionarios sao iguais" << endl;
                return false;
            } else {
                return true;
            }
        }

        friend ostream& operator << (ostream& out, Funcionario f1){
            out << "Nome: " << f1.Name << endl;
            out << "Idade: " << f1.Idade << endl;
            out << "Anos de Experiencia: " << f1.AnoEXP << endl;
            out << "Empresa: " << f1.empresa << endl;

            return out;

        }

        friend istream& operator>> (istream& in, Funcionario f1){
            
            cout << "Insira um nome: " << endl;
            in >> f1.Name;

            cout << "Insira uma idade: " << endl;
            in >> f1.Idade;

            cout << "Insira os anos de experiencia: " << endl;
            in >> f1.AnoEXP;

            cout << "Insira a empresa que trabalha: " << endl;
            in >> f1.empresa;

            return in;
        }

        void SaveFile(ofstream& out){
            out << "Nome: " << getName() << "/" << "Idade: " << getIdade() << "/" << "Anos de Experiencia: " << getAnoEXP() << endl;
            out << "Empresa: " << empresa << endl;

        }

        void ReadFile(ifstream& in){
            string line;

            getline(in,line,',');
            cout << line << endl;
        }


};