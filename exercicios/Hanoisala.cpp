#include <iostream>
using namespace std;

void hanoi(int n, char A, char B , char C){
    if(n==0){
        return;
    }
    if(n==1){
        cout << "Move " << A << " para " << C << endl;
    }else{
        hanoi(n-1,A,C,B);
        cout << "Move " << A << " para " << C << endl;
        hanoi(n-1,B,A,C);
    }
}


int main(){
    int n;
    char a='A',b='B',c='C';

    cin >> n;

    hanoi(n,a,b,c);
    

}