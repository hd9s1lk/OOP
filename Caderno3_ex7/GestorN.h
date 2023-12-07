#include <list>

using namespace std;

class GestorN{
    private:
        list<int> Lista;
    public:
        GestorN(){
            if (!Lista.empty()){
                Lista.clear();
            }
        };

        ~GestorN(){
            if (!Lista.empty()){
                Lista.clear();
            }
        };

        void setGestorN(list<int> _Lista){
            if (!Lista.empty()){
                Lista.clear();
            }
            Lista = _Lista;
        }

        list<int> getGestorN(){
            return Lista;
        }

        void InserirNumero(int num){
            Lista.push_back(num);
            return;
        }

        void RemoverNumero(int num){
            Lista.remove(num);
        }

        void Listar(){
            list<int>::iterator p = Lista.begin();

            while(p != Lista.end()){
                cout << *p << endl;
                p++;
            }
            cout << "\n";
        }

        int ObterPos(int num){
            int i=-1;

            list<int>::iterator p = Lista.begin();

            while(p != Lista.end()){
                i++;
                if (*p == num){
                    return i;
                }
                p++;
            }
            return -1;
        }


};