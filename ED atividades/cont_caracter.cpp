#include <iostream>
#include <string>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, int n, char c)
{
    
    // fazer
    if(n==0){
        return 0;
    }else{
        if(str[n-1] == c){
           return contaCaracteres(str,n-1,c) + 1;
        }else{
        return contaCaracteres(str,n-1,c);
        }
    }

}

int main() 
{
    string s;
    char c;
    
    getline(cin,s);
    cin >> c;

    int tam = (int)s.size();
    //cout << tam;
    cout << contaCaracteres(s,tam,c) << endl;
    
}