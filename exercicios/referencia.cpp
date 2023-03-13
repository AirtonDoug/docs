#include <iostream>
using namespace std;

int soma(const int& x, const int&y){
    return x+y;
}

int main(){
    
   const int E { 22 };
   int x = 87;

   const int& ref = x; 
    
    cout << soma(34,12) << endl;

}