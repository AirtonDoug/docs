#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef struct coordenadas{
    int x;
    int y;
}coordendas;

void show(string *mat, int nl) {
    for(int l = 0; l < nl; l++)
        cout << mat[l] << endl;
}

vector<coordendas> getVizinhos(string *mat,int i, int j, int nlin, int ncol){
    vector<coordenadas> vizinhos;
    coordenadas a;
    if(i==0 && j == ncol-1){
        a.y = i+1;
        a.x = j;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
        a.y = i;
        a.x = j-1;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
    }
    else if(i==0 && j < ncol-1 && j!=0){
        a.y = i+1;
        a.x = j;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
        a.y = i;
        a.x = j-1;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
        a.y = i;
        a.x = j+1;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
    }
    else if(i>0 && j == ncol-1 && i < nlin-1){
        a.y = i-1;
        a.x = j;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
        a.y = i-1;
        a.x = j;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
        a.y = i;
        a.x = j-1;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
    }
     else if(i == nlin-1 && j == ncol-1){
        a.y = i-1;
        a.x = j;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
        a.y = i;
        a.x = j-1;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
    }
     else if(i==0 && j == 0){
        a.y = i+1;
        a.x = j;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
        a.y = i;
        a.x = j+1;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
    }
      else if(i== nlin - 1 && j > 0 && j < ncol - 1){
        a.y = i-1;
        a.x = j;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
        a.y = i;
        a.x = j+1;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
        a.y = i;
        a.x = j-1;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
    }
       else if(j == 0 && i < ncol - 1 && i != 0){
        a.y = i-1;
        a.x = j;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
        a.y = i+1;
        a.x = j;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
        a.y = i;
        a.x = j+1;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
        
    }
    else if(j == 0 && i == ncol - 1){
        a.y = i-1;
        a.x = j;
        if(mat[a.y][a.x]==' ')
            vizinhos.push_back(a);
        a.y = i;
        a.x = j+1;
        if(mat[a.y][a.x]==' ') 
            vizinhos.push_back(a);
        
    }
    else{
        a.y = i+1;
        a.x = j;
        if(mat[a.y][a.x]=='#')
            vizinhos.push_back(a);
        a.y = i-1;
        a.x = j;
        if(mat[a.y][a.x]=='#')
            vizinhos.push_back(a);
        a.y = i;
        a.x = j+1;
        if(mat[a.y][a.x]=='#')
            vizinhos.push_back(a);
        a.y = i;
        a.x = j-1;
        if(mat[a.y][a.x]=='#')
            vizinhos.push_back(a);

    }

    return vizinhos;

}


void achar_caminho(string *mat,int i, int j,int nl,int nc){
    
    
}



int main(){
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    string* mat = new string[nl];
    for(int l = 0; l < nl; l++){
        string line;
        cin >> line;
        mat[l] = line;
    }

   
    
   
}