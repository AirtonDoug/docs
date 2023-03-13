#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;


template <typename T>
void combina_filas(Queue<T>&fres, Queue<T>& f1, Queue<T>& f2){

    while(!f1.empty() && !f2.empty()){
        fres.push(f1.front());
        fres.push(f2.front());
        f1.pop();
        f2.pop();
    }
    while(!f1.empty()){
        fres.push(f1.front());
        f1.pop();
    }
     while(!f2.empty()){
        fres.push(f2.front());
        f2.pop();
    }
    



}

int main(){

    Queue<int> fila,fila2,fres;

    for(int i= 1 ;i<=5; i++) fila.push(i);
    for(int i= 7 ;i<=9; i++) fila.push(i);

    combina_filas(fres,fila,fila2);

    while(!fres.empty()){
        cout << fres.front() << endl;
        fres.pop();
    }

}