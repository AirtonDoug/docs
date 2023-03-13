#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> num ={1,2,3,4,5};

    num.push_back(6);
    num.push_back(7);
    for(int i: num){
        cout << i << ' ';
    }
    cout << '\n' << "numero na posicao 0: " ;
    cout << num.at(0);

    num.at(1)=15;

    cout <<  '\n' << "numero na posicao 1: " << endl;
    cout << num[1] << endl;

    num.pop_back();
    for(int i: num){
        cout << i << ' ';
    }
}