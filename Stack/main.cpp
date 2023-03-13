#include <iostream>
#include "Stack.h"
#include <string>
#include <sstream>
using namespace std;

//recebe uma string e retorna uma string
// com as palavras invertidas
 string inverter_palavra(string str){
    Stack<char> pilha;
    string word;
    for(int i = 0 ;i <= (int)str.size();i++){
        if(str[i] != ' ' && str[i] !='\0'){//li uma letra
            pilha.push(str[i]);
        }else{
            while(!pilha.empty()){
                word += pilha.top();
                pilha.pop();
            }
            word += (str[i] == '\0') ? "" : " ";
        }
    }

 }


int main(){    
    string line {"AMU MEGASNEM ATRECES"};

    cout << inverter_palavra(line);
  
}