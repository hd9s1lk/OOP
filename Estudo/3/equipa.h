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
                cout << "As empresas são iguais" << endl;
                return false;
            } else {
                cout << "As empresas são diferentes" << endl;
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