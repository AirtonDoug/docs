#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int product, A, B;

    cin >> product >> A >> B;

    if(abs(product-A) < abs(product-B)){
        cout << "primeiro" << endl;
    }  if(abs(product-A) > abs(product-B)){
        cout << "segundo"<< endl;
    }else if(abs(product - A) ==  abs(product - B)){
        cout << "empate" << endl;

    }



}