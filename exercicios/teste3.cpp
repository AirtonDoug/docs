#include <iostream>
#include <vector>
using namespace std;
void print(const vector<int>& vec){
for(auto it = vec.begin(); it != vec.end();it++){
        cout << *it << " ";
    }
}
// apaga a primeira ocorrencia do valor
void erase_value(vector<int>&vec,int value){
    for(auto it = vec.begin();it != vec.end();it++){
        if(*it== value){
            vec.erase(it); // retorna endereço da posição apagada
            break;
        }
    }
}
//apaga todas as ocorrencias do valor
void erase_allvalue(vector<int>&vec,int value){
    for(auto it = vec.begin(); it != vec.end(); ){
        if(*it==value){
            vec.erase(it);
        }else{
            it++;
        }
    }
}


int main(){
    vector<int> vec{5,5,5,5,5,5,5,1,2,3,4,5,5,6,7,5,5,5,5,5};
    
    print(vec);
    auto it = vec.begin();
    vec.insert(it,7777);
    print(vec);

    //erase_value(vec,5);
    erase_allvalue(vec,5);
    print(vec);
    
}