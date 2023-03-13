#include <iostream>

using namespace std;

bool verOrdemvetor(int v[]){
    for(int i=1;i<7;i++){
        if(v[i]<v[i-1])
            return false;
               
    }
        return true;
}


int main(){
    int v[7]{1,2,4,5,550,8,10};

    cout << verOrdemvetor(v) << endl;
    


}