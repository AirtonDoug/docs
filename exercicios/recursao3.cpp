#include <iostream> 
using namespace std;

int triangulos(int h){
    if(h==0 || h==1){
        return h;
    }
    else{
        return h + 2*triangulos(h-1) - triangulos(h-2);
    }



}

int main(){
    int h = 3;

    cout << "numero de triangulos numa grade de altura " << h << ": "
         << triangulos(h) << endl;




}