/************************************************************************
 * Arquivo de implementacao da classe ForwardList
 * No final deste arquivo existem algumas funcoes que estao incompletas 
 * e voce precisa implementa-las para concluir a atividade
 ************************************************************************/
#include <vector>
#include <stdexcept>
#include <string>
#include "Node.h"
#include "ForwardList.h"

/***************************************************
 * Implementacao das funcoes-membro da classe
 ***************************************************/

ForwardList::ForwardList() {
    m_head = new Node(0, nullptr);
    m_size = 0;
}

ForwardList::ForwardList(const ForwardList& lst) {
    m_head = new Node(0, nullptr);
    m_size = lst.m_size;
    Node *lstCurrent = lst.m_head->next;
    Node *thisLast = m_head;
    while(lstCurrent != nullptr) {
        thisLast->next = new Node(lstCurrent->value, nullptr);
        lstCurrent = lstCurrent->next;
        thisLast = thisLast->next;
    }
} 

bool ForwardList::empty() const {
    return m_head->next == nullptr;
}

int ForwardList::size() const {
    return m_size;
}

void ForwardList::clear() {
    while(m_head->next != nullptr) {
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

ForwardList::~ForwardList() {
    clear();
    delete m_head;
}

Item& ForwardList::operator[](int index) {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

const Item& ForwardList::operator[](int index) const {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

void ForwardList::insert_at(int index, const Item& val) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *newNode = new Node(val, current->next);
    current->next = newNode;
    m_size++;
}

void ForwardList::remove_at(int index) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    m_size--;
}

std::string ForwardList::toString() {
    std::string str = "[ ";
    Node *ptr = m_head->next;
    while(ptr != nullptr) {
        str += std::to_string(ptr->value) + " ";
        ptr = ptr->next;
    }
    str += "]";
    return str;
}

/***********************************************************
 * Funcoes adicionais - Parte 2
 ***********************************************************/

void ForwardList::concat(ForwardList& lst) {
    if(lst.m_head->next == nullptr)
        return;
    if(lst.m_head->next->next == nullptr){
        Node *aux = this->m_head;
        while(aux->next!=nullptr){
            aux=aux->next;
        }
        aux->next = lst.m_head->next;
        m_size++;
    }
    else{    
        Node *aux = this->m_head;
        while(aux->next!=nullptr){
            aux=aux->next;
        }
        aux->next = lst.m_head->next;
        lst.m_head->next = nullptr;
        this->m_size+=lst.m_size;
    
    }
    
}

void ForwardList::remove(const Item& val) {
    if(m_head->next == nullptr)
        return;
    if(m_head->next->next == nullptr){
        if(m_head->next->value == val){
            delete m_head->next;
            m_head->next = nullptr;
            m_size--;
        }
    }
    else{    
        Node * aux = m_head;
        Node * aux2;
        while(aux->next!=nullptr){
            
            if(aux->next->value == val){
                aux2 = aux->next;
                aux->next= aux->next->next;
                delete aux2;
                m_size--;
                continue;
            }
            aux=aux->next;  
        }
    }
}

ForwardList* ForwardList::clone() {
    ForwardList *list = new ForwardList;
    Node *aux = this->m_head->next;
    Node *aux2 = list->m_head;
    while(aux !=nullptr){
        Node * novo = new Node(aux->value,nullptr);
        aux2->next = novo;
        aux2=aux2->next;
        aux=aux->next;
    
    }
    list->m_size = this->m_size;
    return list;
}

void ForwardList::appendVector(const std::vector<Item>& vec) {
    Node * aux = m_head;
    while(aux->next != nullptr)
        aux = aux->next;
    for(int i = 0; i < (int)vec.size(); i++){
        Node * novo = new Node(vec[i],nullptr);
        aux->next = novo;
        aux = novo;
        m_size++;
    }
}

void ForwardList::swap(ForwardList& lst) {
    Node *aux = this->m_head->next;
    int aux1 = this->m_size;

    this->m_head->next = lst.m_head->next;
    lst.m_head->next = aux;
    this->m_size = lst.m_size;
    lst.m_size = aux1;
    

}

bool ForwardList::equals(const ForwardList& lst) const {
    if(this->m_size == lst.m_size){
        Node *aux = this->m_head->next;
        Node *aux2 = lst.m_head->next;
        bool ok;
        for(int i=0;i < this->m_size;i++){
            if(aux->value == aux2->value)
                ok = true;
            else
                return false;
           aux = aux->next;
           aux2 = aux2->next;         
        }
        return ok;
    }else{
        return false;
    }
}

void ForwardList::reverse() {
    if(m_size == 1 || m_size == 0)
         return;

    Node *auxPrev = nullptr;
    Node *auxCurrent = m_head->next;
    Node *auxNext = nullptr;

    while(auxCurrent!=nullptr){
        auxNext = auxCurrent->next;
        auxCurrent->next = auxPrev;
        auxPrev = auxCurrent;
        auxCurrent = auxNext;
    }
    m_head->next = auxPrev;
}
Item& ForwardList::get(int index) {
      if(index < 0 || index >= m_size){
        throw std::range_error("index out of range.");
    }else{
    Node *aux = m_head->next;
    for(int i=0; i < index; i++){
        aux=aux->next;
    }
    return aux->value;
    }
}

const Item& ForwardList::get(int index) const {
     if(index < 0 || index >= m_size){
        throw std::range_error("index out of range.");
    }else{
    Node *aux = m_head->next;
    for(int i=0; i < index; i++){
        aux=aux->next;
    }
    return aux->value;
    }
}
