#ifndef QUEUE_H
#define QUEUE_H
#include <stack>

class Queue{
private:
    std::stack<int> deposito;
    std::stack<int> prateleira;

public:
    void Enfileirar(int);
    void Desenfileirar();
    int show_front();

};


#endif