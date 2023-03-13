#include <iostream>
#include <cstring>
#include <limits>
using namespace std;


int main(){
    char palavra[10];
    char endereco[20];
    cout << "DIgite uma palavra\n";

    cin.get(palavra,10);
    
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "digite endereco\n";
    cin.get(endereco,20);

        cout << palavra << " "<< endereco << endl;
        cout << strlen(palavra) << endl;
        
    


}