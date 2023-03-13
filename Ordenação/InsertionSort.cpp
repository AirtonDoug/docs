#include <iostream>
using namespace std;

template <typename T>
void insertionsort(T A[], int l, int r){
    for(j = l+1; j <= r; j++){
        T key = A[j];
        int i = j-1;
        while(i >= l && A[i] > key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }

}


int main(){

}