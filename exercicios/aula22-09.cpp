#include <iostream>
using namespace std;

class Pessoa{
    private:
        int idade{34};
        string nome{"ana"};
    public:
        //construtor default
        Pessoa(){}
        //construtor com argumentos
        Pessoa(int i,string n){
            idade=i;
            nome=n;
        }
        //construtor de cópia = copy contructor
        Pessoa(const Pessoa& pessoa){
            idade = pessoa.idade;
            nome = pessoa.nome;   
        }
        void print(){
            cout << idade << ", " << nome << endl;
        }
        //Destrutor
        ~Pessoa(){
            cout << "pessoa morreu" << endl;
        }
        //função que muda o nome
       void setNome(string nome){
            this->nome = nome;
        }  
        void setIdade(int idade){
            this->idade = idade;
        }
        // retorna o nome dapessoa
      string  getNome(){
        return nome;
      }    
};

int main(){
    Pessoa p(25,"marcos");
    Pessoa q(p);
    Pessoa r;
    Pessoa *ptr = new Pessoa(23,"paula");

    p.print();
    q.print();
    ptr->print();
    delete ptr;
}