#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

struct Aluno{
    string nome;
    int matricula;
    string disciplina;
    double nota;


};

void cria_aluno(Aluno *a){
    cin >> a->nome;
    cin.ignore(numeric_limits<streamsize>:: max(), '\n');
    cin >> a->matricula;
    cin.ignore(numeric_limits<streamsize>:: max(), '\n');
    cin >> a->disciplina;
    cin.ignore(numeric_limits<streamsize>:: max(), '\n');
    cin >> a->nota;

}

void compara_nota(Aluno *a1,Aluno *a2){
    if(a1->nota > a2->nota){
        cout << a1->nome << " , ";
        cout << fixed << setprecision(1) << a1->nota;
    }else if(a1->nota < a2->nota){
        cout << a2->nome << " , ";
        cout << fixed << setprecision(1) << a2->nota;
    }else{
        cout << a1->nome << " e " << a2->nome << " , " ;
        cout << fixed << setprecision(1) << a1->nota;
    }

}

int main(){
    Aluno a1,a2;

    cria_aluno(&a1);
    cria_aluno(&a2);

    compara_nota(&a1,&a2);
    

}