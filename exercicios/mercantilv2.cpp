#include <iostream>
using namespace std;

int main(){
    float A;
    char op;
    float product;

    cin >> A;
    cin >> op;
    cin >> product;


    switch (op)
    {
    case 'm'/* constant-expression */:
        if(A > product){
            cout << "segundo" << endl;
        }else{
            cout << "primeiro" << endl;
        }    
        break;
    case 'M':
        if(A < product){
            cout << "segundo" << endl;
        }else{
            cout << "primeiro" << endl;
        }
        break;
    default:
        cout << "op invalida" << endl;
        break;
    }


}