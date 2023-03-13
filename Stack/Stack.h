#ifndef STACK_H
#define STACK_H
#include <stdexcept>
#include "Node.h"


template <typename T>
class Stack{
private:
    Node<T> *m_top{nullptr};//ponteiro para o topo da pilha
    int m_size{0}; // tamanho da pilha
public:
    //Construtor default
    Stack() = default;
    // verifica se a pilha está vazia
    bool empty() const{
        return m_size == 0;
    }
    //retorna tamanho da pilha
    int size() const{
        return m_size;
    }
    //acessar o valor que está no top
    T& top(){
        if(m_size == 0){
            throw std::underflow_error("empty stack");
        }
        return m_top->value;
    }
    const T& top() const {
        if(m_size == 0){
            throw std::underflow_error("empty stack");
        }
        return m_top->value;
    }
    // inserir elemento no top
    void push(const T& val){
        m_top = new Node<T>(val, m_top);
        m_size++;
    }
    //remover elemento da pilha
    void pop(){
        if(m_size > 0){
            Node<T> *aux = m_top;
            m_top = aux->next;
            delete aux;
            m_size--;
        }
    }
    //liberar memoria da pilha

    ~Stack(){
        while(m_top!= nullptr){
            Node<T> *aux = m_top;
            m_top = aux->next;
            delete aux;
        }
    }

};


#endif