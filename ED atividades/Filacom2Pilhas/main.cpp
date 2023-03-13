#include <iostream>
#include "Queue.h"
using namespace std;

int main(){
    int op;
    int size;
    Queue fila;
    cin >> size;

    for(int i = 0; i < size ; i++){
        cin >> op;
        switch (op)
        {
        case 1:
            int x;
            cin >> x;
            fila.Enfileirar(x);
            break;
        case 2:
            fila.Desenfileirar();
            break;
        case 3:
            cout << fila.show_front() << endl;
            break;
        default:
            cout << "opcao invalida" << endl;
            break;
        }
    }

    
    

}