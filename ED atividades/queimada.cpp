#include <iostream>
#include <string>
using namespace std;


void show(string *mat, int nl) {
    for(int l = 0; l < nl; l++)
        cout << mat[l] << "\n";
}

void tocar_fogo(int nl, int nc, string *mat, int l, int c){
    //TODO faca seu codigo aqui
    
    if((l > nl-1 || c > nc-1) || (l<0 || c < 0)||(mat[l][c] != '#')){
        return;
    }
    else{
    mat[l][c]='o';
    tocar_fogo(nl,nc,mat,l-1,c);
    tocar_fogo(nl,nc,mat,l+1,c);
    tocar_fogo(nl,nc,mat,l,c+1);
    tocar_fogo(nl,nc,mat,l,c-1);
    }


}

int main(){
    int nl = 0, nc = 0, lfire = 0, cfire = 0;
    cin >> nl >> nc >> lfire >> cfire;
    string* mat = new string[nl];
    for(int l = 0; l < nl; l++){
        string line;
        cin >> line;
        mat[l] = line;
    }
    tocar_fogo(nl, nc, mat, lfire, cfire);
    show(mat, nl);
    delete[] mat;
}