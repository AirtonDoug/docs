#ifndef CLIST_H
#define CLIST_H
#include <string>
#include "Node.h"

class CircularList {
private:
    Node *m_head {nullptr}; 
    int m_size {0};
    
public:
    CircularList() = default; 
    bool empty() const { return m_head == nullptr; } 
    int size() const { return m_size; }
    
    void push_back(const Item& val); 
    void pop_back();
    Item& operator[](int index);
    const Item& operator[](int index) const;
    std::string toString() const;
    void clear_iterativo();
    void clear_recursivo();
    ~CircularList();

    void insert(int index, const Item& val);
    void remove(const Item& val);
};

#endif