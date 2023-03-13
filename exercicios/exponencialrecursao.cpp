#include <iostream>
using namespace std;

double exp(double a , int b){
    if(b==0){
        return 1;
    }else{
        return exp(a,b-1)*a;
    }
}


int main(){

    cout << exp(3,3) << endl;
}