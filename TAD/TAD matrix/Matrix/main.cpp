#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
    int linhas, colunas;
    cout << "Forneca o numero de linhas e de colunas: ";
    cin >> linhas >> colunas;
    Matrix M(linhas, colunas);
    M.print();
}