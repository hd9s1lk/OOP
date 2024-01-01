#include <iostream>
#include <list>

using namespace std;

class Gestor{
    private:
        list<int> Lista;
    public:
        Gestor(){
            if(!Lista.empty()){
                Lista.clear();
            }
        };

        ~Gestor(){
            if(!Lista.empty()){
                Lista.clear();
            }
        };

        void setGestor(list<int> _Lista){
            if(!Lista.empty()){
                Lista.clear();
            }
            Lista = _Lista;
        }

        list<int> getGestor(){
            return Lista;
        }

        void InserirNumero(int num){
            Lista.push_back(num);
        }

        void RemoverNumero(int num){
            Lista.remove(num);
        }

        void Listar(){
            list<int>:: iterator p = Lista.begin();

            while(p != Lista.end()){
                cout << *p << endl;
                p++;
            } cout << "\n";
        }

        int ObterPos(int num){
            int i=-1;

            list<int>:: iterator p = Lista.begin();
            
            while(p !=Lista.end()){
                i++;
                if (*p==num){
                    return i; 
                }
                p++;
            }
            return -1;
        }

        
};