#include <iostream>
#include <cmath>
using namespace std;

int main(){
    char op;
    float num;
    cin >> op >> num;

    switch (op)
    {
    case 'c'/* constant-expression */:
        cout << ceil(num) << endl;
        break;
    case 'f':
        cout << floor(num) << endl;
        break;
    case 'r':
        cout << round(num) << endl;
        break;
    default:
        cout << "invalid option" << endl;
        break;
    }
    
    
    
    
  

 

   

    



}