#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int *ptr = new int[n]; //quando n tem memoria o new lança uma exception

    for(int i=0;i< n;i++){
        ptr[i] = i;
    }
    for(int i=0;i< n;i++){
        cout << ptr[i] << " ";
    }
    cout << endl;
    delete[] ptr;

    ptr = nullptr;
}