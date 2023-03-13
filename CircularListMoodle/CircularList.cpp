#include <sstream>
#include <string>
#include "Node.h" 
#include "CircularList.h" 



void CircularList::push_back(const Item& val) { 
    Node *aux = m_head;
    if(aux == nullptr){
        aux = new Node(val,m_head);
        aux->next = m_head;
    }else{
    while(aux->next != m_head){
        aux=aux->next;
    }
    aux->next = new Node(val,m_head);
    }
    m_size++;
}

void CircularList::pop_back() {
    if(m_head == nullptr)
        return;
    if(m_head->next == m_head){
        delete m_head;
        m_head = nullptr;
    }else{
        Node *aux = m_head;
        while (aux->next->next != m_head)
        {
            aux=aux->next;
        }
        delete aux->next;
        aux->next = m_head;
    }
    m_size--;    
}

std::string CircularList::toString() const {
    std::stringstream ss;
        ss << "[ ";
        Node *atual = m_head;
       while (atual->next!=m_head)
       {
        ss << atual->next->value << " ";
        atual = atual->next;
       }
       
        ss << "]";

        return ss.str();
}

Item& CircularList::operator[](int index) {
    Node *aux =m_head;
    for(int i=0;i<index;i++){
        aux=aux->next;
    }
    return aux->value;
}

const Item& CircularList::operator[](int index) const {
    Node *aux =m_head;
    for(int i=0;i<index;i++){
        aux=aux->next;
    }
    return aux->value;
}
/*
void clear_recursive(Node *nodeAtual, Node *cabeca){
    if(nodeAtual->next == cabeca){
        delete nodeAtual;
    }else{
        clear_recursive(nodeAtual->next,cabeca);
        delete nodeAtual;
    }
}


void CircularList::clear() {
    if(m_head!= nullptr){

    clear_recursive(m_head,m_head);
    m_head = nullptr;
    m_size = 0;
    }
    else    
        return;
}
*/

void CircularList::clear(){
    if(m_head!= nullptr){
        Node* aux1 = m_head->next;
        Node* aux2 = m_head->next;
        while(aux1!= m_head){
            aux2 = aux2->next;
            delete aux1;
            aux1 = aux2;
        }
        delete m_head;
        m_size = 0;
        m_head = nullptr;
    }
}
//insere val no índice especificado
void CircularList::insert(int index,const Item& val){
    if(index <0 || index > m_size){
        throw std:: range_error("indice invalido");
    }
    if(m_head == nullptr){
        m_head = new Node(val,nullptr);
        m_head->next = m_head;
        m_size++;
    }
   else if(index == 0){
        Node * novo = new Node(val,m_head);
        m_size++;
        
        Node *aux = m_head;
        while(aux->next!=m_head)
            aux = aux->next;
        aux->next = novo;
        m_head = novo;
    }
    else{
        Node* aux = m_head;

        for(int i=0;i<index-1;i++){
            aux=aux->next;
        }
        Node * novo = new Node(val,aux->next);
        aux->next = novo;
        m_size++;
    }
}


void CircularList::remove(const Item& val){
    if(m_head == nullptr){
        return;
    }
    if(m_head->next == m_head){
        if(m_head->value == val){
            delete m_head;
             m_size--;
            m_head= nullptr;
        }
    }else{
        if(m_head->value == val){
            Node * aux = m_head;
            while (aux->next != m_head)
            {
                aux = aux->next;
            }
            aux->next = m_head->next;
            delete m_head;
             m_size--;
            m_head = aux->next;

            
        }
        else{
            Node * aux = m_head;

            while(aux->next->value != val && aux->next->value!= val){
                aux = aux->next;
            }
            if(aux->next != m_head){
                Node *temp = aux->next;
                aux->next = temp->next;
                delete temp;
                 m_size--;
            }
        }
       
    }
}

CircularList::~CircularList() {
    // FAZER
}

