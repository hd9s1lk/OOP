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
        string Equipa;

    public:
        Passageiro() {

        }

        Passageiro(string nome, int idade, string equipa,Carro _carro){
            Nome = nome;
            Idade = idade;
            Equipa = equipa;
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

        inline void setEquipa(string equipa){
            Equipa = equipa;
        }

        inline string getEquipa(){
            return Equipa;
        }

        

        void Show(){
            cout << "Nome: " << getNome() << endl;
            cout << "Idade: " << getIdade() << endl;
            cout << "Equipa: " << getEquipa() << endl;
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

            cout << "Insira a equipa: " << endl;
            cin >> temp;
            setEquipa(temp);

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

class Combustivel: public Passageiro{
    private:
        string Tipo_combustivel;
        Passageiro P;
        Carro carro;
    public:
        Combustivel(){

        }
        
        Combustivel(string tipo_combustivel,Passageiro p){
            Tipo_combustivel = tipo_combustivel;
            P = p;
        }

        inline void setTipo_Combustivel(string tipo_combustivel){
            Tipo_combustivel = tipo_combustivel;
        }

        inline string getTipo_Combustivel(){
            return Tipo_combustivel;
        }

        inline void setPassageiro(Passageiro p){
            P = p;
        }

        inline Passageiro getPassageiro(){
            return P;
        }

        void Show(){
            P.Show();

            cout << "Tipo de combustivel: " << getTipo_Combustivel() << endl;
        }

        void Update(){
            P.Update();

            char aux[100];
            cout << "Insira um novo tipo de combustivel: " << endl;
            cin >> aux;
            setTipo_Combustivel(aux);

        }

        void ShowCarro(){
            P.getCarro();
            cout << "Combustivel: " << getTipo_Combustivel() << endl;

        }

        friend istream& operator >>(istream& sf, Combustivel& c){
            
            char aux[100];

            sf >> (Passageiro&) c;
            cout << "Insira um novo tipo de combustivel: " << endl;
            sf >> aux;
            c.Tipo_combustivel = aux;            

            return sf;

        }

        friend ostream& operator << (ostream& rf, Combustivel& c){

            rf << (Passageiro&) c;
            rf << "Tipo de combustivel: " << c.Tipo_combustivel << endl;

            return rf;
        }

        void Savefile(ofstream& rf){
            P.SaveFile(rf);
            rf << "Tipo de combustivel: " << getTipo_Combustivel() << endl;

        }

        void ReadFile(ifstream& sf){
            P.ReadFile(sf);

            string line;
            while(getline(sf,line)){
                cout << line << endl;
            }
        }

        void Swap(Combustivel* c1, Combustivel* c2){
            Combustivel temp;

            temp = *c1;
            *c1 = *c2;
            *c2 = temp;
        }

};

class Piloto: public Passageiro{
    private: 
        string Equipa;
        Passageiro P;
    public:
        Piloto(){

        }
        Piloto(string equipa, Passageiro p){
            Equipa = equipa;
            P = p;
        }

        void Update(){
            P.Update();

            string temp;
            cout << "Insira uma nova equipa: " << endl;
            cin >> temp;
            setEquipa(temp);
        }

        friend istream& operator >>(istream& sf, Piloto& p){
            
            char aux[100];

            cout << "Insira dados do passageiro: " << endl;
            sf >> p.P;
            cout << "Insira uma nova equipa: " << endl;
            sf >> aux;
            p.Equipa = aux;            

            return sf;

        }

        friend ostream& operator << (ostream& rf, Piloto& p){

            rf << "Tudo: " << p.P << endl;
            rf << "Equipa: " << p.Equipa << endl;

            return rf;
        }

        void Savefile(ofstream& rf){
            P.SaveFile(rf);

            rf << "Equipa: " << getEquipa() << endl;

        }

        void ReadFile(ifstream& sf){
            P.ReadFile(sf);

            char aux[100];
            cout << "Equipa: " << endl;
            sf >> aux;
            setEquipa(aux);

        }


};