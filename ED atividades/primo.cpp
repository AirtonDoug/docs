#include <iostream>
using namespace std;


bool primo (int n){

    for(int i = 2; i < n; i++){
        if(n % i == 0)
            return false;


    }
    return true;


}


int main(){
    int A;
    int B;

    cin >> A >> B;

    for(int i = A;i <= B; i++){
        if(primo(i) == 1)
            cout << i << endl;

    
    }




}