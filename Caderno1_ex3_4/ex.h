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

class Funcionario: public Pessoa{
    private:
        int Num_func;
        string Setor;
        Pessoa pessoa;
        float P_hora_extra;
        int Horas_extra;
        float OrdBase;
    public:
        Funcionario(){

        }

        Funcionario(int num_func, string setor, float p_hora_extra,Pessoa _pessoa, int horas_extra, float ordbase){
            Num_func = num_func;
            Setor = setor;
            P_hora_extra = p_hora_extra;
            pessoa = _pessoa;
            Horas_extra = horas_extra;
            OrdBase = ordbase;
        }

        inline void setOrdBase(float ordbase){
            OrdBase = ordbase;
        }

        inline float getOrdBase(){
            return OrdBase;
        }

        inline void setHoras_extra(int horas_extra){
            Horas_extra = horas_extra;
        }

        inline int getHoras_extra(){
            return Horas_extra;
        }

        inline void setP_hora_extra(float p_hora_extra){
            P_hora_extra = p_hora_extra;
        }

        inline float getP_hora_extra(){
            return P_hora_extra;
        }

        inline void setNum_func(int num_func){
                Num_func=num_func;
            }

        inline int getNum_func(){
                return Num_func;
            }

        inline void setSetor(string setor){
            Setor=setor;
        }
        
        inline string getSetor(){
            return Setor;
        }

        inline void setPessoa(Pessoa _pessoa){
            pessoa = _pessoa;
        }

        inline Pessoa getPessoa(){
            return pessoa;
        }

        void Show(){
            pessoa.Show();
            cout << "Numero de Funcionario: " << getNum_func() << endl;
            cout << "Setor: " << getSetor() << endl;
        }

        void ex5(){
            pessoa.NewAdress();

            char aux[100];
            cout << "Insira um novo setor: " << endl;
            cin.getline(aux, sizeof(aux));
            setSetor(aux);
        }

        void ex6(){
            pessoa.NewDate();
        }

        friend istream& operator >>(istream& sf, Funcionario& f){
                
                char aux[100];

                sf >> (Pessoa&) f;
                cout << "Numero de funcionario: ";
                sf >> f.Num_func;
                cout << "Setor: ";
                sf >> aux;
                f.Setor = aux;                

                return sf;
            }
        
        void SaveFile(ofstream& of){
            
            pessoa.SaveFile(of);
            of << getNum_func() << "/" << getSetor() << endl;
        }

        void ReadFile(ifstream& sf){
            pessoa.ReadFile(sf);

            char aux[100];
            sf.getline(aux, 100, ';');
            Num_func = atoi(aux);
            sf.getline(aux,100,',');
            Setor = aux;

        }

        void BubbleSort(Funcionario *f, int size){
            bool swaped;
            int i,j;

            i = size;
            do {
                swaped = false;
                for(j=1; j<i; j++){
                    if ((f + j -1)->getNome() > (f+j)->getNome()){
                        Swap(f + j -1, f+j);
                        swaped = true;
                    }
                    i--;
                } 
            } while (i>0 && swaped);
        }

        void Swap(Funcionario *f, Funcionario* f2){
            Funcionario aux;

            aux = *f;
            *f = *f2;
            *f2 = aux;
        }

        virtual float Calcula_Ordenado();


};


class Operario: public Funcionario {
    private:
        bool F_turno;
        Funcionario F;
    public:
        Operario(){

        }
        Operario(bool f_turno, Funcionario f){
            F_turno = f_turno;
            F = f;
        }

        inline void setF_turno(bool f_turno){
            F_turno = f_turno;
        }

        inline bool getF_turno(){
            return F_turno;
        }

        void Show(){
            F.Show();            
            if (F_turno){
                cout << "Em turno: " << getNome() << "/" << getNum_func() << endl;
            } else {
                cout << "Ninguem em turno" << endl;
            }
        }

        void ReadAll() {   
                F.ReadAll();                                //Ler info de novo utilizador atraves do teclado
                string op;
                cout << "Trabalho por turno (S/N)" << endl;
                cin >> op;
                if (op == "S" || op == "s"){
                    F_turno = true;
                } else {
                    F_turno = false;
                }
            }

        void ReadFile(ifstream& sf){
            F.ReadFile(sf);
            string op;
            cout << "Trabalho por turno (S/N)" << endl;
            getline(sf, op, ',');
            if (op == "S" || op == "s"){
                F_turno = true;
            } else {
                F_turno = false;
            }
        }

        void Savefile(ofstream& of){
            F.SaveFile(of);

            if (F_turno == true){
                of << "Sim" << endl;
            } else {
                of << "Não" << endl;
            }

        }

        float Calcula_Ordenado(){
            if (F_turno){
                return getOrdBase() * 1.25f + getHoras_extra() * getP_hora_extra();
            } else {
                return getOrdBase() + getHoras_extra() * getP_hora_extra();
            }
        }

};

class Administrativo: public Funcionario{
    private:
        Funcionario F;
    public:

        Administrativo(){

        }
        Administrativo(Funcionario f){
            F = f;
        }

        float Calcula_Ordenado(){
            return getOrdBase() + getHoras_extra() * getP_hora_extra();
        }

};
