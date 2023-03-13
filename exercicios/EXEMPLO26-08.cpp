#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){

    stringstream ss;
    string line;

    cout << "Digite numeros separados por espaço: ";

    getline(cin,line);

    ss << line

    double numero;
    cout << " Os numeros com valor dobrado são:\n";
    while(ss >> numero){
        cout << numero *  2 << " ";
    }


}