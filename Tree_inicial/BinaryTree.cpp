#include <iostream>
#include "Node.h"
#include <sstream>
#include <string>
#include "BinaryTree.h"
using namespace std;

/**
 * @brief Construct a new empty Binary Tree object
 */
BinaryTree::BinaryTree() {
    root = nullptr;
}

/**
 * @brief Construct a new Binary Tree with two subtrees.
 * The subtrees become empty after this operation
 * 
 * @param value The data at the root
 * @param lchild The left subtree
 * @param rchild The right subtree
 */
BinaryTree::BinaryTree(int value, BinaryTree& lchild, BinaryTree& rchild) {
    root = new Node(value, lchild.root, rchild.root);
    lchild.root = nullptr;
    rchild.root = nullptr;  
}

/**
 * @brief Indicate that this is the empty tree.
 * 
 * @return true if tree is empty
 * @return false if tree is not empty
 */
bool BinaryTree::is_empty() const {
    return root == nullptr;
}

/**
 * @brief Indicate that this tree is a leaf.
 * 
 * @return true if tree is a leaf
 * @return false if tree is not a leaf
 */
bool BinaryTree::is_leaf() const {
    return !is_empty() && root->left == nullptr && root->right == nullptr;
}
bool contains_recursive(Node *node, int value) {
    if(node == nullptr)
        return false;
    if(node->key == value)
        return true;
    else
        return  contains_recursive(node->left, value) ||
                contains_recursive(node->right,value);       
}
/**
 * @brief Indicate if the tree contains the given value
 * 
 * @return true if the tree contains the given value
 * @return false if the tree does not contains the given value
 */
bool BinaryTree::contains(int value) const {
    return contains_recursive(root,value);
}


//função recursiva que imprime todas as chaves da arvore
void print_keys_recursive(Node*node){
    if(node != nullptr){
        cout << node->key << " ";
        print_keys_recursive(node->left);
        print_keys_recursive(node->right);
    }
    
}


/**
 * @brief Print the keys saved on the tree
 */
void BinaryTree::print_keys() const {
    print_keys_recursive(root);
}

//função recursiva que recebe uma raiz de arvore e 
//libera todos os nós contidos nessa arvore, retornando
//nullptr ao final
Node* clear_recursive(Node *node){
    if(node != nullptr){
        node->left = clear_recursive(node->left);
        node->right = clear_recursive(node->right);
        delete node;
    }
    return nullptr;
}


/**
 * @brief empties the tree
 */
void BinaryTree::clear() {
    root = clear_recursive(root);   
}

BinaryTree::~BinaryTree() {
    clear();
}

void preordem_rec(Node *node){
    if(node != nullptr){
        cout << node->key << " ";
        preordem_rec(node->left);
        preordem_rec(node->right);
    }
}

void BinaryTree::preordem() const{
    preordem_rec(root);
}

void posordem_rec(Node *node){
    if(node != nullptr){
        posordem_rec(node->left);
        posordem_rec(node->right);
        cout << node->key << " ";
    }
}

void BinaryTree::posordem() const{
    posordem_rec(root);
}

void ordemsimetrica_rec(Node* node){
    if(node != nullptr){
        ordemsimetrica_rec(node->left);
        cout << node->key << " ";
        ordemsimetrica_rec(node->right);
    }

}

void BinaryTree::ordemsimetrica() const{
    ordemsimetrica_rec(root);
    }


void serialization_rec(Node*node, stringstream&ss){
    if(node== nullptr){
        ss << "# ";
    }else{
        ss << node->key << " ";
        serialization_rec(node->left, ss);
        serialization_rec(node->right, ss);
    }
}

std::string  BinaryTree::serialization() const{
    stringstream ss;
    serialization_rec(root, ss);
    return ss.str();
}

Node* deserialization_rec(stringstream& ss){
    string valor;
    ss >> valor;
    if(valor == "#"){
        return nullptr;
    }
    else{
        Node *aux = new Node(stoi(valor),nullptr,nullptr);
        aux->left = deserialization_rec(ss);
        aux->right = deserialization_rec(ss);
        return aux;
    }
}

BinaryTree::BinaryTree(std::string serial){
    stringstream ss (serial);
    root = deserialization_rec(ss);
}


