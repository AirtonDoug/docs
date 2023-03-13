#include <iostream>
using namespace std;

void triangulos_somas(int n,int v[]){
   

if(n<1){
    return;
}
else{
    int soma=0;
    int aux[n-1];
    for(int i=0;i<n-1;i++){
        soma = v[i] + v[i+1];
        aux[i]=soma;
    }
    triangulos_somas(n-1,aux);

    for(int i=0;i<n;i++){
        if(i==0)
            cout << '[';
        cout << v[i];
        if(i<n-1)
            cout << ", ";
        if(i==n-1)
            cout << ']';
        
    }
    cout << endl;
}


}
int main(){
    int n;
    int vet[50];

    cin >> n;
    
    for(int i = 0;i < n;i++){
        cin >> vet[i];
    }

    triangulos_somas(n,vet);

}