#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

class Matrix {
private:
    int linhas;  // numero de linhas
    int colunas; // numero de colunas
    int **mat;   // ponteiro para a matriz em si

public:
    // Construtor com dois parametros
    Matrix(int n, int m) {
        linhas = n;
        colunas = m;
        mat = new int*[n];
        for(int i = 0; i < n; i++) {
            mat[i] = new int[m]{0}; // ja inicializa com zeros
        }
        std::cout << "matriz criada" << std::endl;
    }

    // Imprime a matriz
    void print() {
        for(int i = 0; i < linhas; i++) {
            for(int j = 0; j < colunas; j++) {
                std::cout << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    // Destrutor
    ~Matrix() {
        for(int i = 0; i < linhas; i++) {
            delete[] mat[i];
        }
        delete[] mat;
        std::cout << "matriz liberada" << std::endl;
    }
};

#endif