#include <sstream>
#include <string>
#include "Node.h" 
#include "CircularList.h" 

void CircularList::push_back(const Item& val) { 
    if(m_head == nullptr) { // lista vazia
        m_head = new Node(val, nullptr);
        m_head->next = m_head;
    }
    else { // lista nao vazia
        Node *atual = m_head;
        while(atual->next != m_head) 
            atual = atual->next;
        atual->next = new Node(val, m_head);
    } 
    m_size++;
}

void CircularList::pop_back() {
    if(m_head == nullptr)   // lista vazia
        return;
    if(m_head->next == m_head) { // 1 elemento
        delete m_head;
        m_head = nullptr;
    }
    else { // 2 ou mais elementos
        Node *atual = m_head;
        while(atual->next->next != m_head)
            atual = atual->next;
        delete atual->next;
        atual->next = m_head;
    }
    m_size--;
}

std::string CircularList::toString() const {
    std::stringstream ss;
    ss << "[ ";
    Node *atual = m_head;
    if(atual != nullptr) {
        ss << atual->value << " ";
        while(atual->next != m_head) {
            atual = atual->next;
            ss << atual->value << " ";
        }
    }
    ss << "]";
    return ss.str();
}

Item& CircularList::operator[](int index) {
    Node *temp = m_head;
    int count = 0;
    while(count < index) {
        count++;
        temp = temp->next;
    }
    return temp->value;
}

const Item& CircularList::operator[](int index) const {
    Node *temp = m_head;
    int count = 0;
    while(count < index) {
        count++;
        temp = temp->next;
    }
    return temp->value;
}

// libera todos os nós, se tiver nó
// e deixa m_size = 0
void CircularList::clear_iterativo() { // O(n)
    if(m_head != nullptr) {
        Node *aux1 = m_head->next;
        Node *aux2 = m_head->next;
        while(aux1 != m_head) {
            aux2 = aux2->next;
            delete aux1;
            aux1 = aux2;
        }
        delete m_head;
        m_size = 0;
        m_head = nullptr;
    }
}

CircularList::~CircularList() {
    clear_iterativo();
}


// recursive function = O(n)
void clearRecursive(Node *node, Node *head) {
    if(node != head) {
        clearRecursive(node->next, head);
    }
    delete node;
}

// aversion using a recursive function
void CircularList::clear_recursivo() {
    if(m_head != nullptr) {
        clearRecursive(m_head->next, m_head);
        m_head = nullptr;
        m_size = 0;
    }
}

// insere val no índice especificado
// se o index for invalido, entao lanca uma exception
void CircularList::insert(int index, const Item& val) {
    if(index < 0 || index > m_size) {
        throw std::range_error("indice invalido");
    }
    if(m_head == nullptr) { // lista vazia
        m_head = new Node(val, nullptr);
        m_head->next = m_head;
        m_size++;
    }
    else if(index == 0) { // lista com pelo menos 1 elemento e insere na frente
        Node *novo = new Node(val, m_head);
        m_size++;
        Node *aux = m_head;
        while(aux->next != m_head) {
            aux = aux->next;
        }
        aux->next = novo;
        m_head = novo;
    }
    else { // lista com pelo menos 1 elemento e insere em outra posicao
        Node *aux = m_head;
        for(int cont = 0; cont < index-1; cont++) {
            aux = aux->next;
        }
        Node *novo = new Node(val, aux->next);
        aux->next = novo;
        m_size++;
    }
}

// Remove a primeira ocorrencia de val da lista
void CircularList::remove(const Item& val) {
    if(m_head == nullptr) { // caso lista vazia
        return;
    }
    if(m_head->next == m_head) { // caso lista com 1 elemento
        if(m_head->value == val) {
            delete m_head;
            m_head = nullptr;
            m_size = 0;
        }
    }
    else { // caso lista com pelo menos dois elementos
        if(m_head->value == val) {
            Node *aux = m_head;
            while(aux->next != m_head) {
                aux = aux->next;
            }
            aux->next = m_head->next;
            delete m_head;
            m_head = aux->next;
            m_size--;
        }
        else {
            Node *aux = m_head;
            while(aux->next != m_head && aux->next->value != val) {
                aux = aux->next;
            }
            if(aux->next != m_head) {
                Node *temp = aux->next;
                aux->next = temp->next;
                delete temp;
                m_size--;
            }
        }
    }
}


