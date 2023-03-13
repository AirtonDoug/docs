#include <iostream>
#include <limits>
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

void imprimir_aluno(Aluno *a){
    cout << a->nome;
    if(a->nota >= 7){
        cout << " aprovado(a) em ";
    }else{
        cout << " reprovado(a) em ";
    }
    cout << a->disciplina;

}

int main(){
    Aluno a1;

    cria_aluno(&a1);
    imprimir_aluno(&a1);

}