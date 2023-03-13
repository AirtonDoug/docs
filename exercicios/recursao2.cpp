#include <iostream>
using namespace std;

int maximo1(int ini,int fim, int v[]){
    if(ini == fim){
        return v[ini];
    }else{
        int x = (ini+fim)/2;
        int max1 = maximo1(ini,x,v);
        int max2 = maximo1(x+1,fim,v);
        if(max1>max2)
            return max1;
        else
            return max2;    
    }
}


// recebe um vetor com n elementos e retorna o maior entre eles
int maximo(int n, int v[]){
    if(n==1){
        return v[n-1];
    }
    else{
        int maior = maximo(n-1,v);

        if(maior > v[n-1])
            return maior;
        else
            return v[n-1];    

    }
}

int main(){
    int vetor[] ={-1,0,9,5,15,19,98,37,123,38};
    int n = sizeof(vetor) / sizeof(int); // da a quantidade de elementos de um vetor 
    cout << maximo1(0,n-1,vetor) << endl;


}