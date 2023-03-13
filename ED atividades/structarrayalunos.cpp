#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

struct Aluno{
    int matricula;
    string nome;
    double media;
};



void cria_Aluno(Aluno a[] , int tam){
   
    for(int i=0;i<tam;i++){
        
        cin >> a[i].matricula;
        cin.ignore(numeric_limits<streamsize>:: max(), '\n');
        getline(cin,a[i].nome);
        cin >> a[i].media;
        
    }
   
}

void print_aluno(int m , Aluno a[],int tam){
     bool encontrou = false;
    for(int i=0;i<tam;i++){
        if(m == a[i].matricula){
           encontrou = true;
            cout << a[i].nome << endl;
            cout << fixed << setprecision(1) << a[i].media;
            break;
        }else{
            encontrou = false;
        }
    }
    if(encontrou == false){
        cout << "NAO ENCONTRADA";
    }
}


int main(){
    int n;
    int busca;
    Aluno v[50];

    cin >> n;
    
    cria_Aluno(v,n);
    cin.ignore(numeric_limits<streamsize>:: max(), '\n');   
    cin >> busca;

    print_aluno(busca,v,n);


    

  



}