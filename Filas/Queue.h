#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>
#include "Node.h"

template <typename T>
class Queue{
private:
    Node<T> *m_first{nullptr};
    Node<T> *m_last{nullptr};
    int m_size {0};

public:
    //construtor padrão
    Queue() = default;
    // retorna se a fila esta vazia ou nao
    bool empty() const{
        return m_first == nullptr;
    }
    // retorna o tamanho da fila
    int size () const{
        return m_size;
    }
    // retorna o valor da primeira posicao
    T& front(){
        if(m_size == 0){
            throw std::underflow_error("empty queue");
        }
        return m_first->value;
    }

    const T& front() const{
        if(m_size == 0){
            throw std::underflow_error("empty queue");
        }
        return m_first->value;
    }

    T& back(){
          if(m_size == 0){
            throw std::underflow_error("empty queue");
        }
        return m_last->value;
    }

    const T& back() const{
          if(m_size == 0){
            throw std::underflow_error("empty queue");
        }
        return m_last->value;
    }
    //insere o valor no final da fila
    void push(const T& val){
        if(m_size==0){
            m_first = m_last = new  Node<T> (val,nullptr);
        }else{
            m_last->next = new  Node<T>(val,nullptr);
            m_last = m_last->next;
        }
        m_size++;
    }

    void pop(){
        if(m_size > 0){
            Node<T> * aux = m_first;
            m_first = aux->next;
            aux->next = nullptr;
            delete aux;
            m_size--;
            if(m_size == 0)
                m_last = nullptr;
        }
    }



};




#endif