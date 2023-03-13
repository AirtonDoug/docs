#include <iostream>
using namespace std;

void inverte(int v[],int ini,int fim){
    if(ini < fim){
        int aux = v[ini];
        v[ini] = v[fim];
        v[fim] = aux;
        inverte(v,ini+1,fim-1);
    }


}

void print(int v[],int n){
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    int vetor[] = {1,2,3,4,5};
    int n = sizeof(vetor) / sizeof(int);
    inverte(vetor,0,n-1);

    print(vetor,n);


}