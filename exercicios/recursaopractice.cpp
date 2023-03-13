#include <iostream>
using namespace std;

int fat(int n){
    if(n==0 || n==1){
        return 1;
    }else{
        return fat(n-1)*n;
    }
}

int main(){
    cout << fat(5) << endl;
}