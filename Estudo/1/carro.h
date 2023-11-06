#include <iostream>
#include <fstream>

using namespace std;

class Carro {
    private:
        string Marca;
        int Hp;
        int Ano;

    public:
        Carro() {

        } 

        Carro(string marca, int hp, int ano){
            Marca = marca;
            Hp = hp;
            Ano = ano;
        }

        inline void setMarca(string marca){
            Marca = marca;
        }

        inline string getMarca(){
            return Marca;
        }

        inline void setHp(int hp){
            Hp = hp;
        }

        inline int getHp(){
            return Hp;
        }

        inline void setAno(int ano){
            Ano = ano;
        }

        inline int getAno(){
            return Ano;
        }

        void Show(){
            cout << "Carro: " << getMarca() << " / " << getHp() << "hp / " << getAno() << endl; 
        }

        void Update(){
            int temp;
            string temp2;

            cout << "Insira uma nova Marca: " << endl;
            cin >> temp2;
            setMarca(temp2);

            cout << "Insira a cavalagem atmosférica: " << endl;
            cin >> temp;
            setHp(temp);

            cout << "Insira o ano do carro: " << endl; 
            cin >> temp;
            setAno(temp);

        }

        bool Igual(Carro c1){
            if (c1.Marca == getMarca() && c1.Ano == getAno() && c1.Hp == getHp() ){
                cout << "Os carros são iguais" << endl;
                return true;
            } else {
                cout << "Os carros são diferentes" << endl;
                return false;
            }
        }

        friend bool operator==(Carro& c1, Carro& c2){
            if (c1.Marca == c2.Marca && c1.Ano == c2.Ano && c1.Hp == c2.Hp ){
                cout << "Os carros são iguais" << endl;
                return true;
            } else {
                cout << "Os carros são diferentes" << endl;
                return false;
            }
        }

        friend bool operator!=(Carro& c1, Carro& c2){
            if (c1.Marca == c2.Marca && c1.Ano == c2.Ano && c1.Hp == c2.Hp ){
                cout << "Os carros são iguais" << endl;
                return false;
            } else {
                cout << "Os carros são diferentes" << endl;
                return true;
            }
        }

        friend ostream& operator<< (ostream& sf, Carro& c1){
            sf << "Marca: " << c1.Marca << endl;
            sf << "Cavalagem Atmosférica: " << c1.Hp << endl;
            sf << "Ano: " << c1.Ano << endl;

            return sf;
        }

        friend istream& operator>> (istream& rf, Carro& c1){
            cout << "Insira a Marca: " << endl;
            rf >> c1.Marca;

            cout << "Insira a cavalagem atmosférica: " << endl;
            rf >> c1.Hp;

            cout << "Insira o Ano: " << endl;
            rf >> c1.Ano;

            return rf;
        } 

        void SaveFile(ofstream& sf){
            sf << getMarca() << "/" << getHp() << "/" << getAno() << endl;
        }

        void ReadFile(ifstream& rf){
            string line;

            getline(rf,line,';');
            Marca = stoi(line);

            getline(rf,line,';');
            Hp = stoi(line);

            getline(rf,line);
            Ano = stoi(line);
            
            }
        
};

class Passageiro: public Carro {
    private:
        string Nome;
        int Idade;
        Carro carro;

    public:
        Passageiro() {

        }

        Passageiro(string nome, int idade, Carro _carro){
            Nome = nome;
            Idade = idade;
            carro = _carro;
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

        inline void setCarro(Carro _carro){
            carro = _carro;
        }

        inline Carro getCarro(){
            return carro;
        }

        void Show(){
            cout << "Nome: " << getNome() << endl;
            cout << "Idade: " << getIdade() << endl;
            carro.Show();

        }

        void Update(){
            string temp;
            int temp2;

            cout << "Insira um novo Nome: " << endl;
            cin >> temp;
            setNome(temp);

            cout << "Insira a idade: " << endl;
            cin >> temp2;
            setIdade(temp2);

            cout << "Altere o veículo: " << endl;
            Carro carro;
            cin >> carro;
            setCarro(carro);

        }

        friend ostream& operator<< (ostream& sf, Passageiro& p){
                sf << "Nome: " << p.Nome << endl;
                sf << "Idade: " << p.Idade << endl;
                sf << "Carro: " << p.carro << endl;

                return sf;
        }

        friend istream& operator>> (istream& rf, Passageiro& p){
                char aux[100];
                int aux1;

                cout << "Insira o seu Nome: " << endl;
                rf.getline(aux,sizeof aux);
                p.Nome = aux;
                cout << "Insira o seu Idade: " << endl;
                cin >> aux1;
                p.Idade = aux1; 
                cout << "Insira o seu Veículo: " << endl;
                rf >> p.carro;

                return rf;
                
        }

        friend bool operator== (Passageiro p1, Passageiro p2){
                if (p1.Nome == p2.Nome && p1.Idade == p2.Idade && p1.carro == p2.carro){
                    cout << "Estas pessoas sao iguais" << endl;
                    return true;
                } else {
                    cout << "Estas pessoas sao diferentes" << endl;
                    return false;
                }
        }

        friend bool operator!= (Passageiro p1, Passageiro p2){
                if (p1.Nome == p2.Nome && p1.Idade == p2.Idade && p1.carro == p1.carro){
                    cout << "Estas pessoas sao iguais" << endl;
                    return false;
                } else {
                    cout << "Estas pessoas sao diferentes" << endl;
                    return true;
                }
        }

        void MaisNovo(Passageiro p1, Passageiro p2){
            if (p1.Idade < p2.Idade){
                cout << "O primeiro passageiro e mais novo" << endl;
            } else {
                cout << "O segundo passageiro e mais velho" << endl;
            }
        }

        void SaveFile(ofstream& sf){
            sf << "Nome: " << getNome() << endl;
            sf << "Idade: " << getIdade() << endl;
            carro.SaveFile(sf);
        }

        void ReadFile(ifstream& rf){
            string line;

            getline(rf,line,',');
            Nome = stoi(line);

            getline(rf,line,',');
            Idade = stoi(line);

            //getline(rf,line);
            //carro = stoi(line);
        }


};