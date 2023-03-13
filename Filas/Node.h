#ifndef NODE_H
#define NODE_H

template <typename T>

struct Node
{
    T value;
    Node *next;
    //construtor
    Node (const T& val ,Node *next){
        this->value = val;
        this->next = next;
    }
    //Destrutor
    ~Node(){
        delete next;
    }

};


#endif