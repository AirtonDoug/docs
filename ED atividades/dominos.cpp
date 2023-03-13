#include <iostream>
using namespace std;

int main(){
    int n;
    int vetor[50];
    bool ordenado;
    cin >> n;

    for(int i =0;i < n ; i++)
        cin >> vetor[i];
    

    for(int i=0; i < n-1 ;i++){
        if(vetor[i] <= vetor[i+1]){
            ordenado = true;
        }else{
            ordenado = false;
            break;
        }

    }
    if(ordenado == true || n == 1)
        cout << "ok" << endl;
    else    
        cout << "precisa de ajuste" << endl;

}
