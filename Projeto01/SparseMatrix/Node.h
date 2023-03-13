#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node{// Classe Node   
public:
    int linha;//Possui um valor inteiro representando sua coordenada na linha
    int coluna;//e na coluna
    Node *next;//possui um ponteiro para o proximo elemento a direita
    Node *below;//possui um ponteiro para o elemento abaixo
    double valor;// e o valor do elemento na matriz
    
    Node(int linha,int coluna,Node*prox,Node*abaixo,double valor){//Construtor do Node recebe em ordem a 
        this->linha= linha;                                       // linha e coluna do node a referencia para o proximo, referencia para o abaixo e o valor.
        this->coluna = coluna;
        next = prox;
        below = abaixo;
        this->valor = valor;
    }    
};





#endif