#include <iostream>
using namespace std;

int main(){
     int matriz[4][4];
    int linha0;
    int linha1;
    int linha2;

    int coluna0;
    int coluna1;
    int coluna2;

    int diagonal0;
    int diagonal1;

    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cin >> matriz[i][j];
        }
    }
    
    linha0 = matriz[0][0]+ matriz[0][1] + matriz[0][2];
    linha1 = matriz[1][0]+ matriz[1][1] + matriz[1][2];
    linha2 = matriz[2][0]+ matriz[2][1] + matriz[2][2];

    coluna0 = matriz[0][0] + matriz[1][0] + matriz[2][0];
    coluna1 = matriz[0][1] + matriz[1][1] + matriz[2][1];
    coluna2 = matriz[0][2] + matriz[1][2] + matriz[2][2];

    diagonal0 = matriz[0][0] + matriz[1][1] + matriz[2][2];
    diagonal1 = matriz[0][2] + matriz[1][1] + matriz[2][0];

    if(linha0==linha1 && linha0 == linha1 && linha0 == linha2 && linha0== coluna0 && linha0 == coluna1 && linha0 == coluna2 && linha0 == diagonal0 && linha0 == diagonal1)
        cout << "sim" << endl;
    else
        cout << "nao" << endl;


}