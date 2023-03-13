#include <iostream>
using namespace std;

class Pessoa {
private:
    int idade {34};
    string nome {"ana"};

public:
    // construtor default 
    Pessoa() {
        std::cout << "pessoa criada no construtor default" << endl;
    }
    // construtor com dois argumentos
    Pessoa(int i, string n) {
        std::cout << "pessoa criada no construtor com dois argumentos" << endl;
        idade = i;
        nome = n;
    }
    // construtor de cópia = copy constructor
    Pessoa(const Pessoa& pessoa) {
        std::cout << "pessoa criada no construtor de cópia" << endl;
        idade = pessoa.idade;
        nome = pessoa.nome;
    }
    void print() {
        std::cout << idade << ", " << nome << std::endl;
    }
    // Destrutor
    ~Pessoa() {
        std::cout << "pessoa morreu" << std::endl;
    }
    // função que muda o nome da pessoa
    void setNome(string nome) {
        this->nome = nome;
    }
    // função que muda a idade da pessoa
    void setIdade(int idade) {
        this->idade = idade;
    }
    // retorna o nome da pessoa
    string getNome() {
        return nome;
    }
    // retorna a idade da pessoa
    int getIdade() {
        return idade;
    }
};

int main() {
    Pessoa pessoa;
    cout << "Digite o nome do cliente: ";
    string nome;
    getline(cin, nome);
    pessoa.setNome(nome);
    cout << "Digite a idade do cliente: ";
    int idade;
    cin >> idade;
    pessoa.setIdade(idade);
    pessoa.print();
}