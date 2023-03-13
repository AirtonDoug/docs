#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include "Node.h"
class SparseMatrix{
public:
    //ATRIBUTOS DA MATRIZ ESPARAS
    //Node cabeca dos cabeças
    Node *m_head;
    //Primeiro Node cabeca das linhas
    Node *i_head;
    //Primeiro Node cabeca das colunas
    Node *j_head;
    //Nº de linhas
    int i_size;
    //Nº de colunas
    int j_size;


    //Construtor que inicializa a Matrix com tamanho (m x n) vazia
    SparseMatrix(int m, int n);

    //Destrutor apaga todos os valores dentro da matriz e os nodes cabecas
    ~SparseMatrix();

    //Devolve valor na célula(ixj) da matriz
    //desde que o valor de 1 < i <= nº de linhas
    // e 1 < j <= nº de colunas
    double get(int i, int j);

    //Imprime a matriz esparsa completa(inclusive os zeros)
    void print();

    //insere val na posição i x j
    void insert(double val, int i, int j);

  

    

    

    

};






#endif