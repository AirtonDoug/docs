#include <iostream>
using namespace std;

struct Empregado {
    short id;
    int idade;
    double salario;
};
Empregado cria_empregado(){
    Empregado p;
    cout << "Digite o id ";
    cin >> p.id;
    cout << "Digite a idade ";
    cin >> p.idade;
    cout << "Digite o salario ";
    cin >> p.salario;
    return p;
}

void print_Empregado(Empregado p){
     cout << "ID: "    << p.id
         << "\nIdade" << p.idade
         << "\nSalario" << p.salario;

}

int main(){
    Empregado emp1,emp2;
    //emp1 = cria_empregado();
    //print_Empregado(emp1);

    emp1.id = 23;
    emp1.idade = 56;
    emp1.salario = 786.98;

}