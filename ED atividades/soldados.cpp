#include <iostream>
using namespace std;

int main(){
    int soldados[5][5];
    int count=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> soldados[i][j];

        }

    }
    
    for(int i=0;i<2;i++){
        if(soldados[i][0] > soldados[i+1][0])
            count++;
    }
    for(int i=0;i<2;i++){
        if(soldados[i][1] > soldados[i+1][1])
            count++;
    }
     for(int i=0;i<2;i++){
        if(soldados[i][2] > soldados[i+1][2])
            count++;
    }



    cout << count << endl;
}