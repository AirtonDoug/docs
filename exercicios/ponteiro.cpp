#include <iostream>
using namespace std;

int main(){
    int x = 77;
    int *ptrInt = &x;

    *ptrInt = 88;
   cout << *ptrInt << endl;
   cout << ptrInt << endl;


}