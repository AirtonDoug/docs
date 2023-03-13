#include <iostream>
#include <string>
using namespace std;

// recebe uma string e diz se é um palindromo
bool palindromo(string str,int ini,int fim){
    if(ini < fim){
        if(str[ini] == str[fim])
            return palindromo(str,ini+1,fim-1);
        else
            return false;
        
    }
    else return true;
    

int main(){
    string palavra = "sopapos";

    cout << boolalpha << palindromo(palavra,0,palavra.size()-1) << endl;






}



}