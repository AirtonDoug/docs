#include <iostream>
#include <vector>
using namespace std;




vector <int> filaIngresso(vector <int> vec,vector <int> out){

    for(int i=0; i<(int)out.size();i++ ){
        for(int j=0;j<(int)vec.size();j++){
            if(out[i] == vec[j]){
                vec.erase(vec.begin()+j);
            }
        }
    }
    return vec;
}



int main(){
    vector <int> fila;
    vector <int> saiu;
    vector <int> res;
    int n;
    int id;
    int qnt;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> id;
        fila.push_back(id);
    }

    cin >> qnt;

     for(int i=0;i<qnt;i++){
        cin >> id;
        saiu.push_back(id);
    }

    res = filaIngresso(fila,saiu);

    for(int i=0;i < (int)res.size();i++){
        cout << res[i] << " ";
    }
    cout << '\n';


}