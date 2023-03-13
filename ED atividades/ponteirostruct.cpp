#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

struct Empregado {
    short id;
    int idade;
    double salario;
};
void cria_empregado(Empregado *p){
    
    cout << "Digite o id ";
    cin >> p->id;
    cout << "Digite a idade ";
    cin >> p->idade;
    cout << "Digite o salario ";
    cin >> p->salario;
}

void print_Empregado(Empregado *p){
     cout << "ID: "    << p->id
         << "\nIdade " << p->idade
         << "\nSalario " << p->salario;

}

int main(){
    Empregado emp1;
    cria_empregado(&emp1);
    print_Empregado(&emp1);

}