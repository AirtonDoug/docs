#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot){
    if(nrot > 0){
            int aux = vet.back();
            vet.erase(vet.end()-1);
            vet.insert(vet.begin(),aux);
            right_rotation(vet,nrot-1); 
            }
}

void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main(){
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);
}

