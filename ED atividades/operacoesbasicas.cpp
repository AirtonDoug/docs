#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void printvet(vector<int> v,int n){
  if(n<1){
    return;
  }else{
   
    printvet(v,n-1);
    cout << v[n-1] << ' ';
  }
  
}
void rvet(vector<int> v,int n){
   if(n<1){
    return;
  }else{
   cout << v[n-1] << ' ';
    rvet(v,n-1);
    
  }

}

 void invert(vector<int> &v,int ini,int fim){
    if(ini<fim){
      int aux=0;
      aux=v[ini];
      v[ini]=v[fim];
      v[fim]=aux;
      invert(v,ini+1,fim-1);
    }

    }



int sum(vector <int> v,int n){
  if(n<=0){
    return 0;
  }else{
   return (sum(v,n-1)+ v[n-1]);

  }

}
int mult(vector <int> v,int n){
  if(n<=0){
    return 1;
  }else{
   return (mult(v,n-1)* v[n-1]);

  }

}
int min(vector <int> v, int n){
    if(n==1){
        return v[n-1];
    }
    else{
        int minimo = min(v,n-1);

        if (minimo < v[n-1])
            return minimo;
        else
            return v[n-1];    

    }
}



int main(){
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> vet;
    int value;
    while(ss >> value){
        vet.push_back(value);
    }
    int n = vet.size();
    cout << "vet : " << "[ ";
    printvet(vet,n);
    cout << "]" << endl;
    cout << "rvet: " << "[ ";
    rvet(vet,n);
    cout << "]" << endl;
    cout <<  "sum : " << sum(vet,n) << endl;
    cout << "mult: " << mult(vet,n) << endl;
    cout << "min : "  << min(vet,n) << endl;
    cout << "inv : " << "[ ";
    invert(vet,0,n-1);
    printvet(vet,n);
    cout << "]" << endl;
    


}