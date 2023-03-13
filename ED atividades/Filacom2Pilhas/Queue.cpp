#include "Queue.h"
#include <stack>

void Queue::Enfileirar(int value){
    while(!deposito.empty()){
            prateleira.push(deposito.top());
            deposito.pop();
        }
        deposito.push(value);
    while(!prateleira.empty()){
            deposito.push(prateleira.top());
            prateleira.pop();
        }
    }

void Queue::Desenfileirar(){
    if(!deposito.empty()){
            deposito.pop();
        }
    }
int Queue::show_front(){
    return deposito.top();
    }    
