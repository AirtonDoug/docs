#include <iostream>
using namespace std;

void print_array(int n, int v[]){
    for(int i=0; i < n; i++){
        cout << v[i] <<" ";
    }
    cout << endl;
}

void print_array2(int n, int *ptr){
    for(int i=0; i < n; i++){
        cout << ptr[i] << " ";
    }
    cout << endl;
}
void print_reverso(int n, int *ptr){
    for(int i=n-1;i>=0;i--){
         cout << ptr[i] << " ";
    }
    cout << endl;
}

int main(){
    int array[10] {0,1,7895,3,4,5,6,7,8,9};


    
    print_array(10,array);
    print_array2(10,array);
    print_reverso(10,array);

}