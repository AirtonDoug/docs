// Arquivo de Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include "Matriz.h"
using namespace std;

// Aloca espaco dinamicamente para matriz com m linhas e n colunas
Matriz::Matriz(int m, int n) {
    lin = m;
    col = n;
    mat = new int*[m];
    for(int i=0; i < m; i++){
        mat[i]= new int[n]{0};
    }
}   

// Destrutor: Libera a memoria que foi alocada dinamicamente no construtor
Matriz::~Matriz() {
    for(int i=0;i<lin;i++){
        delete[] mat[i];
    }
   


}   

// Retorna o numero de linhas da matriz
int Matriz::linhas() {
    return lin;
} 

// Retorna o numero de colunas da matriz
int Matriz::colunas() { 
    return col;
}

// Retorna o valor da celula [i][j] da matriz
int Matriz::getValor(int i, int j) {
    return mat[i][j];
} 

// Atribui valor a celula [i][j] da matriz
void Matriz::setValor(int valor, int i, int j) {
    mat[i][j]=valor;
}

// Imprimir a matriz 
void Matriz::print() {
     for(int i = 0; i < lin; i++) {
            for(int j = 0; j < col; j++) {
                std::cout << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
} 

// Soma matrizes
Matriz *Matriz::soma(Matriz& B) {
    if(this->col == B.col && this->lin == B.lin){
        Matriz *C = new Matriz(lin,col);
        for(int i = 0; i < this->lin;i++){
            for(int j = 0;j < this->col ;j++){
                C->setValor((this->mat[i][j]+B.mat[i][j]),i,j);
            }
            return C;
        }
    }else{
        cout << "nao foi possivel somar" << endl;
        return nullptr;

    }
}

// Multiplica matrizes
Matriz *Matriz::multiplica(Matriz& B) {
    if(this->col == B.lin){
        Matriz *C = new Matriz(B.lin,B.col);
        for(int i=0;i < this->lin;i++){
            for(int j =0;j< B.col;j++){
                for(int k=0;k<B.lin;k++){
                    int mult = C->getValor(i,j)+(this->mat[i][k] * B.mat[k][j]);
                    C->setValor(mult,i,j);
                    
                }
            }
        }
        return C;
    }else{
        return nullptr;
    }
}