#include <iostream>
#include <fstream>

using namespace std;

class Data{
    private:
            int Dia;
            int Mes;
            int Ano;

    public:
            Data() {
               
            }

            Data(int dia, int mes, int ano){
                Dia = dia;
                Mes = mes;
                Ano = ano;
            }

            inline void setDia(int dia){    //set do dia
                Dia = dia;
            }

            int getDia(){           //get do dia
                return Dia;
            }

            inline void setMes(int mes){    //set do mes
                Mes = mes;
            }

            int getMes(){           //get do mes
                return Mes;
            }

            inline void setAno(int ano){    //set do ano
                Ano = ano;
            }

            int getAno(){           //get do ano
                return Ano;
            }

            void Show(){
                cout << "Ano: " << getAno() << " Mes: " << getMes() << " Dia: " << getDia() << endl;
            }

            void Update(){
                int temp;

                cout << "Introduza um novo dia: " << endl;
                cin >> temp;
                setDia(temp);

                cout << "Introduza um novo mes: " << endl;
                cin >> temp;
                setMes(temp);

                cout << "Introduza um novo Ano: " << endl;
                cin >> temp;
                setAno(temp);

            }

            bool Igual(Data d1){
                if (d1.Ano != getAno()) {
                    cout << "Sao diferentes" << endl;
                    return false;
                    
                } else {
                    cout << "Sao iguais" << endl;
                    return true;
                }
            }


            friend bool operator ==(Data &d1 , Data d2) {
                if (d1.Ano == d2.Ano && d1.Mes == d2.Mes && d1.Dia == d2.Dia){
                    cout << "As datas são iguais" << endl;
                    return true;
                } else {
                    return false;
                }
                    
            }

            friend bool operator !=(Data &d1 , Data d2) {
                if (d1.Ano == d2.Ano && d1.Mes == d2.Mes && d1.Dia == d2.Dia){
                    cout << "As datas são iguais" << endl;
                    return false;
                } else {
                    return true;
                }
                    
            }

            friend ostream& operator<< (ostream& of, Data& d1){
                of << "Dia: " << d1.Dia << endl;
                of << "Mes: " << d1.Mes << endl;
                of << "Ano: " << d1.Ano << endl;

                return of;
            }

            friend istream& operator>> (istream& sf, Data& d1){
                cout << "Indique o dia: " << endl;
                sf >> d1.Dia;

                cout << "Indique o mes: " << endl;
                sf >> d1.Mes;

                cout << "Indique o ano: " << endl;
                sf >> d1.Ano;

                return sf;

            }


            void SaveFile(ofstream& of){
                of << "Data: " << getAno() << "/" << getMes() << "/" << getDia() << endl;
                
            }

            void ReadFile(ifstream& sf){
                string line;

                while(getline(sf,line)){
                    cout << line << endl;
                }
            }

};

class Pessoa: public Data{
    private:
            string Nome;
            string Morada;
            Data data;
    
    public:
            Pessoa() {

            }
            
            Pessoa(string nome, string morada, Data _data){
                Nome = nome;
                Morada = morada;
                data = _data;
            }

            inline void setNome(string nome){
                Nome = nome;
            }

            inline string getNome(){
                return Nome;
            }

            inline void setMorada(string morada){
                Morada = morada;
            }

            inline string getMorada(){
                return Morada;
            }

            inline void setData(Data _data){
                data = _data;
            }

            inline Data getData(){
                return data;
            }

            void Show(){                                      //Mostrar info
                cout << "Nome: " << getNome() << endl;
                cout << "Morada: " << getMorada() << endl;
                data.Show();
            }

            void NewAdress() {                                  //Inserir Nova morada
                char aux[100];
                cout << "Insira uma nova morada: " << endl;
                cin.getline(aux,sizeof aux);
                setMorada(aux);

            }

            void NewDate() {                                  //Inserir nova data
                cout << "Insira uma nova data: " << endl;
                Data data;
                cin >> data;
                setData(data);
            }

            void ReadAll() {                                   //Ler info de novo utilizador atraves do teclado
                char aux[100];
                cout << "Insira o seu nome: " << endl;
                cin.getline(aux, sizeof aux);
                setNome(aux);
                cout << "Insira a sua morada: " << endl;
                cin.getline(aux, sizeof aux);
                setMorada(aux);
                cout << "Insira a sua data: " << endl;
                cin >> data;
                setData(data);

            }

            friend ostream& operator <<(ostream& of, Pessoa p){
                of << "Nome: " << p.Nome << endl;
                of << "Morada: " << p.Morada << endl;
                of << "Data: " << p.data << endl;

                return of;
            }

            friend istream& operator >>(istream& sf, Pessoa& p){
                char aux[100];
                cout << "Insira o seu nome: " << endl;
                sf.getline(aux, sizeof aux);
                p.Nome = aux;
                cout << "Insira a sua morada: " << endl;
                sf.getline(aux, sizeof aux);
                p.Morada = aux;
                cout << "Insira a sua data: " << endl;
                sf >> p.data;

                return sf;
            }


            friend bool operator ==(Pessoa &p1 , Pessoa p2) {
                if (p1.Nome == p2.Nome && p1.Morada == p2.Morada && p1.data == p2.data){
                    cout << "Estas pessoas são iguais" << endl;
                    return true;
                } else {
                    return false;
                }
                    
            }

            friend bool operator !=(Pessoa &p1 , Pessoa p2) {
                if (p1.Nome == p2.Nome && p1.Morada == p2.Morada && p1.data == p2.data){
                    cout << "Estas pessoas são iguais" << endl;
                    return false;
                } else {
                    return true;
                }
                    
            }

            void SaveFile(ofstream& of){
                of << "Nome: " << getNome() << endl;
                of << "Morada: " << getMorada() << endl;
                data.SaveFile(of);
                //of << "Data: " << getData() << endl;
            }

            void ReadFile(ifstream& sf){
                    string line;

                    while(getline(sf, line)){
                        cout << line << endl;
                    }
            }

            void ReadFileVector(ifstream& sf){
                char aux[100];
                int auxData;

                sf.getline(aux, sizeof aux, ';');
                setNome(aux);

                sf.getline(aux, sizeof aux, ';');
                Morada = aux;

                sf.getline(aux, sizeof aux, ';');
                data.setDia(atoi(aux));
                cout << aux;

                sf.getline(aux, sizeof aux, ';');
                data.setMes(atoi(aux));
                cout << aux;

                sf.getline(aux, sizeof aux, ';');
                data.setAno(atoi(aux));
                cout << aux;

            }


};

