#include <iostream>
#include <cstdlib> // pesquisar: <random>
#include <chrono>
void bubblesort(int A[],int l, int r){
    int aux;
    bool trocou = false;
    for(int i = l ;i <  r;i++){
        for(int j = r; j > i; j--){
            if(A[j] < A[j-1]){
                aux = A[j];
                A[j] = A[j-1];
                A[j-1] = aux;
                trocou= true;
            }
        }
        if(!trocou)
            break;
    }
}

void print(int A[],int l,int r){
    for(int i = l; i<=r; i++){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    const int n= 10000;
    int vec[n];

    for(int i = 0; i < n; i++){
        vec[i] = rand() % 100;
    }
    auto start = std::chrono::steady_clock::now();
    bubblesort(vec, 0, n-1);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_time = end-start;
    auto duration=
         std::chrono::duration_cast<std::chrono::seconds>(elapsed_time);
    //print(vec, 0, n-1);


   /* int v[]{3,7,6,5,88,77,12,11};
    int n = sizeof (v) / sizeof(v[0]);
    print(v,0,n-1);
    bubblesort(v,0,n-1);
    print(v,0,n-1);
*/

}
